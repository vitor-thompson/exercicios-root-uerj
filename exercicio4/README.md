# Exercício 4: Análise de Ntuplas com `TTree` e Filtros Encadeados (`TCut`)

## Descrição do Problema
O objetivo deste exercício é analisar uma estrutura de dados (*Tree*) contida no arquivo `tree.root` para projetar a distribuição do momento total $p$ das partículas associadas a eventos cuja energia do feixe (*beam energy*) esteja desviada da sua média em mais de $0.2$:

$$|ebeam - \mu_{ebeam}| > 0.2$$

A seleção de eventos deve ser implementada obrigatoriamente utilizando objetos da classe `TCut`. O gráfico final deve ser projetado em um histograma, desenhado e exportado em arquivo de imagem e em arquivo `.root`.

---

## Explicação Detalhada do Código (`exercicio4.C`)

O código realiza o processamento dos eventos da árvore `tree1` e aplica a álgebra de cortes lógica em C++:

1. **Cálculo Dinâmico da Média (`ebeam_mean`):**
   * Cria-se um histograma temporário (`h_temp`) para projetar a variável `ebeam` sem desenhar na tela (`opção "goff"`).
   * A média $\mu_{ebeam}$ é calculada dinamicamente via `h_temp->GetMean()`.

2. **Formatação de Condições com `TCut`:**
   * Para evitar erros do interpretador C++ (Cling) com alocação dinâmica, a string de corte é formatada previamente usando `TString` e `Form("abs(ebeam - %f) > 0.2", ebeam_mean)`.
   * São instanciados os ponteiros para os cortes adicionais de plano de momento no feixe:
     * `px_plane = new TCut("px / log(px*2 + py**2) > 0.10")`
     * `py_plane = new TCut("py / log(px*2 + py**2) > 0.10")`

3. **Cálculo do Momento Total $p$ e Projeção:**
   * O momento quadridimensional/tridimensional total é calculado através da norma do vetor tridimensional:
     $$p = \sqrt{p_x^2 + p_y^2 + p_z^2}$$
   * A projeção é feita diretamente da `TTree` para o histograma `h_p` aplicando a conjunção lógica dos três cortes: `cut_ebeam && *px_plane && *py_plane`.

4. **Exportação dos Resultados:**
   * O gráfico final é desenhado no `TCanvas` e exportado como imagem PNG (`exercicio4_momento.png`).
   * O histograma processado é gravado em um arquivo de dados persistente (`exercicio4_saida.root`).

---

## Arquivos Requeridos no Repositório

Para o correto funcionamento desta etapa, a pasta `exercicio4/` deve conter:
* `exercicio4.C` (Código fonte em C++)
* `tree.root` (Arquivo de dados de entrada com a `TTree tree1`)
