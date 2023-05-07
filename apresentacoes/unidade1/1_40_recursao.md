---
marp: true
theme: gaia
paginate: true

---

<!-- _class: lead -->

# Recursão #

Professor: Carlos Alvaro Quintella

---

## Calculo de Fatorial ##

Fatorial é uma operação matemática aplicada a um número inteiro não negativo, representada pelo símbolo "!" (ponto de exclamação). O fatorial de um número n é o produto de todos os números inteiros positivos de 1 até n. Em outras palavras, é a multiplicação de todos os números inteiros entre 1 e n, inclusive.

---

A definição formal do fatorial é:

````math
n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
````

Além disso, por convenção, o fatorial de 0 é definido como 1:

````math
0! = 1
````

O conceito de fatorial é frequentemente usado em combinações e permutações na teoria da probabilidade e estatística, computação, bem como em análise combinatória e na solução de equações diferenciais.

---

Faça um programa que calcule o fatorial de um número digitado pelo usuário...

---

# Algoritmo para calcular Fatorial ##

````c
#include <stdio.h>

unsigned long long fatorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;
    printf("Digite um número para calcular seu fatorial: ");
    scanf("%d", &numero);

    unsigned long long resultado = fatorial(numero);
    printf("Fatorial de %d é %llu\n", numero, resultado);

    return 0;
}
````

---

## Sequência de Fibonacci ##

A sequência de Fibonacci é uma sequência numérica em que cada número é a soma dos dois números que o precedem. A sequência geralmente começa com os números 0 e 1 e continua indefinidamente. A sequência de Fibonacci pode ser definida matematicamente pela seguinte fórmula de recorrência:

F(n) = F(n-1) + F(n-2)

com as condições iniciais:

F(0) = 0
F(1) = 1

Os primeiros números da sequência de Fibonacci são:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

---

## Conceito de Recursão ##

A recursão ocorre quando uma função chama a si mesma diretamente ou indiretamente. Uma função recursiva geralmente possui duas partes principais: o caso base e o caso recursivo. O caso base define as condições em que a função retorna um valor diretamente, sem fazer chamadas recursivas. O caso recursivo define como a função chama a si mesma, reduzindo o problema a um subproblema menor.

* Recursividade é extremamente útil em diversas áreas da computação incluíndo para inteligência artificial.

---

## Exemplo: Fatorial ##

* Quanto é fatorial de 2?
* Quanto é o fatorial de 4?
* Quanto é o fatorail de 10?
* Quanto é o fatorial de 11?

---

````c
int fatorial(int n) {
    if (n == 0) {
        return 1; // caso base
    }
    return n * fatorial(n - 1); // caso recursivo
}

````

---

### Caso Base ###

O caso base é a condição que define quando a função recursiva deve parar de chamar a si mesma e retornar um valor diretamente. É essencial para evitar loops infinitos de chamadas recursivas e garantir que a função eventualmente termine.

* Para o cálculo do fatorial, o caso base ocorre quando n = 0. Neste caso, a função retorna 1, pois o fatorial de 0 é definido como 1.

---

O caso recursivo define como a função chama a si mesma, geralmente com o objetivo de reduzir o problema a um subproblema menor. A solução do subproblema menor é usada para construir a solução do problema original.

* A sequência de Fibonacci começa com os números 0 e 1 e, em seguida, cada número subsequente é a soma dos dois números anteriores.

* Para calcular o enésimo número da sequência de Fibonacci, o caso recursivo envolve a soma de duas chamadas recursivas, cada uma **reduzindo o problema em um subproblema menor**.

---

## Sequencia de Fibonacci ##

````c

int fibonacci(int n) {
    if (n == 0) {
        return 0; // caso base
    }
    if (n == 1) {
        return 1; // caso base
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // caso recursivo
}
````

---

## Programacao Dinâmica ##

Programação dinâmica é uma técnica de otimização usada em ciência da computação e matemática para resolver problemas que apresentam uma estrutura de sobreposição de subproblemas e subestrutura ótima. Ela é particularmente útil para resolver problemas de otimização e problemas que podem ser divididos em subproblemas menores e independentes.

---

### Características dos Problemas para aplicação ###

A programação dinâmica pode ser aplicada quando um problema possui as seguintes características:

* Sobreposição de subproblemas: O problema pode ser dividido em subproblemas menores e a solução do problema original pode ser obtida a partir das soluções desses subproblemas. Além disso, esses subproblemas menores são resolvidos várias vezes, o que leva a cálculos redundantes.

* Subestrutura ótima: A solução ótima do problema original pode ser construída a partir das soluções ótimas dos subproblemas.

---

### Duas abordagens ###

A programação dinâmica utiliza duas abordagens principais para resolver problemas:

**Abordagem de memoização** (top-down): Nesta abordagem, a solução do problema é construída de cima para baixo, começando com o problema original e dividindo-o em subproblemas menores. Os resultados dos subproblemas são armazenados em uma tabela (ou estrutura de dados similar) para evitar cálculos redundantes. Quando um subproblema é resolvido pela primeira vez, o resultado é armazenado na tabela. Se o mesmo subproblema for encontrado novamente, o resultado armazenado é utilizado em vez de resolver o subproblema novamente.

---

**Abordagem de programação dinâmica bottom-up (também chamada de abordagem tabulação)**: Nesta abordagem, a solução do problema é construída de baixo para cima, começando com os subproblemas menores e combinando suas soluções para resolver problemas maiores. A tabela é preenchida em uma ordem específica, de forma que os resultados dos subproblemas estejam disponíveis antes de serem necessários para resolver problemas maiores. Isso elimina a necessidade de chamadas recursivas e reduz a redundância de cálculos.

---

### Comparação entre as abordagens ###

Ambas as abordagens, memoização (top-down) e tabulação (bottom-up), têm suas vantagens e desvantagens. A abordagem de memoização tende a ser mais intuitiva, pois segue a estrutura natural do problema e pode ser facilmente implementada adicionando uma estrutura de armazenamento (como um dicionário ou matriz) a um algoritmo recursivo existente. No entanto, a memoização ainda usa a recursão e, portanto, pode levar a um maior consumo de memória devido à pilha de chamadas recursivas.

---

A abordagem de tabulação é geralmente mais eficiente em termos de tempo e espaço, pois elimina a necessidade de chamadas recursivas e calcula apenas os subproblemas que são estritamente necessários para resolver o problema original. No entanto, a tabulação pode ser menos intuitiva e requer a identificação de uma ordem específica para resolver os subproblemas.

---

Ambas as abordagens têm como objetivo reduzir a redundância de cálculos e melhorar a eficiência do algoritmo, aproveitando as características de sobreposição de subproblemas e subestrutura ótima do problema em questão. Ao escolher entre as abordagens de programação dinâmica, é importante considerar as especificidades do problema e as necessidades de tempo e espaço do algoritmo.

---

## Conclusão ##

O uso de recursão torna a solução mais simples e elegante, embora em geral ocasione em mais espaço de memória.
