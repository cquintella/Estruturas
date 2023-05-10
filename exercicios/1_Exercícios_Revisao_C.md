---
marp: true
author: carlos.quintella@uva.br
paginate: true
backgroundColor: white
theme: gaia
---

<!-- _class: lead -->

# Exercícios em C #

1) Declaração de variáveis e Conversão de tipos:
a) Escreva um programa que leia dois números inteiros e imprima a soma entre eles.
b) Escreva um programa que leia um número inteiro e um número real e imprima a multiplicação entre eles.
c) Escreva um programa que leia um caractere e imprima o valor correspondente na tabela ASCII.

---

2) Uso de for:
a) Escreva um programa que imprima os números pares de 0 a 20 utilizando um loop for.
b) Escreva um programa que imprima a soma dos números ímpares de 1 a 99 utilizando um loop for.

---

3) Leitura de dados do teclado:
a) Escreva um programa que leia um número inteiro e verifique se ele é positivo, negativo ou zero.
b) Escreva um programa que leia três valores inteiros e imprima o maior e o menor deles.

---

4) Escrita em arquivos texto:
a) Escreva um programa que leia o nome de um arquivo de texto e uma string e escreva essa string no final do arquivo.
b) Escreva um programa que leia o nome de um arquivo de texto e imprima o conteúdo desse arquivo na tela.

Obs: Os exercícios podem ser adaptados para a necessidade e nível dos alunos.


---

## Resolução ##

### 1 a ###

```c
#include <stdio.h>

int main() {
  int num1, num2, soma;
  
  printf("Digite dois números inteiros:\n");
  scanf("%d %d", &num1, &num2);
  
  soma = num1 + num2;
  
  printf("A soma entre %d e %d é: %d\n", num1, num2, soma);
  
  return 0;
}
```

---

## 1.b ##

```c
#include <stdio.h>

int main() {
  int num1;
  float num2, mult;
  
  printf("Digite um número inteiro e um número real:\n");
  scanf("%d %f", &num1, &num2);
  
  mult = num1 * num2;
  
  printf("A multiplicação entre %d e %.2f é: %.2f\n", num1, num2, mult);
  
  return 0;
}
```

---

## 1.c ##

```c
#include <stdio.h>

int main() {
  char caractere;
  
  printf("Digite um caractere:\n");
  scanf("%c", &caractere);
  
  printf("O valor correspondente na tabela ASCII é: %d\n", caractere);
  
  return 0;
}
```

---

## 2.a ##

```c
#include <stdio.h>

int main() {
  int num1, num2, soma;
  
  printf("Digite dois números inteiros:\n");
  scanf("%d %d", &num1, &num2);
  
  soma = num1 + num2;
  
  printf("A soma entre %d e %d é: %d\n", num1, num2, soma);
  
  return 0;
}
```

---

## 2.b ##

```c
#include <stdio.h>

int main() {
  int num1;
  float num2, mult;
  
  printf("Digite um número inteiro e um número real:\n");
  scanf("%d %f", &num1, &num2);
  
  mult = num1 * num2;
  
  printf("A multiplicação entre %d e %.2f é: %.2f\n", num1, num2, mult);
  
  return 0;
}

```

---

## 2.c ##

```c
#include <stdio.h>

int main() {
  char caractere;
  
  printf("Digite um caractere:\n");
  scanf("%c", &caractere);
  
  printf("O valor correspondente na tabela ASCII é: %d\n", caractere);
  
  return 0;
}

```

