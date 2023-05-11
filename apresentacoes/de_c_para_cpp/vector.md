---
marp: true
author: carlos.quintella@uva.br
backgroundColor : white
paginate: true
theme: gaia
---

<!-- _class: lead -->

# C++: Vector #

---

O vector em C++ é um contêiner dinâmico que permite armazenar e manipular uma sequência de elementos. Ele é similar a um array, mas possui tamanho variável e recursos extras, como inserção, exclusão e ordenação de elementos.

> Um contêiner dinâmico é uma estrutura de dados que permite armazenar e manipular elementos de forma flexível, com tamanho variável, que pode crescer ou encolher conforme necessário.

- Vector foi introduzido na biblioteca padrão do C++ (STL - Standard Template Library) juntamente com outras classes de contêineres na versão C++98.

---

-Funciona alocando memória de forma dinâmica.
- Ao criar um vector, um bloco de memória é reservado para armazenar um número inicial de elementos. 
- Conforme mais elementos são adicionados, mais memória é alocada conforme necessário. 
- Da mesma forma, quando elementos são removidos, a memória alocada para eles é liberada.

Essa flexibilidade torna o vector uma opção conveniente para lidar com coleções de dados que podem crescer ou encolher ao longo do tempo.

---

O vector fornece métodos e operadores que simplificam a manipulação e o acesso aos elementos. Isso inclui a capacidade de acessar elementos por índice, adicionar elementos no final, inserir elementos em uma posição específica, remover elementos e muito mais.

Os elementos armazenados em um vector podem ser acessados por meio de seus índices, que começam em zero. O acesso a elementos de um vector é tão rápido quanto o acesso a elementos de um array.

O vector também fornece vários métodos para manipular os elementos armazenados nele. Alguns desses métodos são:

- push_back(): adiciona um novo elemento ao final do vector
- pop_back(): remove o último elemento do vector
- insert(): insere um ou mais elementos em uma posição especificada no vector
- erase(): remove um ou mais elementos de uma posição especificada no vector
- clear(): remove todos os elementos do vector
- size(): retorna o número de elementos atualmente armazenados no vector
- capacity(): retorna o número máximo de elementos que podem ser armazenados no vector sem alocar mais memória

O vector também suporta vários tipos de inicialização e construção, incluindo inicialização por cópia, inicialização por lista, construção de vetor vazio, construção de vetor com tamanho específico e construção de vetor com valores padrão.

O vector é uma estrutura de dados extremamente útil em C++, porque fornece uma maneira fácil e eficiente de armazenar e manipular sequências dinâmicas de elementos. Ele é frequentemente usado em programas que lidam com grandes quantidades de dados, como aplicativos de processamento de imagem, aplicativos de análise de dados e aplicativos de jogos.
