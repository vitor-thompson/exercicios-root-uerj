# Exercício 3: Histogramas 1D e Estatísticas Avançadas (`TH1F` e `gStyle`)

## Descrição do Problema
O objetivo deste exercício é gerar uma amostragem estatística pseudoaleatória e exibi-la através de um histograma uni-dimensional no CERN ROOT, configurando a caixa de estatísticas (*Stats Box*) para exibir todas as métricas detalhadas do conjunto de dados:

1. **Histograma:** Criar um histograma de 50 bins no intervalo de $0$ a $10$.
2. **Amostragem:** Preencher o histograma com 10.000 números aleatórios seguindo uma distribuição Gaussiana (Normal) com média $\mu = 5$ e desvio padrão $\sigma = 2$.
3. **Caixa de Estatísticas (`THistPainter`):** Configurar a exibição de:
   * Número de entradas (*Entries*)
   * Média (*Mean*)
   * RMS / Desvio Padrão (*Std Dev*)
   * Integral do histograma (*Integral*)
   * Transbordamentos inferiores (*Underflows*)
   * Transbordamentos superiores (*Overflows*)
   * Assimetria (*Skewness*)
   * Curtose (*Kurtosis*)

---

## Explicação Detalhada do Código (`exercicio3.C`)

O código em C++ utiliza o gerador de números aleatórios `TRandom3` e configura o estilo global de exibição através do `gStyle`:

1. **Configuração Global de Estatísticas (`gStyle->SetOptStat`):**
   * A função `gStyle->SetOptStat(111111111)` utiliza uma máscara de dígitos binários (`kKsiourmne`) para ativar a exibição de todas as informações estatísticas no painel lateral do gráfico:
     * `k` (Kurtosis)
     * `s` (Skewness)
     * `i` (Integral)
     * `o` (Overflows)
     * `u` (Underflows)
     * `r` (RMS / Std Dev)
     * `m` (Mean)
     * `n` (Number of Entries)
     * `e` (Errors)

2. **Geração de Dados Aleatórios (`TRandom3`):**
   * Instancia-se o gerador `TRandom3` com uma semente fixa (`42`) para garantir a reprodutibilidade exata dos resultados.
   * O método `rand.Gaus(5.0, 2.0)` gera valores distribuídos gaussianamente em torno de $\mu = 5.0$ e $\sigma = 2.0$.

3. **Preenchimento e Renderização (`TH1F`):**
   * O histograma é configurado com 50 divisões (*bins*) cobrindo o intervalo $[0, 10]$.
   * Os valores são inseridos via `h1->Fill(...)`. Os eventos que caem abaixo de $0$ ou acima de $10$ são contabilizados automaticamente como *Underflows* e *Overflows*, respectivamente.

4. **Exportação dos Resultados:**
   * O gráfico gerado é salvo automaticamente em dois formatos: **PNG** (`exercicio3.png`) e **PDF** (`exercicio3.pdf`).

---

## Arquivos Requeridos no Repositório

Para o correto funcionamento desta etapa, a pasta `exercicio3/` deve conter:
* `exercicio3.C` (Código fonte em C++)
