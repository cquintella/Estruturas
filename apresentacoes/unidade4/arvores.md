---
marp: true
theme: gaia
paginate: true
backgroundColor: #fff
---

<!-- _class: lead -->

# Árvores #

---

As árvores são uma categoria importante de estruturas de dados não lineares.

A origem das árvores como estruturas de dados remonta às primeiras pesquisas em ciência da computação e matemática. Os primeiros trabalhos em estruturas de dados baseadas em árvores foram desenvolvidos na década de 1950 e 1960, com o objetivo de organizar e gerenciar informações de maneira eficiente e hierárquica.

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

--- 
## binary search trees, also called ordered binary trees ##
    
Uma árvore de busca binária tem a seguinte propriedade: para cada nó n da árvore, todos os valores armazenados em sua subárvore esquerda (a árvore cuja raiz é o filho esquerdo) são menores do que o valor v armazenado em n, e todos os valores armazenados na subárvore direita são maiores ou iguais a v.

Armazenar várias cópias do mesmo valor na mesma árvore pode levar a problemas de ambiguidade e tornar a estrutura de dados menos eficiente.

---

Em uma árvore de busca binária, cada nó é geralmente usado para armazenar um valor exclusivo, e a estrutura da árvore é construída de tal forma que cada valor é armazenado em um único nó. Se múltiplas cópias do mesmo valor são armazenadas na árvore, pode se tornar difícil determinar a localização exata de cada cópia e qual delas é a correta. Isso pode levar a erros na busca e manipulação dos dados armazenados na árvore.

Além disso, armazenar múltiplas cópias do mesmo valor em uma árvore pode torná-la menos eficiente, já que é necessário alocar mais espaço para armazenar os valores repetidos e executar mais operações de busca e comparação para lidar com esses valores.

---

### Implementação de Binary Search Tree ###

As árvores binárias podem ser implementadas de pelo menos duas maneiras: como arrays e como estruturas interconectadas (linked structures).

---

#### com vetor ###

Para implementar uma árvore como um array, um nó é declarado como uma estrutura com um campo de informação e dois campos de "ponteiro". Esses campos de ponteiro contêm os índices das células do array em que os filhos esquerdo e direito são armazenados, se houver algum. 

```cpp
struct Node {
    int data;
    int left_child;
    int right_child;
};
````

---

No entanto, essa implementação pode ser inconveniente, mesmo que o array seja flexível - ou seja, um vetor. As localizações dos filhos devem ser conhecidas para inserir um novo nó e essas localizações podem precisar ser localizadas sequencialmente. Depois de excluir um nó da árvore, um buraco no array teria que ser eliminado. Isso pode ser feito usando um marcador especial para uma célula não utilizada, o que pode levar a popular o array com muitas células não utilizadas, ou movendo os elementos uma posição, o que também requer atualizar as referências aos elementos que foram movidos. Às vezes, uma implementação de array é conveniente e desejável, e será usada ao discutir o heap sort. Mas geralmente, outra abordagem precisa ser usada.

---


   
   A raiz é sempre localizada na primeira célula, célula 0, e -1 indica um filho nulo. Nessa representação, os dois filhos do nó 13 estão localizados nas posições 4 e 2, e o filho direito do nó 31 é nulo.



---

### raiz ###
root level 1


### nós ###

Em uma árvore, um nó não-terminal (também chamado de nó interno) é um nó que tem pelo menos um filho. Em outras palavras, um nó não-terminal é um nó que não é uma folha, ou seja, está localizado em algum lugar entre a raiz e as folhas da árvore.

---


### folha ###

Em uma árvore, uma "folha" (também chamada de "nó folha" ou "nó terminal") é um nó que não tem nenhum filho. Em outras palavras, uma folha é um nó que está localizado na extremidade de um ramo e não tem nenhum outro nó conectado a ele.



---

### Altura da árvore ###

The empty tree is a legitimate tree of height 0 (by definition), and a single node is a tree of height 1

node and arches 


a principio nao existe limite para a altura de uma arvore, depende apenas da disponibilidade de memoria

Compare busca e insercao em arvore e lista ligada

An important characteristic of bi- nary trees, which is used later in assessing an expected efficiency of sorting algo- rithms, is the number of leaves.

As already defined, the level of a node is the number of arcs traversed from the root to the node plus one.

## Desenhos de árvores válidas ##

```mermaid
graph TD
A --> B
A --> C
A --> H
B --> D
B --> E
C --> F
C --> G
C --> I
```



```mermaid
graph TD
1 --> 2
1 --> 3
2 --> 4
4 --> 5
4 --> 6
3 --> 7
7 --> 8
```
```mermaid
graph TD
X --> Y
X --> Z
Y --> W
Y --> V
Z --> U
Z --> T

```
```mermaid
graph TD
M --> N
N --> O
O --> P
P --> Q

```
```mermaid
graph TD
Root --> A1
Root --> A2
A1 --> B1
A1 --> B2
A2 --> B3
B2 --> C1
B2 --> C2

```
```mermaid

```

---

## Binary search tree with arrays ##

```cpp

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    int left_child;
    int right_child;
};

class BinaryTree {
public:
    BinaryTree() {
        // Inicializa o vetor com um nó raiz nulo
        nodes.push_back({0, -1, -1});
    }

    // Insere um novo nó na árvore com o valor especificado
    void insert(int value) {
        int current = 0; // Começa na raiz

        // Percorre a árvore até encontrar uma folha vazia para inserir o novo nó
        while (true) {
            if (value < nodes[current].data) {
                if (nodes[current].left_child == -1) {
                    nodes.push_back({value, -1, -1});
                    nodes[current].left_child = nodes.size() - 1;
                    break;
                } else {
                    current = nodes[current].left_child;
                }
            } else {
                if (nodes[current].right_child == -1) {
                    nodes.push_back({value, -1, -1});
                    nodes[current].right_child = nodes.size() - 1;
                    break;
                } else {
                    current = nodes[current].right_child;
                }
            }
        }
    }

    // Busca um valor na árvore
    bool search(int value) {
        int current = 0; // Começa na raiz

        while (current != -1) {
            if (nodes[current].data == value) {
                return true; // Valor encontrado
            } else if (value < nodes[current].data) {
                current = nodes[current].left_child;
            } else {
                current = nodes[current].right_child;
            }
        }

        return false; // Valor não encontrado
    }

private:
    vector<Node> nodes;
};

int main() {
    BinaryTree tree;

    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);

    cout << tree.search(3) << endl; // Saída: 1 (true)
    cout << tree.search(6) << endl; // Saída: 0 (false)

    return 0;
}

```
