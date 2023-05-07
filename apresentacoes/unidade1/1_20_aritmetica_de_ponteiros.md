---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
---

<!-- _class: lead -->


# Aritmética de Ponteiros #

Professor: Carlos Alvaro Quintella

---

A aritmética de ponteiros é um recurso da linguagem C que permite a manipulação de endereços de memória através de operações matemáticas realizadas com ponteiros. A aritmética de ponteiros é especialmente útil quando se trabalha com arrays e estruturas de dados como listas, pilhas e filas.

---

Existem quatro operações básicas na aritmética de ponteiros:

- Adição: É possível adicionar um inteiro a um ponteiro. O resultado é um novo ponteiro que aponta para uma posição de memória deslocada em relação ao ponteiro original. O deslocamento é calculado multiplicando o valor inteiro pelo tamanho do tipo de dado apontado pelo ponteiro.

Exemplo:

````c
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr; // p aponta para o primeiro elemento do array (arr[0])
p = p + 3; // p agora aponta para o quarto elemento do array (arr[3])

````

---

- Subtração: É possível subtrair um inteiro de um ponteiro, resultando em um novo ponteiro que aponta para uma posição de memória deslocada em relação ao ponteiro original. O deslocamento é calculado de forma semelhante à adição, porém na direção oposta.

Exemplo:

````c

int arr[5] = {1, 2, 3, 4, 5};
int *p = arr + 4; // p aponta para o último elemento do array (arr[4])
p = p - 2; // p agora aponta para o terceiro elemento do array (arr[2])
````

---

- Diferença entre ponteiros: É possível calcular a diferença entre dois ponteiros do mesmo tipo. O resultado é um inteiro que representa o número de elementos entre os dois ponteiros.

Exemplo:

````c
int arr[5] = {1, 2, 3, 4, 5};
int *p1 = arr;      // p1 aponta para o primeiro elemento do array (arr[0])
int *p2 = arr + 4;  // p2 aponta para o último elemento do array (arr[4])
int diff = p2 - p1; // diff é igual a 4, pois há 4 elementos entre p1 e p2
````

---

- Incremento e decremento: Os operadores de incremento (++) e decremento (--) também podem ser utilizados com ponteiros, avançando ou retrocedendo a posição de memória apontada.

Exemplo:

````c
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr; // p aponta para o primeiro elemento do array (arr[0])
p++;          // p agora aponta para o segundo elemento do array (arr[1])
p--;          // p volta a apontar para o primeiro elemento do array (arr[0])

````

---

* É importante ressaltar que a aritmética de ponteiros leva em consideração o tamanho do tipo de dado apontado pelo ponteiro.

* Portanto, ao adicionar ou subtrair um valor de um ponteiro, o deslocamento é ajustado automaticamente com base no tamanho do tipo de dado. 

* Por exemplo, se você estiver trabalhando com um ponteiro para int e incrementar o ponteiro, ele avançará o número de bytes necessários para armazenar um inteiro (geralmente 4 bytes em sistemas modernos).

---

## AVISO ##

A aritmética de ponteiros é uma ferramenta poderosa e flexível em C, mas é essencial utilizá-la com cuidado, pois erros na manipulação de ponteiros podem levar a comportamentos indefinidos, como acessar áreas de memória não permitidas ou corromper dados.
