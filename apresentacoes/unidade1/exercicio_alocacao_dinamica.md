---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
---

<!-- _class: lead -->

1) Crie uma variável que é um ponteiro para uma área de memória que tem um inteiro com valor 1999.

---

```cpp
int* ptr = (int*) malloc(sizeof(int));
*ptr = 1999;
```

---

2) Aloque uma área de memória, grave 2023 e imprima o valor e depois desaloque a memória.

---

```cpp
int* ptr = (int*) malloc(sizeof(int));
*ptr = 2023;
std::cout << *ptr << std::endl;
free(ptr);
```

---

3) Aloque área de memória para um vetor de 3 valores inteiros e grave a data corrente. Desaloque a memória ao sair do programa.

---

```cpp
int* ptr = (int*) malloc(3 * sizeof(int));
ptr[0] = 10;
ptr[1] = 5;
ptr[2] = 2023;
free(ptr);
```

---

4) Crie uma função que recebe um ponteiro para uma área de memória que contém um vetor de caracteres e imprime seu conteúdo.

---

```cpp
void print_string(char* ptr) {
    std::cout << ptr << std::endl;
}
```

---

5) Crie uma função que recebe dois ponteiros para áreas de memória que contém dois inteiros e troca seus valores.

---

```cpp
void swap_integers(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

---

6) Crie uma função que recebe um ponteiro para uma área de memória que contém um vetor de inteiros e o tamanho do vetor, e retorna a soma dos valores do vetor.

---

```cpp
int sum_array(int* ptr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += ptr[i];
    }
    return sum;
}
```

---

7) Crie uma função que recebe um ponteiro para uma área de memória que contém um vetor de inteiros e o tamanho do vetor, e retorna o valor máximo do vetor.

---

```cpp
int max_array(int* ptr, int size) {
    int max = ptr[0];
    for (int i = 1; i < size; i++) {
        if (ptr[i] > max) {
            max = ptr[i];
        }
    }
    return max;
}
```
