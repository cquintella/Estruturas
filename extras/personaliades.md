---
marp: true
theme: default
paginate: true
---

# Personalidades

Donald Knuth - autor de "The Art of Computer Programming" e criador da linguagem de programação TeX.
Edsger Dijkstra - um pioneiro em ciência da computação, conhecido por sua contribuição à teoria dos grafos e desenvolvimento do algoritmo de Dijkstra.
Claude Shannon - criador da teoria da informação e pioneiro em comunicação digital.

---

John von Neumann - um matemático e cientista da computação que foi fundamental no desenvolvimento do computador moderno e da teoria da automação.
Alan Turing - considerado o pai da computação teórica e um dos principais responsáveis pela decodificação do Enigma, máquina utilizada pelos nazistas para criptografar mensagens durante a Segunda Guerra Mundial.
Barbara Liskov - conhecida por sua contribuição ao desenvolvimento da linguagem de programação CLU e por suas pesquisas em programação orientada a objetos e sistemas distribuídos.

---

Niklaus Wirth - desenvolvedor da linguagem de programação Pascal e autor do livro "Algorithms + Data Structures = Programs".

---

## O Trabalho de Donald Knuth

---

### Introdução

- Quem foi Donald Knuth?
- Principais contribuições para a Ciência da Computação
- Prêmios e reconhecimentos

---

### Quem foi Donald Knuth?

- Nascido em 1938 nos Estados Unidos
- Matemático, cientista da computação e professor
- Autor de diversos livros e trabalhos importantes na área de algoritmos e análise de algoritmos

---

### Principais contribuições para a Ciência da Computação

- Série de livros "The Art of Computer Programming"
- Criação da linguagem de programação TEX e do sistema de formatação de textos METAFONT
- Desenvolvimento do algoritmo de ordenação "Quicksort"
- Contribuições em análise de algoritmos e estruturas de dados

---

### The Art of Computer Programming

- Livros-texto clássicos sobre programação de computadores e algoritmos
- Abrange diversos tópicos, como análise de algoritmos, estruturas de dados, combinatória e teoria dos grafos
- Importante referência para estudantes e profissionais da área

---

### TEX e METAFONT

- Linguagem de programação para tipografia digital de alta qualidade
- TEX: foco na composição tipográfica e formatação de textos matemáticos
- METAFONT: sistema para a criação e manipulação de fontes digitais

---

### Quicksort

- Algoritmo de ordenação eficiente e amplamente utilizado
- Baseado no princípio "dividir para conquistar"
- Complexidade média de O(n * log(n)), onde n é o número de elementos a serem ordenados

---

### Análise de algoritmos e estruturas de dados

- Desenvolveu técnicas e metodologias para analisar a eficiência de algoritmos
- Contribuições em estruturas de dados como árvores de busca, tabelas hash e listas ligadas
- Influenciou a pesquisa e o desenvolvimento de novos algoritmos e estruturas de dados

---

### Prêmios e reconhecimentos

- ACM Turing Award (1974)
- Medalha Nacional de Ciência dos EUA (1979)
- Prêmio Kyoto (1996)
- Membro da Academia Nacional de Ciências dos EUA

---

### Conclusão

- Donald Knuth é um pioneiro e uma figura icônica na Ciência da Computação
- Seus trabalhos são fundamentais para a compreensão de algoritmos e programação
- Estudar suas contribuições é essencial para qualquer profissional da área

---

![Art of Computer Programming](https://m.media-amazon.com/images/I/410vJZbAZGS._SY393_BO1,204,203,200_.jpg)

[Lex Friedman - Donald Knuth](https://www.youtube.com/watch?v=2BdBfsXbST8)

---

## O Trabalho de Edsger W. Dijkstra

### Introdução**
- Quem foi Edsger W. Dijkstra?
- Contribuições importantes para a Ciência da Computação
- Prêmios e reconhecimentos

## Quem foi Edsger W. Dijkstra?

- Nascido em 1930 na Holanda, faleceu em 2002
- Matemático, cientista da computação e professor
- Desenvolveu trabalhos fundamentais em algoritmos, linguagens de programação e sistemas distribuídos

---

## Contribuições importantes para a Ciência da Computação

- Algoritmo de Dijkstra para caminho mínimo em grafos
- Estruturas de dados e algoritmos para sistemas operacionais
- Conceitos de semáforos e exclusão mútua
- Contribuições para a linguagem de programação ALGOL

---

## Algoritmo de Dijkstra
- Encontra o caminho mais curto entre dois vértices em um grafo ponderado
- Amplamente utilizado em aplicações de roteamento e logística
- Base para outros algoritmos de caminho mínimo

---

```c++
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

const int INF = std::numeric_limits<int>::max();

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adj_list, int source) {
    int n = adj_list.size();
    std::vector<int> dist(n, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj_list(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int source;
    std::cin >> source;

    std::vector<int> distances = dijkstra(adj_list, source);

    for (int i = 0; i < n; ++i) {
        std::cout << "Distância mínima de " << source << " para " << i << " é " << distances[i] << std::endl;
    }

    return 0;
}

```

Essa implementação utiliza uma lista de adjacências para representar o grafo e uma fila de prioridade para armazenar os vértices a serem processados. A função dijkstra recebe a lista de adjacências e o vértice de origem, e retorna um vetor contendo as distâncias mínimas de cada vértice em relação ao vértice de origem.

---

## Estruturas de dados e algoritmos para sistemas operacionais

- Desenvolveu o THE (Technische Hogeschool Eindhoven) Multiprogramming System
- Introduziu conceitos de estrutura em camadas e hierarquia de módulos
- Influenciou o desenvolvimento de sistemas operacionais modernos

---

## Semáforos e Exclusão Mútua

- Conceitos fundamentais para o controle de concorrência em sistemas distribuídos
- Permitiu a criação de algoritmos e sistemas mais eficientes e seguros
- Base para a teoria e prática da computação paralela e distribuída

---

## Contribuições para a linguagem de programação ALGOL

- Participou do desenvolvimento da linguagem de programação ALGOL 60
- Influenciou a sintaxe e semântica de muitas linguagens posteriores
- Defendeu a importância da legibilidade e estrutura no código

### Prêmios e reconhecimentos

- ACM Turing Award (1972)
- Kyoto Prize (1989)
- Medalha John von Neumann (2002)
- Membro da Academia Real Holandesa de Artes e Ciências

#### RESPONSÁVEL PELA DEMONIZAÇÃO DO GOTO!

---

## Conclusão

- Edsger W. Dijkstra foi um pioneiro e influente cientista da computação
- Seus trabalhos continuam relevantes e impactantes na atualidade
- A compreensão de suas contribuições é essencial para qualquer profissional da área

---