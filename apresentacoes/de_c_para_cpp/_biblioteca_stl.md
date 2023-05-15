---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
theme: gaia
---

<!-- _class: lead -->

# C++ : Bibliotecas #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

O C++ possui uma variedade de bibliotecas padrão disponíveis para o desenvolvimento de aplicações, entre elas:

- Standard Template Library (STL). que é um conjunto de classes que fazem uso de `template`, destinadas a fornecer estruturas de dados e funções de programação comuns, como listas, pilhas, arrays, etc.


Ela consiste em uma biblioteca de classes de contêineres, algoritmos e iteradores. Como uma biblioteca generalizada, seus componentes são parametrizados. Ter um conhecimento prático das classes template é um pré-requisito para trabalhar com a STL.

---

## Standard Vector ##

_std: "std" é a abreviação de "standard" e refere-se ao namespace padrão (standard namespace) da biblioteca padrão do C++ (C++ Standard Library)_.

STL: "STL" é a abreviação de "Standard Template Library" e é uma parte importante da biblioteca padrão do C++. A STL é uma coleção de classes e funções genéricas que fornecem estruturas de dados comuns (como vetores, listas e mapas) e algoritmos (como pesquisa, ordenação e manipulação de conjuntos) que podem ser usados com qualquer tipo de dado. A STL utiliza intensivamente recursos de templates para fornecer essa funcionalidade genérica.

---

## Standard Arrays ##

vector sao como arrays, mas aumentam de tamanho.

cuidado com ponteiros para arrays, pq alguma hora que incluir informacao o vetor pode ser copiado para outro espaco de memória e o ponteiro passa apontar para lixo.

---

## Links ##

[C++ COntainers](https://www.youtube.com/watch?v=6OoSgY6NVVk)