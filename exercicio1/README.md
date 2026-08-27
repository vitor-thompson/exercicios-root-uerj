# Exercício 1: Funções Paramétricas, Derivadas e Integrais no CERN ROOT

## Descrição do Problema
O objetivo deste exercício é criar e manipular funções matemáticas parametrizadas.

A atividade exige a plotagem da função em cor azul para diferentes conjuntos de parâmetros (p_0 e p_1), seguida pelo cálculo numérico das seguintes propriedades para p_0 = 1 e p_1 = 2:
* **a.** Valor da função em x = 1.
* **b.** Derivada da função em x = 1.
* **c.** Integral definida no intervalo entre 0 e 3.

---

## Explicação Detalhada do Código (`exercicio1.C`)

O código em C++ utiliza a classe `TF1` do ROOT para a manipulação analítica e numéricas da função:

1. **Instanciação da Função Principal (`f1`):**
   * É criada a função parametrizada com o intervalo de exibição de x in [0.01, 10.0] para evitar a divisão por zero em x = 0.
   * Os parâmetros são configurados com `SetParameters(1.0, 2.0)`, onde `[0]` representa p_0 = 1.0 e `[1]` representa p_1 = 2.0.
   * A linha é configurada para a cor azul (`kBlue`) e espessura 2.

2. **Comparação com Parâmetros Alternativos (`f2`):**
   * Instancia-se uma segunda curva com p_0 = 2.0 e p_1 = 1.0 em linha vermelha tracejada (`kRed`, `LineStyle(2)`).
   * A opção `"SAME"` no método `Draw()` permite desenhar a nova curva no mesmo Canvas sem apagar a anterior.

3. **Cálculos Numéricos:**
   * **`Eval(1.0)`**: Avalia o valor numérico exato de f(1.0).
   * **`Derivative(1.0)`**: Calcula a primeira derivada f'(1.0) usando métodos de diferenças finitas.
   * **`Integral(0.0, 3.0)`**: Executa a integração numérica de Gauss-Legendre no intervalo [0, 3].

---

## Resultados Obtidos

Ao executar o código com `root -l exercicio1.C`, a saída obtida no terminal é:

* **a. Valor da Função em x = 1:** `0.909297`
* **b. Derivada em x = 1:** `-1.32544`
* **c. Integral entre 0 e 3:** `1.60541`
* **c. Integral entre $0$ e $3$:** `1.60541`
* **b. Derivada em $x = 1$:** `-1.32544`
* **c. Integral entre $0$ e $3$:** `1.60541`
