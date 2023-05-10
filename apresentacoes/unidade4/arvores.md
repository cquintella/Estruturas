---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Curso de C++
theme: gaia
---

<!-- _class: lead -->

# Árvores #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

---

As árvores são uma categoria importante de estruturas de dados não lineares. Elas são usadas para representar hierarquias e relacionamentos entre elementos, bem como para realizar operações de busca, inserção e remoção de maneira eficiente.

- [Wikipedia](https://pt.wikipedia.org/wiki/%C3%81rvore_(estrutura_de_dados))

![arvore bg 90% left:33%](https://upload.wikimedia.org/wikipedia/commons/thumb/9/93/Tree.example.png/300px-Tree.example.png)

---

A origem das árvores como estruturas de dados remonta às primeiras pesquisas em ciência da computação e matemática. Os primeiros trabalhos em estruturas de dados baseadas em árvores foram desenvolvidos na década de 1950 e 1960, com o objetivo de organizar e gerenciar informações de maneira eficiente e hierárquica.

---

## Definições ##

- **Raíz**: A raiz é o primeiro nó da árvore e não possui nenhum nó pai. Todos os outros nós da árvore são descendentes diretos ou indiretos da raiz.

- **Floresta**: Uma floresta é um conjunto de árvores que não estão conectadas entre si. Cada árvore individual em uma floresta é chamada de componente.

- **Nó**: Um nó é um elemento individual da árvore que contém informações (dados) e pode ter referências para seus nós filhos.

---

- **Arestas**: Faz a conexão ente os nós.

- **Pai**: O pai é o nó que está diretamente conectado a outro nó por uma aresta em direção à raiz. Cada nó, exceto a raiz, tem exatamente um nó pai.

- **Filho**: Um filho é um nó que está diretamente conectado a outro nó por uma aresta na direção oposta à raiz. Um nó pode ter zero ou mais nós filhos.

- **Folha**: Um nó folha é um nó que não possui filhos. As folhas são os nós terminais da árvore.

---

- **Árvore Ordenada**: Uma árvore ordenada é aquela na qual os filhos de cada nó estão ordenados.
  - Assume-se ordenação da esquerda para a direita.

- **Árvore Cheia**: Uma árvore de grau `d` é uma árvore cheia se possui o número máximo de nós, isto é, todos os nós tem número máximo de filhos (exceto as folhas, logicamente) e o das as folhas estão na mesma altura.

-- **Árvores com grau 2**: Cada nó pode ter 2 filhos, no máximo.

---

## Aplicações ##

Árvores são usadas em muitas aplicações, incluindo sistemas de arquivos, bancos de dados, algoritmos de busca e compressão de dados, Jogos, Computação gráfica, Navegação, GUI e outros.

---

## Métricas de Árvores ##

As métricas em árvores são usadas para avaliar e descrever suas propriedades e características. Algumas métricas comuns em árvores incluem:

- **Altura da árvore**: É a distância entre a raíz e seu nó mais profundo.

Se T é uma árvore, h(T) é dito: a altura de T.

- Se V é uma subárvore, h(V) é a altura da Subárvore.

---

- **Profundidade de um nó**: A profundidade de um nó é o número de arestas entre a raiz e o nó. A profundidade da raiz é 0, e a profundidade dos outros nós é a profundidade do nó pai mais 1.

- **Tamanho**:  O tamanho de uma árvore é o número total de nós presentes nela.

- **Grau**: O grau de um nó é o número máximo de filhos que ele possui. O grau de uma árvore é equivalente ao Grau do nó com maior quantidade de filhos.

- **Caminho**: Um caminho em uma árvore é uma sequência de nós conectados por arestas. O comprimento de um caminho é o número de arestas nele.

Essas métricas podem ser usadas para analisar o desempenho e a eficiência de algoritmos de árvore e para otimizar a estrutura da árvore para melhor atender aos requisitos de uma aplicação específica.

--

## Percurso de uma árvore ##

Assim como percorremos um vetor ou uma matriz para recuperar ou imprimir seu conteúdo, podemos fazer o mesmo com árvores. No entanto, observe que as árvores, assim como as matrizes, podem ser percorridas de diferentes maneiras.

_Nota_:Percorrer uma árvore significa visitar (exibir o conteúdo ou executar uma operação) cada nó da árvore de maneira sistemática e ordenada.

---

## Percurso/Travessia de Árvores ##

Existem várias formas de percorrer uma árvore, e as mais comuns são os percursos em profundidade e em largura. Nos percursos em profundidade, temos três métodos principais:

1. **Pré-ordem (Preorder)**: Neste método, a árvore é percorrida na seguinte ordem: primeiro, visita-se a raiz, depois percorre-se a subárvore esquerda e, por fim, a subárvore direita.

---

2. **Em ordem (Inorder)**: Neste método, a árvore é percorrida na seguinte ordem: primeiro, visita-se a subárvore esquerda, depois a raiz e, por fim, a subárvore direita. Para árvores binárias de busca, esse percurso retorna os valores em ordem crescente.

3. **Pós-ordem (Postorder)**: Neste método, a árvore é percorrida na seguinte ordem: primeiro, visita-se a subárvore esquerda, depois a subárvore direita e, por fim, a raiz.

---

No percurso em largura, também chamado de **travessia em nível (Level-order traversal)**, os nós são visitados nível por nível, da esquerda para a direita. Esse percurso pode ser realizado usando uma fila para armazenar os nós a serem visitados em cada nível.

---

## Tipos de árvores ##

Algumas das árvores mais comuns incluem árvores binárias, árvores AVL, árvores de busca binária, árvores B..

---

Uma das primeiras árvores de dados conhecidas é a árvore binária, que foi introduzida por John von Neumann em 1946 para resolver problemas de pesquisa, classificação e codificação de prefixo. Desde então, muitas outras árvores e variações foram propostas e desenvolvidas para resolver uma ampla gama de problemas de computação.

---

Por exemplo, a árvore binária de busca (BST) foi desenvolvida na década de 1960 para melhorar a eficiência das pesquisas. A árvore AVL, uma das primeiras árvores binárias de busca autoequilibradas, foi introduzida por Adelson-Velsky e Landis em 1962. A árvore B foi proposta por Rudolf Bayer e Edward M. McCreight em 1972 como uma generalização da árvore binária de busca, adequada para armazenamento em disco e recuperação eficiente de dados.

---

Elas são usadas para representar hierarquias, facilitar pesquisas eficientes e organizar dados de maneira eficaz. Existem vários tipos de árvores em estruturas de dados, incluindo:

**Árvore Binária**: É uma árvore onde cada nó tem no máximo dois filhos, geralmente chamados de filho esquerdo e filho direito.

Árvore Binária de Busca (Binary Search Tree, BST): É uma árvore binária com a propriedade de que o valor de cada nó é maior do que ou igual a todos os valores dos nós à sua esquerda e menor do que ou igual a todos os valores dos nós à sua direita. As BSTs permitem inserção, remoção e pesquisa eficientes.

---

**Árvore AVL**: É uma árvore binária de busca autoequilibrada que garante que a altura da árvore permaneça logarítmica em relação ao número de nós. As árvores AVL realizam rotações para manter o equilíbrio após inserções e remoções.

**Árvore Rubro-Negra (Red-Black Tree)**: É outra árvore binária de busca autoequilibrada que utiliza cores (vermelho ou preto) para manter o equilíbrio. As operações de inserção, remoção e pesquisa têm complexidade de tempo logarítmico.

---

**Árvore B**: É uma árvore de busca generalizada que permite que cada nó tenha um número variável de filhos (maior que 2) e chaves. As árvores B são comumente usadas em sistemas de gerenciamento de banco de dados e sistemas de arquivos para armazenar e recuperar dados de maneira eficiente.

**Árvore Trie (ou Prefix Tree)**: É uma árvore de pesquisa onde os nós armazenam caracteres em vez de valores completos. As tries são usadas para armazenar um conjunto dinâmico de strings, permitindo pesquisas eficientes por prefixo.

---

**Árvore de Segmentos (Segment Tree)**: É uma árvore binária usada para armazenar informações sobre intervalos ou segmentos. As árvores de segmentos são úteis para resolver problemas que envolvem consultas e atualizações de intervalos em um array.

**Árvore Fenwick (ou Binary Indexed Tree, BIT)**: É uma estrutura de dados que combina as propriedades de arrays e árvores binárias para fornecer uma maneira eficiente de executar consultas de intervalo e atualizações em arrays.

---

**Árvore K-D (K-Dimensional Tree)**: É uma árvore binária de busca que armazena pontos em um espaço k-dimensional. As árvores K-D são usadas para pesquisas espaciais eficientes, como consultas de vizinhos mais próximos.
