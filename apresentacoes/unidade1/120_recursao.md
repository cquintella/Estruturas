---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Estrutura de Dados
theme: gaia
---

<!-- _class: lead -->

# Programação Dinâmica e Recursão #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![UVA 70% bg left:20%](https://uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

## Programação Dinamica ##

- Técnica de resolução de problemas computacionais.
- Dividir problemas em subproblemas menores, ou
- Resolver subproblemas uma única vez e armazenar soluções.
- Útil em problemas com sobreposição de subproblemas
- Aplicações: IA, otimização, engenharia de software, finanças
- Exemplos: caminho mais curto em grafo, sequência de Fibonacci

---

### Tipos ###

1. Programação Dinâmica Clássica:
   - Otimização de função objetivo com restrições.
   - Subproblemas resolvidos de forma recursiva.

2. Programação Dinâmica Baseada em Memória (memoização):
   - Resolver problemas de otimização.
   - Encontrar melhor sequência de decisões.
   - Utilizar tabela ou matriz para armazenar soluções de subproblemas.

---

A programação dinâmica é uma técnica de resolução de problemas computacionais que consiste em dividir um problema em subproblemas menores e resolvê-los apenas uma vez, armazenando suas soluções para evitar a repetição desnecessária do cálculo. É útil em problemas com sobreposição de subproblemas e é amplamente utilizada em áreas como inteligência artificial, otimização, engenharia de software e finanças. É aplicável a uma ampla variedade de problemas, como encontrar o caminho mais curto em um grafo ou calcular a sequência de Fibonacci.

A programação dinâmica pode ser dividida em dois tipos principais: programação dinâmica clássica e programação dinâmica baseada em memória.

- O primeiro é utilizado em problemas que precisam otimizar uma função objetivo sujeita a algumas restrições, quebrando o problema em subproblemas menores e mais simples resolvidos de forma recursiva.
- Já o segundo tipo é usado para resolver problemas de otimização, encontrando a melhor sequência de decisões a serem tomadas, utilizando uma tabela ou matriz para armazenar soluções para subproblemas que são reutilizados para encontrar a solução para o problema original.

<!-- Divisão da Programacao dinamica

A programação dinâmica pode ser dividida em dois tipos principais:

- Programação dinâmica clássica: Este tipo de programação dinâmica é aplicado em problemas onde é necessário otimizar uma função objetivo sujeita a algumas restrições. Ele quebra o problema em subproblemas menores e mais simples que são resolvidos de forma recursiva. A solução final é obtida combinando as soluções dos subproblemas. Exemplos de problemas clássicos de programação dinâmica incluem a Mochila 0/1, o Problema do Caixeiro Viajante e o Problema da Sequência Comum Mais Longa.

Programação dinâmica baseada em memória: Este tipo de programação dinâmica é usado para resolver problemas de otimização que envolvem encontrar a melhor sequência de decisões a serem tomadas. Em vez de dividir o problema em subproblemas menores, este método usa uma tabela ou matriz para armazenar soluções para subproblemas que são reutilizados para encontrar a solução para o problema original. Exemplos de problemas baseados em memória incluem a Busca em Profundidade, a Busca em Largura e o Algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo ponderado.
-->

---

A programação dinâmica requer duas principais características: sobreposição de subproblemas e a propriedade de subestrutura ótima.

- Sobreposição de subproblemas: significa que os subproblemas são reutilizados várias vezes. No DFS, cada subproblema (ou seja, o cálculo da distância a partir de um nó) é calculado apenas uma vez, então essa característica não é cumprida.

- Subestrutura ótima: significa que a solução ótima do problema pode ser construída a partir das soluções ótimas dos subproblemas.

---

## Recursão ##

uma função é dita recursiva se ela chama a si mesma em sua própria definição.

Essa técnica é útil quando um problema pode ser naturalmente dividido em vários subproblemas menores que são instâncias do mesmo tipo de problema.

---

É o caso da busca ou pesquisa binária:

```c
int binary_search(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binary_search(arr, low, mid - 1, target);

        return binary_search(arr, mid + 1, high, target);
    }

    return -1;
}
```

--

### Função ###

Para entender melhor como funciona a recursão precisamos voltar a definição de uma função.

- Uma função em C é um bloco de código que possui um tipo de retorno e recebe parâmetros, sendo responsável por executar uma tarefa específica.

- As funções desempenham um papel fundamental na programação em C, pois possibilitam dividir o código em partes menores e modulares, facilitando a organização, compreensão e manutenção do código.

---

- O tipo de retorno de uma função indica o tipo de dado que ela retorna ao ser chamada.
- Os parâmetros são variáveis passadas à função, permitindo que ela receba informações e opere com base nessas informações.

---

### Como funciona a chamada de funções ###

Quando uma função é chamada em C, o sistema precisa armazenar informações para garantir que a função seja executada e o programa continue a execução corretamente de onde parou.

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

[Linguagens de Programação - Celso Olivete Júnior](http://docs.fct.unesp.br/docentes/dmec/olivete/lp/arquivos/Aula11.pdf)

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

## Mais sobre Recursão ##

### Definições recursivas e conjuntos infinitos ###

- Uma regra básica para definir novos objetos é que a definição deve conter apenas termos já definidos ou óbvios.
- Uma definição que contém o próprio objeto é um círculo vicioso e uma violação dessa regra.
- No entanto, existem conceitos de programação que se definem a si mesmos sem violar a regra.

---

- Essas definições são chamadas de definições recursivas e são usadas principalmente para definir conjuntos infinitos.

- Uma definição recursiva tem duas partes:

1) **Caso base**: lista os elementos básicos que são os blocos de construção de todos os outros elementos do conjunto.
2) **Regras**: permitem a construção de novos objetos a partir de elementos básicos ou objetos já construídos.

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

---

## Fatorial e definições recursivas ##

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

## Consolidando o conceito ##

A recursão ocorre quando uma função chama a si mesma diretamente ou indiretamente. Uma função recursiva geralmente possui duas partes principais: o caso base e o caso recursivo.

- O caso base define as condições em que a função retorna um valor diretamente, sem fazer chamadas recursivas.

- O caso recursivo define como a função chama a si mesma, reduzindo o problema a um subproblema menor.

---

- Recursividade é extremamente útil em diversas áreas da computação incluíndo para inteligência artificial.

---

### Caso Base ###

O caso base é a condição que define quando a função recursiva deve parar de chamar a si mesma e retornar um valor diretamente. É essencial para evitar loops infinitos de chamadas recursivas e garantir que a função eventualmente termine.

- Para o cálculo do fatorial, o caso base ocorre quando n = 0. Neste caso, a função retorna 1, pois o fatorial de 0 é definido como 1.

---

### Caso Recursivo ###

O caso recursivo define como a função chama a si mesma, geralmente com o objetivo de reduzir o problema a um subproblema menor. A solução do subproblema menor é usada para construir a solução do problema original.

- A sequência de Fibonacci começa com os números 0 e 1 e, em seguida, cada número subsequente é a soma dos dois números anteriores, essa soma que é o caso recursimv. As chamadas sucessivas, acabam **reduzindo o problema em um subproblema menor**.

---

## Características dos Problemas para aplicação ##

A programação dinâmica pode ser aplicada quando um problema possui as seguintes características:

- Sobreposição de subproblemas: O problema pode ser dividido em subproblemas menores e a solução do problema original pode ser obtida a partir das soluções desses subproblemas. Além disso, esses subproblemas menores são resolvidos várias vezes, o que leva a cálculos redundantes.

- Subestrutura ótima: A solução ótima do problema original pode ser construída a partir das soluções ótimas dos subproblemas.

---

### Duas abordagens ###

A programação dinâmica utiliza duas abordagens principais para resolver problemas:

---

#### Abordagem de memoização ####

- (top-down): Nesta abordagem, a solução do problema é construída de cima para baixo, começando com o problema original e dividindo-o em subproblemas menores.

- Os resultados dos subproblemas são armazenados em uma tabela (ou estrutura de dados similar) para evitar cálculos redundantes. Quando um subproblema é resolvido pela primeira vez, o resultado é armazenado na tabela.

- Se o mesmo subproblema for encontrado novamente, o resultado armazenado é utilizado em vez de resolver o subproblema novamente.

---

#### Abordagem de programação dinâmica bottom-up ####

- (também chamada de abordagem tabulação) Nesta abordagem, a solução do problema é construída de baixo para cima, começando com os subproblemas menores e combinando suas soluções para resolver problemas maiores.
- A tabela é preenchida em uma ordem específica, de forma que os resultados dos subproblemas estejam disponíveis antes de serem necessários para resolver problemas maiores.
- Isso elimina a necessidade de chamadas recursivas e reduz a redundância de cálculos.

---

### Comparação entre as abordagens ###

Ambas as abordagens, memoização (top-down) e tabulação (bottom-up), têm suas vantagens e desvantagens.

- A abordagem de memoização tende a ser mais intuitiva, pois segue a estrutura natural do problema e pode ser facilmente implementada adicionando uma estrutura de armazenamento (como um dicionário ou matriz) a um algoritmo recursivo existente. No entanto, a memoização ainda usa a recursão e, portanto, pode levar a um maior consumo de memória devido à pilha de chamadas recursivas.

---

- A abordagem de tabulação é geralmente mais eficiente em termos de tempo e espaço, pois elimina a necessidade de chamadas recursivas e calcula apenas os subproblemas que são estritamente necessários para resolver o problema original.

- No entanto, a tabulação pode ser menos intuitiva e requer a identificação de uma ordem específica para resolver os subproblemas.

---

Ambas as abordagens têm como objetivo reduzir a redundância de cálculos e melhorar a eficiência do algoritmo, aproveitando as características de sobreposição de subproblemas e subestrutura ótima do problema em questão. Ao escolher entre as abordagens de programação dinâmica, é importante considerar as especificidades do problema e as necessidades de tempo e espaço do algoritmo.

---

## Exemplo de uso de MEMOIZAÇÃO ##

```cpp
#include <iostream>
#include <unordered_map>

std::unordered_map<int, long long> memo;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    // Verifica se o resultado já foi calculado anteriormente
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // Calcula o resultado e armazena na memória
    long long result = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = result;

    return result;
}

int main() {
    int n = 10; // Exemplo: Calcula o décimo número da sequência de Fibonacci

    long long result = fibonacci(n);

    std::cout << "O " << n << "º número da sequência de Fibonacci é: " << result << std::endl;

    return 0;
}
```

---

## Cálculo do Fatorial ##

```cpp

#include <iostream>

int factorial(int n) {
    // Caso base: se n for 0 ou 1, o fatorial é 1
    if (n == 0 || n == 1) {
        return 1;
    }

    // Chamada recursiva para calcular o fatorial de n - 1
    return n * factorial(n - 1);
}
```

---

```c

int main() {
    int n = 5;  // Exemplo: Calcula o fatorial de 5

    int result = factorial(n);

    std::cout << "O fatorial de " << n << " é: " << result << std::endl;

    return 0;
}

```

---

## Conclusão ##

O uso de recursão torna a solução mais simples e elegante, embora em geral ocasione em mais espaço de memória.
