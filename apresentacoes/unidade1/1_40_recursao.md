---
marp: true
theme: gaia
paginate: true

---

<!-- _class: lead -->

# Recursão #

Professor: Carlos Alvaro Quintella

---

## Como funciona a chamada de funções ##

Quando uma função é chamada em C, o sistema precisa armazenar informações importantes para garantir que a função seja executada e o programa continue a execução corretamente de onde parou.

---

### Armazenando informações da chamada ###

Informações que são armazenadas:

- Os parâmetros passados para a função
- O endereço de retorno, indicando onde a execução do programa deve ser retomada após a função terminar

- A posição atual do registro de ativação da função chamadora, chamada de "link dinâmico"
- Espaço de memória para as variáveis locais da função

---

### Registro de Ativação ###

Essas informações são armazenadas em um registro de ativação, cujo o endereço é criado no topo da pilha de execução quando a função é chamada.

- O registro de ativação é alocado dinamicamente e armazena todas as informações necessárias para executar a função corretamente.

---

```c
struct activation_record {
  // parâmetros da função
  int param1;
  double param2;
  
  // variáveis locais da função
  int local1;
  char local2[10];
  
  // endereço de retorno
  void *return_address;
  
  // dynamic link
  struct activation_record *dynamic_link;
};
```

_Nota_: O formato do registro de ativação depende da verdade da plataforma.

---

Quando a função termina, a pilha é "desempilhada" e o registro de ativação é desalocado. O endereço de retorno é então usado para retomar a execução do programa na posição correta.

---

Em funções recursivas, múltiplos registros de ativação são criados na pilha de execução, cada um correspondente a uma chamada da função. À medida que as chamadas recursivas são resolvidas, a pilha é "desempilhada" e os registros de ativação são desalocados na ordem inversa em que foram criados.

---

## Definições recursivas e conjuntos infinitos ##

- Uma regra básica para definir novos objetos é que a definição deve conter apenas termos já definidos ou óbvios
- Uma definição que contém o próprio objeto é um círculo vicioso e uma violação dessa regra
- No entanto, existem conceitos de programação que se definem a si mesmos sem violar a regra

---

- Essas definições são chamadas de definições recursivas e são usadas principalmente para definir conjuntos infinitos

- Uma definição recursiva tem duas partes:

1) **Caso base**: lista os elementos básicos que são os blocos de construção de todos os outros elementos do conjunto
2) **Regras**: permitem a construção de novos objetos a partir de elementos básicos ou objetos já construídos

---

_Nota_: O caso base é o ponto em que a função recursiva para de chamar a si mesma e retorna um valor para a chamada anterior. Na maioria dos casos, o caso base é uma condição simples que pode ser verificada em cada chamada recursiva. Quando essa condição é satisfeita, a função recursiva retorna um valor sem chamar a si mesma novamente.

---

- Essas regras são aplicadas repetidamente para gerar novos objetos

- Um exemplo de definição recursiva é a construção do conjunto de números naturais:

```math
    0 ∈ N;
    se n ∈ N, então (n + 1) ∈ N;
    não há outros objetos no conjunto N.
```

- Nesse caso, dar uma lista completa de elementos é impossível para conjuntos infinitos ou grandes, logo, definições recursivas são uma maneira eficiente de definir esses conjuntos.

<!--
Uma das regras básicas para definir novos objetos ou conceitos é que a definição deve conter apenas termos que já foram definidos ou que são óbvios.

Portanto, um objeto definido em termos de si mesmo seria uma violação dessa regra - um círculo vicioso. Por outro lado, existem muitos conceitos de programação que se definem a si mesmos. Como se constatou, as restrições formais impostas às definições, como existência e unicidade, são satisfeitas e não ocorre violação das regras. 

Tais definições são chamadas de definições recursivas e são usadas principalmente para definir conjuntos infinitos. Ao definir tal conjunto, dar uma lista completa de elementos é impossível e, para conjuntos finitos grandes, é ineficiente. Portanto, uma maneira mais eficiente deve ser criada para determinar se um objeto pertence a um conjunto.

Uma definição recursiva consiste em duas partes. Na primeira parte, chamada de caso base, os elementos básicos que são os blocos de construção de todos os outros elementos do conjunto são listados. Na segunda parte, são dadas regras que permitem a construção de novos objetos a partir de elementos básicos ou objetos que já foram construídos. Essas regras são aplicadas repetidamente para gerar novos objetos. Por exemplo, para construir o conjunto de números naturais, um elemento básico, 0, é escolhido e a operação de incrementar por 1 é dada como:

    0 ∈ N;
    se n ∈ N, então (n + 1) ∈ N;
    não há outros objetos no conjunto N.

- Adam Drozdek
-->

---

## Título: Fatorial e definições recursivas ##

- A habilidade de decompor um problema em subproblemas mais simples do mesmo tipo às vezes é uma verdadeira benção.
- Definições recursivas são frequentemente usadas para definir funções e sequências de números.

---

- O conceito de fatorial é frequentemente usado em combinações e permutações na teoria da probabilidade e estatística, computação, bem como em análise combinatória e na solução de equações diferenciais

- A função fatorial é um exemplo comum de uma definição recursiva:

- O fatorial de um número n é o produto de todos os números inteiros positivos de 1 até _n_.
- A definição formal do fatorial é:

```math
 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
 ```

- Ainda, por convenção, o fatorial de 0 é definido como 1: 0! = 1.

---

## Cálculo de fatorial usando definição recursiva #

A definição recursiva do fatorial é:

- Caso base: 0! = 1
- Caso recursivo: n! = n * (n - 1)!

A definição recursiva pode ser usada para calcular o fatorial de números grandes de maneira eficiente, por exemplo:

```math
10! = 10 x 9! = 10 x 9 x 8! = 10 x 9 x 8 x 7! = ... = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 = 3628800

O cálculo recursivo para 5! seria: 5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 120
```

---

Caso 1: Faça um programa que calcule o fatorial de um número digitado pelo usuário ...

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
