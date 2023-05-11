---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
---

<!-- _class: lead -->

# Novidades no Gerenciamento de Memória Dinâmica#

---

## No C ##

- O gerenciamento de memória dinâmica é feito por meio das funções malloc(), calloc(), realloc() e free().

- O programador é responsável por alocar e liberar a memória alocada.
    Não há verificação de limites de array.

- Acesso indevido a memória pode causar problemas sérios, como corrupção de dados e falhas de segurança.

---

## No C++ ##

**new** e **delete** são operadores em C++ usados para alocar e desalocar memória dinamicamente no heap. Eles são uma evolução das funções malloc e free do C, mas oferecem melhorias significativas em termos de segurança e facilidade de uso.

--

**new**: **O operador new aloca memória no heap para armazenar um objeto do tipo especificado e retorna um ponteiro para o objeto**. Ele também chama o construtor do objeto para inicializá-lo. Isso é útil quando você precisa alocar memória dinamicamente, por exemplo, quando o tamanho do objeto é determinado em tempo de execução ou quando você precisa alocar recursos que persistem além do escopo da função.

---

Exemplo:

```c++

int* p = new int(10); // Aloca um novo inteiro no heap e inicializa com o valor 10.

```

---

**delete**: **O operador delete libera a memória alocada pelo operador new e chama o destrutor do objeto**. É importante liberar a memória alocada dinamicamente para evitar vazamentos de memória.

Exemplo:

```c++
delete p; // Libera a memória apontada por p.

```

---

- Em C, o programador tem mais controle sobre o gerenciamento de memória, mas isso aumenta o risco de erros e bugs.
- Em C++, o gerenciamento de memória é mais seguro e conveniente, mas há uma sobrecarga de processamento adicional em tempo de execução.
-O uso de contêineres em C++ pode ajudar a evitar erros de acesso a memória e tornar o código mais legível e fácil de manter.

---

Contêineres são objetos que armazenam um conjunto de outros objetos, geralmente com o objetivo de facilitar o acesso, a busca e a manipulação desses objetos de uma maneira organizada e eficiente. Em programação, é comum encontrar contêineres em diversas linguagens, incluindo C++ e Java, que oferecem diversas implementações de contêineres para diferentes necessidades e casos de uso. Os contêineres podem ser de diferentes tipos, como listas, vetores, filas, pilhas, árvores, mapas e conjuntos, entre outros

---

Alguns exemplos de contêineres em C++ são:

- std::vector: uma sequência dinâmica de elementos
- std::deque: uma sequência dinâmica de elementos que permite inserção e remoção eficiente tanto no início quanto no final
- std::list: uma lista duplamente encadeada de elementos
- std::set: uma coleção ordenada de elementos únicos
- std::map: uma coleção associativa de pares chave-valor, onde as chaves são exclusivas

---

- std::unordered_set: uma coleção não ordenada de elementos únicos
- std::unordered_map: uma coleção associativa não ordenada de pares chave-valor, onde as chaves são exclusivas