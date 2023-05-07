---
marp: true
author: carlos.quintella@uva.br
backgroundColor: black
paginate: true
theme: gaia
---

<!-- class: invert -->
<!-- _class: lead -->
<!-- _color: white -->


# TAD - Tipo Abstrato de Dados

---

- É um conceito da programação orientada a objetos;
- Define uma estrutura de dados com um conjunto de operações que podem ser realizadas sobre ela;
- Esconde a implementação dos dados, tornando-os acessíveis apenas através das operações definidas;
- Proporciona modularidade e segurança ao código, uma vez que as operações são definidas para garantir o correto uso da estrutura de dados;
- Exemplos de TADs: lista, pilha, fila, árvore, grafo, entre outros.

---

Exemplo:

```c++
class Lista {
private:
    int *dados;
    int tamanho;
public:
    Lista(int tam); // construtor
    ~Lista(); // destrutor
    void inserir(int valor); // operação de inserção
    void remover(int posicao); // operação de remoção
    int buscar(int posicao); // operação de busca
};
```

---

- A classe `Lista` é um exemplo de TAD;
- Define uma estrutura de dados (lista de inteiros) com um conjunto de operações (`inserir`, `remover` e `buscar`) que podem ser realizadas sobre ela;
- Esconde a implementação dos dados (array dinâmico de inteiros), tornando-os acessíveis apenas através das operações definidas;
- Proporciona modularidade e segurança ao código, uma vez que as operações são definidas para garantir o correto uso da estrutura de dados.

---

Tipos abstratos de dados (TADs) são uma abstração que descreve um tipo de dado, juntamente com um conjunto de operações que podem ser realizadas sobre esse tipo de dado. Eles são considerados abstratos porque a implementação dos dados e operações é oculta do usuário, ou seja, o usuário só tem acesso às operações definidas para o tipo de dado, sem precisar saber como elas são implementadas.

TADs podem ser implementados em qualquer linguagem de programação, e fornecem uma maneira de organizar e manipular dados de uma forma mais estruturada e organizada. Eles permitem que os programadores se concentrem na definição dos dados e operações, em vez de se preocupar com a implementação subjacente.

Os TADs são muito utilizados em programação orientada a objetos, onde cada objeto é um exemplo de um tipo de dado abstrato. Por exemplo, um objeto Pessoa pode ter atributos como nome, idade e endereço, bem como operações como adicionar um novo contato ou exibir as informações de contato existentes.

Ao usar TADs, os programadores podem reutilizar o código, criando uma biblioteca de tipos de dados abstratos que podem ser usados em vários projetos. Isso ajuda a tornar o código mais modular e fácil de manter.
User
de um exemplo
ChatGPT

Um exemplo de TAD poderia ser uma classe Lista, que descreve uma lista de elementos. A classe Lista pode ter operações como adicionar um novo elemento, remover um elemento existente ou retornar o número total de elementos na lista.

A implementação subjacente da classe Lista pode variar dependendo da linguagem de programação usada. Por exemplo, em C++, a classe Lista poderia ser implementada usando ponteiros e alocação dinâmica de memória. Já em Python, a classe Lista poderia ser implementada usando estruturas de dados integradas, como listas nativas da linguagem.

Independentemente da implementação, a classe Lista fornece uma abstração que permite que os programadores usem e manipulem listas de elementos de uma forma mais organizada e estruturada. Eles podem usar as operações definidas
