---
marp: true
author: carlos.quintella@uva.br
backgroundColor: black
paginate: true
theme: gaia
---

<!-- class: invert -->
<!-- _class: lead -->
<!-- color: white -->

# Problemas Complexos #

Professor: carlos Alvaro Quintella

---

## Definições ##

Problemas complexos em programação são aqueles que são difíceis de resolver ou levar muito tempo para serem resolvidos. Esses problemas geralmente requerem mais recursos computacionais ou uma abordagem mais sofisticada para serem resolvidos de forma eficiente.

* [HBR: What It Takes to Think Deeply About Complex Problems](https://hbr.org/2018/05/what-it-takes-to-think-deeply-about-complex-problems)
* [HBR:  How to Solve Problems](https://hbr.org/2021/10/how-to-solve-problems)

---

Alguns exemplos de problemas complexos em programação incluem:

* **Problemas de otimização**: problemas que envolvem a busca da melhor solução possível, geralmente com muitas variáveis ou restrições.

* **Problemas de computação de alta performance**: problemas que envolvem grandes quantidades de dados ou cálculos complexos, que podem exigir o uso de computação paralela ou distribuída para serem resolvidos de forma eficiente.

---

* **Problemas de inteligência artificial**: problemas que envolvem a criação de modelos ou algoritmos de aprendizado de máquina ou processamento de linguagem natural, que podem exigir a análise de grandes quantidades de dados e o uso de técnicas sofisticadas para obter resultados precisos.
  
---

A identificação de problemas complexos em programação pode ser feita observando-se a natureza do problema e sua complexidade intrínseca, bem como os recursos computacionais necessários para resolvê-lo de forma eficiente.

Muitas vezes, problemas complexos requerem soluções criativas e abordagens inovadoras para serem resolvidos de forma satisfatória.

---

## Estratégias ##

1- **Dividir para conquistar**: Esta estratégia envolve dividir um problema complexo em subproblemas menores e mais gerenciáveis. Resolvendo esses subproblemas, você pode juntar as soluções para resolver o problema original. Algoritmos de ordenação como merge sort e quick sort são exemplos clássicos dessa abordagem.

---

2- **Programação dinâmica**: Esta técnica é útil para resolver problemas de otimização que possuem uma estrutura de sobreposição ótima. A ideia é armazenar os resultados de subproblemas em uma tabela para evitar cálculos repetidos, o que acelera a solução do problema original. Exemplos de problemas que podem ser resolvidos com programação dinâmica incluem o problema do troco, o problema da mochila e o problema da subsequência comum mais longa.

---

3- **Busca em árvore / grafos**: Muitos problemas computacionais envolvem a exploração de um espaço de estados em forma de árvore ou grafo. Estratégias de busca, como busca em profundidade, busca em largura e busca A* (A-estrela), são usadas para encontrar soluções nesses casos.

---

4- **[Algoritmos gulosos](https://www.wikiwand.com/pt/Algoritmo_guloso)**: Algoritmos gulosos são aqueles que tomam decisões localmente ótimas na esperança de encontrar uma solução globalmente ótima. Eles são geralmente mais simples de implementar e mais rápidos do que outras abordagens, mas nem sempre produzem a solução ótima. Exemplos de problemas solucionáveis com algoritmos gulosos incluem o problema do troco (com moedas canônicas) e o problema do agendamento de tarefas.

---

5- **[Backtracking](https://www.wikiwand.com/pt/Backtracking)**: Backtracking é uma estratégia que envolve explorar o espaço de soluções de um problema, testando parcialmente as soluções e descartando aquelas que não levam a uma solução completa e válida. Problemas como o das oito rainhas e o problema do caixeiro-viajante podem ser resolvidos usando backtracking.

---

6- **[Heurísticas](https://www.wikiwand.com/pt/Heur%C3%ADstica) e [meta-heurísticas](https://www.wikiwand.com/pt/Meta-heur%C3%ADstica)**: Essas técnicas são usadas quando uma solução exata para um problema é computacionalmente cara ou inviável. Heurísticas são regras simples e eficientes que fornecem soluções aproximadas para um problema, enquanto meta-heurísticas são algoritmos de alto nível que exploram o espaço de soluções para encontrar soluções aproximadas. Exemplos de meta-heurísticas incluem algoritmos genéticos, otimização por enxame de partículas e [recozimento simulado](https://www.wikiwand.com/pt/Simulated_annealing).

---

7- **[Programação linear](https://www.wikiwand.com/pt/Programa%C3%A7%C3%A3o_linear) e inteira**: Problemas de otimização com restrições lineares podem ser resolvidos usando técnicas de programação linear, como o método simplex. Quando as variáveis são restritas a valores inteiros, podemos usar técnicas de [programação inteira](https://www.wikiwand.com/pt/Programa%C3%A7%C3%A3o_inteira), como o [branch-and-bound](https://www.wikiwand.com/pt/Ramificar_e_limitar).

---

## Exemplos Interessantes ##

### A Programação Genética (PG) ###

É um ramo da computação evolutiva que tem como objetivo gerar programas de computador de forma automática. A PG foi desenvolvida na década de 1990 por John Koza e se baseia na evolução biológica para criar soluções para problemas complexos.

---

Na PG, os programas de computador são representados como árvores sintáticas, em que os nós da árvore correspondem a funções ou operações, e as folhas correspondem a variáveis ou constantes. Cada programa é avaliado quanto à sua aptidão (fitness) para resolver o problema em questão, e então é aplicado um processo de seleção, reprodução e mutação para gerar uma nova geração de programas.

O processo de seleção é baseado na aptidão dos programas, de forma que programas com maior aptidão têm maior probabilidade de serem selecionados para reprodução. O processo de reprodução é feito por meio da recombinação de subárvores dos programas selecionados, produzindo novos programas. Finalmente, a mutação é aplicada para introduzir variação genética na população, permitindo que novas soluções possam ser descobertas.

A Programação Genética é uma técnica poderosa para gerar soluções para problemas complexos, especialmente em casos em que a solução ótima é desconhecida ou difícil de encontrar. Ela já foi aplicada em diversas áreas, como engenharia, biologia, finanças e jogos.

No entanto, assim como outras técnicas de computação evolutiva, a PG pode levar a soluções subótimas ou mesmo inúteis, dependendo do problema em questão e das escolhas feitas no processo de evolução. Além disso, a avaliação de aptidão pode ser um processo demorado e caro computacionalmente, especialmente para problemas complexos.

[Genetic programming: an introduction and survey of applications](https://ieeexplore.ieee.org/document/681044)

---

### Simulação de Monte Carlo ###

A ideia básica da simulação de Monte Carlo é gerar um grande número de amostras aleatórias e usar os resultados para aproximar a solução do problema. A qualidade da aproximação geralmente melhora à medida que o número de amostras aumenta.

Por exemplo, a simulação de Monte Carlo pode ser usada para aproximar o valor de pi. Você pode gerar pontos aleatórios dentro de um quadrado que contém um círculo e contar a proporção de pontos que caem dentro do círculo em relação ao total de pontos gerados. Essa proporção pode ser usada para aproximar o valor de pi com base na área do círculo e do quadrado.

---

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, pontos_dentro_do_circulo = 0, total_pontos = 1000000;
    double x, y, pi;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera pontos aleatórios e conta quantos caem dentro do círculo
    for (i = 0; i < total_pontos; i++) {
        x = (double)rand() / RAND_MAX * 2 - 1;
        y = (double)rand() / RAND_MAX * 2 - 1;

        if (x * x + y * y <= 1) {
            pontos_dentro_do_circulo++;
        }
    }

    // Calcula a aproximação de π
    pi = 4 * (double)pontos_dentro_do_circulo / total_pontos;

    printf("Estimativa de Pi com base na simulação de Monte Carlo: %f\n", pi);

    return 0;
}
```

---

[Simulação de Monte Carlo](https://www.youtube.com/watch?v=7ESK5SaP-bc)

---

## Exemplos clássicos de problemas complexos em programação ##

1- **Problema do caixeiro-viajante**
O problema do [caixeiro-viajante](https://www.wikiwand.com/pt/Problema_do_caixeiro-viajante) é um problema de otimização combinatória que envolve encontrar o menor caminho possível que um viajante pode percorrer, passando por todas as cidades em uma lista, e voltar para a cidade de origem. É considerado um problema complexo porque a quantidade de possíveis rotas aumenta exponencialmente com o número de cidades, tornando impossível testar todas as possibilidades em tempo razoável.

---

Uma estratégia recomendada para resolvê-lo é usar algoritmos de busca heurística, como algoritmos genéticos ou algoritmos de busca em vizinhança, que podem encontrar soluções aproximadas em tempo razoável.

[Caixeiro Viajante](https://www.youtube.com/watch?v=T9nqWFONdKM)
[Caixeiro Viajante 2](https://www.youtube.com/watch?v=QTMo_El_tMU)

---

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_POP 100
#define TAXA_MUT 0.01
#define TAXA_CRUZ 0.5
#define NUM_GERACOES 1000

typedef struct {
    int* genes;
    int distancia;
} Individuo;

int** criarMatrizDistancias(int n);
void liberarMatrizDistancias(int** matriz, int n);
void criarPopulacao(Individuo* populacao, int tam_pop, int n);
void liberarPopulacao(Individuo* populacao, int tam_pop);
void avaliarPopulacao(Individuo* populacao, int tam_pop, int** matriz_distancias, int n);
void ordenarPopulacao(Individuo* populacao, int tam_pop);
void selecionarPais(int* pai1, int* pai2, int tam_pop);
void cruzarIndividuos(Individuo* filho1, Individuo* filho2, Individuo* pai1, Individuo* pai2, int n);
void mutarIndividuo(Individuo* individuo, int n);
void evoluirPopulacao(Individuo* populacao, int tam_pop, int** matriz_distancias, int n);
void imprimirMelhorIndividuo(Individuo* populacao);
```

---

```c
int main() {
    srand(time(NULL));
    int n = 10;
    int** matriz_distancias = criarMatrizDistancias(n);
    Individuo populacao[TAM_POP];
    criarPopulacao(populacao, TAM_POP, n);
    avaliarPopulacao(populacao, TAM_POP, matriz_distancias, n);
    ordenarPopulacao(populacao, TAM_POP);

    for(int geracao = 1; geracao <= NUM_GERACOES; geracao++) {
        evoluirPopulacao(populacao, TAM_POP, matriz_distancias, n);
        ordenarPopulacao(populacao, TAM_POP);
        imprimirMelhorIndividuo(populacao);
    }

    liberarPopulacao(populacao, TAM_POP);
    liberarMatrizDistancias(matriz_distancias, n);

    return 0;
}

```

---

```c

int** criarMatrizDistancias(int n) {
    int** matriz = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
    return matriz;
}

void liberarMatrizDistancias(int** matriz, int n) {
    for(int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

```

---

```c

void criarPopulacao(Individuo* populacao, int tam_pop, int n) {
    for(int i = 0; i < tam_pop; i++) {
        populacao[i].genes = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            populacao[i].genes[j] = j;
        }
        for(int j = n - 1; j > 0; j--) {
            int k = rand() % (j + 1);
            int tmp = populacao[i].genes[j];
            populacao[i].genes[j] = populacao[i].genes[k];
            populacao[i].genes[k] = tmp;
        }
    }
}
```

---

```c

void avaliarPopulacao(Individuo* populacao, int tam_pop, int** matriz_distancias, int n) {
    for(int i = 0; i < tam_pop; i++) {
        int distancia = 0;
        for(int j = 0; j < n - 1; j++) {
            int cidade_atual = populacao[i].genes[j];
            int prox_cidade = populacao[i].genes[j + 1];
            distancia += matriz_distancias[cidade_atual][prox_cidade];
        }
        int cidade_final = populacao[i].genes[n - 1];
        int cidade_inicial = populacao[i].genes[0];
        distancia += matriz_distancias[cidade_final][cidade_inicial];
        populacao[i].distancia = distancia;
    }
}

void ordenarPopulacao(Individuo* populacao, int tam_pop) {
    for(int i = 0; i < tam_pop - 1; i++) {
        for(int j = i + 1; j < tam_pop; j++) {
            if(populacao[i].distancia > populacao[j].distancia) {
                Individuo tmp = populacao[i];
                populacao[i] = populacao[j];
                populacao[j] = tmp;
            }
        }
    }
}

```

---

```c

void selecionarPais(int* pai1, int* pai2, int tam_pop) {
    *pai1 = rand() % tam_pop;
    *pai2 = rand() % tam_pop;
    while(*pai2 == *pai1) {
        *pai2 = rand() % tam_pop;
    }
}

void cruzarIndividuos(Individuo* filho1, Individuo* filho2, Individuo* pai1, Individuo* pai2, int n) {
    int ponto_corte = rand() % (n - 1) + 1;
    for(int i = 0; i < ponto_corte; i++) {
        filho1->genes[i] = pai1->genes[i];
        filho2->genes[i] = pai2->genes[i];
    }
    int j = ponto_corte;
    for(int i = 0; i < n; i++) {
        int cidade = pai2->genes[i];
        int encontrado = 0;
        for(int k = 0; k < ponto_corte; k++) {
            if(cidade == filho1->genes[k]) {
                encontrado = 1;
                break;
            }
        }
        if(!encontrado) {
            filho1->genes[j] = cidade;
            j++;
        }
        if(j == n) {
            break;
        }
    }
    j = ponto_corte;
    for(int i = 0; i < n; i++) {
        int cidade = pai1->genes[i];
        int encontrado = 0;
        for(int k = 0; k < ponto_corte; k++) {
            if(cidade == filho2->genes[k]) {
                encontrado = 1;
                break;
            }
        }
        if(!encontrado) {
            filho2->genes[j] = cidade;
            j++;
        }
        if(j == n) {
            break;
        }
    }
}

```

---

```c
void mutarIndividuo(Individuo* individuo, double taxa_mutacao, int n) {
    for(int i = 0; i < n; i++) {
        if((double)rand() / RAND_MAX < taxa_mutacao) {
            int j = rand() % n;
            int tmp = individuo->genes[i];
            individuo->genes[i] = individuo->genes[j];
            individuo->genes[j] = tmp;
        }
    }
}

void evoluirPopulacao(Individuo* populacao, int tam_pop, int** matriz_distancias, int n) {
    Individuo nova_populacao[TAM_POP];
    int elite = tam_pop * ELITE_PERCENT / 100;

    for(int i = 0; i < elite; i++) {
        nova_populacao[i] = populacao[i];
    }

    for(int i = elite; i < tam_pop; i += 2) {
        int pai1, pai2;
        selecionarPais(&pai1, &pai2, tam_pop);
        cruzarIndividuos(&nova_populacao[i], &nova_populacao[i + 1], &populacao[pai1], &populacao[pai2], n);
        mutarIndividuo(&nova_populacao[i], TAXA_MUTACAO, n);
        mutarIndividuo(&nova_populacao[i + 1], TAXA_MUTACAO, n);
    }

```

---

```c
    avaliarPopulacao(nova_populacao, TAM_POP, matriz_distancias, n);
    ordenarPopulacao(nova_populacao, TAM_POP);
    for(int i = 0; i < tam_pop; i++) {
        populacao[i] = nova_populacao[i];
    }
}

void imprimirMelhorIndividuo(Individuo* populacao) {
    printf("Distancia do melhor individuo: %d\n", populacao[0].distancia);
}

```

---

2- **Problema da mochila**

O problema da mochila é um problema de otimização combinatória que envolve escolher um subconjunto de itens de uma lista, com limitações de peso, para maximizar o valor total.
É considerado um problema complexo porque a quantidade de possíveis combinações aumenta exponencialmente com o número de itens, tornando impossível testar todas as possibilidades em tempo razoável. Uma estratégia recomendada para resolvê-lo é usar algoritmos de programação dinâmica ou algoritmos genéticos para encontrar soluções aproximadas em tempo razoável.

[The Knapsack Problem & Genetic Algorithms - Computerphile](https://www.youtube.com/watch?v=MacVqujSXWE)

---

3- **Problema da multiplicação de matrizes**
O problema da multiplicação de matrizes é um problema de computação de alta performance que envolve a multiplicação de duas ou mais matrizes grandes. É considerado um problema complexo porque o tempo de execução aumenta exponencialmente com o tamanho das matrizes, tornando impossível multiplicar matrizes muito grandes em tempo razoável em um único núcleo de processamento.

---

Uma estratégia recomendada para resolvê-lo é usar técnicas de computação paralela ou distribuída, como o uso de GPUs ou clusters de computação, para dividir a tarefa em várias partes e acelerar o processo de multiplicação.

[Multiplicação de matrizes como composição](https://www.youtube.com/watch?v=XkY2DOUCWMU)

[AlphaTensor by DEEPMIND finds new Algorithms for Matrix Multiplication](https://www.youtube.com/watch?v=8ILk4Wjo5rc)

---

4- **Problema do reconhecimento de padrões**
O problema do reconhecimento de padrões é um problema de inteligência artificial que envolve a identificação de padrões em dados brutos, geralmente usando técnicas de aprendizado de máquina. É considerado um problema complexo porque a quantidade de dados pode ser muito grande e os padrões podem ser sutis ou difíceis de detectar. Uma estratégia recomendada para resolvê-lo é usar técnicas de aprendizado de máquina, como redes neurais ou árvores de decisão, para treinar modelos a partir de dados de treinamento e usá-los para identificar padrões em novos dados.

[Pattern Recognition - Introduction](https://www.youtube.com/watch?v=cbZUnuyxcVs)

---

## Bibliografia ##

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Algoritmos: Teoria e Prática. Rio de Janeiro: Elsevier. (Versão em português do clássico "Introduction to Algorithms")

Sedgewick, R., & Wayne, K. (2011). Algorithms. Addison-Wesley Professional.

Skiena, S. S. (2020). The Algorithm Design Manual. Springer.

Knuth, D. E. (1997). The Art of Computer Programming, Volumes 1-4A. Addison-Wesley.

Kleinberg, J., & Tardos, É. (2005). Algorithm Design. Pearson Education.

Horowitz, E., Sahni, S., & Mehta, D. (2007). Fundamentals of Data Structures in C++. Silicon Press.

Lafore, R. (2003). Estruturas de Dados e Algoritmos em C++. São Paulo: Pearson Makron Books. (Versão em português do livro "Data Structures and Algorithms in C++")

Papadimitriou, C. H., & Steiglitz, K. (1998). Combinatorial Optimization: Algorithms and Complexity. Dover Publications.

Aho, A. V., & Ullman, J. D. (1995). Fundamentos de Teoria da Computação. Rio de Janeiro: LTC. (Versão em português do livro "Foundations of Computer Science")
