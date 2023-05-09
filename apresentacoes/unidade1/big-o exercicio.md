---
marp: true
theme: gaia
paginate: true
backgroundColor: #fff
---

<!-- _class: lead -->

# Exame de Ciências da Computação #

Tópico: Notação Big-O (Análise de Complexidade Algoritmos)

---

Questão 1: Qual das seguintes notações descreve o melhor caso para um algoritmo de busca binária?

```pseudocode
**Algoritmo Busca Binária** (array, valor_alvo)

    Inicializar variáveis:
        inicio = 0
        fim = tamanho do array - 1
    Enquanto inicio <= fim:
    a. Calcular meio = (inicio + fim) / 2, arredondando para baixo
    b. Se array[meio] == valor_alvo, retornar meio
    c. Se array[meio] < valor_alvo, atualizar inicio para meio + 1
    d. Se array[meio] > valor_alvo, atualizar fim para meio - 1
```

a) O(1)
b) O(log n)
c) O(n)
d) O(n^2)

---

O algoritmo de busca binária possui as seguintes classificações de complexidade:

Complexidade de tempo:

    Caso médio e pior caso: O(log n)
    Melhor caso: O(1)

Complexidade de espaço:

    O(1) (complexidade de espaço constante, pois usa apenas um espaço adicional para armazenar variáveis)

Classificação Omega (Ω):
A classificação Omega representa o melhor caso de desempenho para um algoritmo. No caso da busca binária, a classificação Omega é Ω(1), pois no melhor caso, o valor alvo é encontrado na primeira tentativa, ou seja, quando o valor está na posição do meio do array.

Em resumo, a busca binária é um algoritmo eficiente para encontrar elementos em arrays ordenados, pois sua complexidade de tempo é logarítmica e sua complexidade de espaço é constante.

---

Questão 2: Dado um algoritmo com complexidade O(n^2), qual das opções abaixo descreve corretamente o comportamento do tempo de execução do algoritmo em relação ao tamanho da entrada (n)?
a) O tempo de execução aumenta linearmente com n.
b) O tempo de execução aumenta exponencialmente com n.
c) O tempo de execução aumenta quadraticamente com n.
d) O tempo de execução aumenta logaritmicamente com n.

---

Questão 3: Dado um algoritmo com complexidade O(log n), qual das opções abaixo descreve corretamente o comportamento do tempo de execução do algoritmo em relação ao tamanho da entrada (n)?
a) O tempo de execução aumenta linearmente com n.
b) O tempo de execução aumenta exponencialmente com n.
c) O tempo de execução aumenta quadraticamente com n.
d) O tempo de execução aumenta logaritmicamente com n.
