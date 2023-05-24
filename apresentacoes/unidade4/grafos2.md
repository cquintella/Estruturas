---
marp: true
theme: gaia
paginate: true
backgroundColor: #fff
---

<!-- _class: lead -->

# Grafos - segunda parte #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

---

## Representação de Grafos ##

A representação adequada de um grafo depende do contexto em que ele é utilizado, seja na memória durante a execução de um programa ou quando armazenado em meio digital. Existem diversas formas de representar um grafo, sendo as principais:

- Lista de Adjacência: Nessa representação, cada vértice do grafo possui uma lista que contém os vértices adjacentes a ele. Essa abordagem é eficiente para grafos esparsos, onde apenas as conexões relevantes são armazenadas.

- Matriz de Adjacência: Nessa representação, é utilizada uma matriz bidimensional em que as linhas e colunas representam os vértices do grafo. Os valores na matriz indicam a existência ou o peso das arestas entre os vértices. Essa representação é adequada para grafos densos.

Além dessas formas, outras representações, como a matriz de incidência e a lista de arestas, podem ser utilizadas dependendo das necessidades do problema.

Outro fator importante a considerar é o tipo do grafo que será armazenado. Grafos direcionados possuem arestas com direção específica, enquanto grafos não direcionados não possuem essa distinção. Grafos cíclicos têm ciclos, ou seja, é possível percorrer um caminho e voltar ao vértice inicial. Grafos ponderados atribuem pesos às arestas, representando diferentes custos ou distâncias.

A escolha da forma de representação adequada deve levar em consideração o uso do grafo no programa, a eficiência de armazenamento, a velocidade de acesso aos elementos do grafo e a facilidade de manipulação dos dados. Além disso, as características específicas do grafo, como direção, ciclicidade e pesos, também influenciam na escolha da representação mais adequada.

---

### Matriz de Adjacência ###

É uma matriz quadrada de tamanho NxN, onde N é o número de vértices no grafo. A entrada M[i][j] é 1 se existe uma aresta entre o vértice "i" e o vértice "j", e 0 caso contrário. Para grafos não direcionados, a matriz é simétrica em relação à diagonal principal.

Exemplo para o grafo A - B - C - D:

```text
  A B C D
A 0 1 0 0
B 1 0 1 0
C 0 1 0 1
D 0 0 1 0
```

<!--Se o grafo for ponderado podemos usar os pesos no ligar do flag se existe link ou não.

Mas e se o grafo for direcionado? Se os pesos forem números naturais, que tal usa ro sinal para marcar a direção?

Mas e se for o caso onde possa haver mais de uma conexão em diferentes direçoes entre dois verties especificados? -->

---

### Matriz de Incidência ###

Uma matriz de incidência é uma matriz de tamanho NxM, onde N é o número de vértices e M é o número de arestas. A entrada M[i][j] é 1 se a aresta "j" é incidente ao vértice "i", e 0 caso contrário. Para um grafo não direcionado, cada coluna da matriz terá exatamente dois 1s.

Exemplo para o grafo A - B - C - D com as arestas AB, BC e CD:

---

### Lista de Adjacencia ###

Uma lista de adjacências é uma maneira de representar um grafo em que, para cada vértice do grafo, mantemos uma lista dos vértices aos quais ele está conectado por uma aresta. Essa representação é especialmente útil quando temos um grafo esparso (um grafo com poucas arestas em comparação ao número total possível de arestas), pois economiza espaço de armazenamento.

---

Por exemplo, para um grafo não direcionado com os vértices A, B, C, D e as arestas (A-B), (B-C), (C-D), a lista de adjacências seria a seguinte:

```text
A: B
B: A, C
C: B, D
D: C

```

---

Para representar um grafo com pesos e direcionado, você pode utilizar a representação de Lista de Adjacência com pesos nas arestas. Nesse formato, cada linha do arquivo representa um nó do grafo, e os nós adjacentes são listados com seus respectivos pesos.

```text
1: (2, 3.0), (3, 5.2)
2: (1, 2.1), (3, 4.4)
3: (1, 1.5), (2, 6.1)
```

---

## Exercício ##

Represente as pontes de Kronisberg como um grafo e em seguida com uma Lista de Adjacência.

[Mermaid editor](https://mermaid.live/)

---

Cada linha representa um vértice e os vértices aos quais ele está conectado. Por exemplo, o vértice B está conectado aos vértices A e C, portanto, a linha correspondente na lista de adjacências é "B: A, C".

Em uma lista de adjacências para um grafo direcionado, a presença de um vértice em outra lista de vértices significa que existe uma aresta na direção do primeiro vértice para o segundo.

---

## Travessia de Grafos ##

O processo de travessia envolve "visitar" cada elemento do grafo. Isso é fácil de se fazer com uma lista encadeada, pois cada elemento está ligado ao seguinte em ordem. No entanto, em um grafo, isso não ocorre, já que um grafo pode ter elementos isolados e ligações formando círculos.

---

Nós utilizamos algoritmos conhecidos como: [Depth-First Search](https://www.youtube.com/watch?v=PMMc4VsIacU) (DFS): Busca em Profundidade e (depth-first search) ou [Breadth-First Search](https://www.youtube.com/watch?v=xlVX7dXLS64) (BFS): Busca em Largura; que foi desenvolvido por John Hopcroft e Robert Tarjan.

Neste algoritmo, cada vértice v é visitado e, em seguida, cada vértice adjacente a v não visitado também é visitado. Se um vértice v não tem vértices adjacentes ou se todos os seus vértices adjacentes já foram visitados, nós voltamos ao predecessor de v. A travessia é concluída se este processo de visitação e retorno levar ao primeiro vértice onde a travessia começou. Se ainda houver alguns vértices não visitados no grafo, a travessia continua reiniciando a partir de um dos vértices não visitados.

---

O algoritmo Depth-First Search (DFS), ou Busca em Profundidade, é um algoritmo de travessia de grafos que explora o máximo possível de um ramo antes de retroceder. Começando a partir de um vértice inicial, o algoritmo visita esse vértice e, em seguida, recursivamente visita os vizinhos não visitados desse vértice. O processo continua até que todos os vértices sejam visitados ou não haja mais vértices a serem visitados em um determinado ramo. Em outras palavras, o DFS segue um caminho específico o mais longe possível antes de retroceder.

Por outro lado, o algoritmo Breadth-First Search (BFS), ou Busca em Largura, é um algoritmo de travessia de grafos que explora todos os vértices de um nível antes de passar para o próximo nível. Começando a partir de um vértice inicial, o algoritmo visita esse vértice e, em seguida, visita todos os seus vizinhos. Em seguida, ele visita os vizinhos dos vizinhos e assim por diante. O processo continua até que todos os vértices sejam visitados ou não haja mais vértices a serem visitados em um determinado nível.

A principal diferença entre os dois algoritmos está na ordem em que os vértices são visitados. Enquanto o DFS segue um caminho específico o mais longe possível antes de retroceder, o BFS visita os vértices em níveis consecutivos, explorando todas as arestas de um determinado nível antes de passar para o próximo nível.

Ambos os algoritmos têm suas aplicações e são utilizados em diferentes cenários. O DFS é útil para encontrar componentes conectados, identificar ciclos, determinar caminhos mínimos e realizar outras tarefas relacionadas à estrutura do grafo. Já o BFS é eficaz na determinação do caminho mais curto entre dois vértices, na busca por padrões específicos e em problemas que exigem a exploração sistemática do grafo em largura.

Em resumo, o DFS e o BFS são algoritmos de travessia de grafos com abordagens diferentes para visitar os vértices. Ambos desempenham um papel importante na análise e manipulação de grafos em diferentes problemas e aplicações.

---

Exemplo de implementação em C para matriz de adjacência:

```c

#include <stdio.h>

#define MAX_VERTICES 5
int visited[MAX_VERTICES];

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int start_vertex) {
    visited[start_vertex] = 1;
    printf("%d ", start_vertex);

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[start_vertex][i] == 1 && visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 1, 0},
    };
  
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }

    DFS(graph, 0);

    return 0;
}
```

---

## Propriedades de Grafos ##

Várias propriedades que podem ser computadas e analisadas em redes complexas. Aqui estão algumas das propriedades comumente estudadas:

- Grau (Degree): O **grau de um nó** em uma rede é o número de conexões que ele possui. O **grau do grafo** todo é o maior grau entre todos os vértices do grafo. Em outras palavras, é o maior número de arestas conectadas a qualquer vértice no grafo.

- Tamanho (Size): o tamanho do grafo é a soma do número de vértices com o número de arestas.

---

- Distribuição de Grau (Degree Distribution): A distribuição de grau é a probabilidade de um nó na rede ter um determinado grau. Ela descreve como os graus dos nós estão distribuídos na rede.

- Coeficiente de Aglomeração (Clustering Coefficient): O coeficiente de aglomeração mede a tendência dos vizinhos de um nó estarem conectados entre si.

---

- Caminhos Mínimos (Shortest Paths): Os caminhos mínimos são os caminhos mais curtos entre dois nós em uma rede. A análise dos caminhos mínimos pode fornecer informações sobre a eficiência da comunicação ou a propagação de informações na rede.

- Centralidade (Centrality): A centralidade é uma medida que identifica os nós mais importantes ou influentes em uma rede. Existem diferentes tipos de centralidade, como a centralidade de grau, a centralidade de proximidade, a centralidade de intermediação (betweenness) e a centralidade de vetor próprio (eigenvector centrality).

---

- Coesão da Comunidade (Community Cohesion): A coesão da comunidade é uma medida da força dos agrupamentos ou comunidades na rede. Ela indica o quão fortemente os nós de uma comunidade estão conectados entre si em comparação com as conexões fora da comunidade.

- Componentes Conectados (Connected Components): Os componentes conectados são conjuntos de nós que estão interconectados, onde é possível percorrer de qualquer nó para qualquer outro nó dentro do componente. A análise dos componentes conectados pode revelar a estrutura geral da rede e a existência de sub-redes isoladas.

---

- Centralidade de Intermediação (Betweenness Centrality): A centralidade de intermediação mede a importância de um nó na comunicação entre outros nós na rede. Um nó com alta centralidade de intermediação atua como um ponto de passagem crítico ao longo dos caminhos mais curtos entre outros nós.

---

## Busca de Menor Caminho ##

[Dijkstra's Algorithm - Computerphile](https://www.youtube.com/watch?v=GazC3A4OQTE)