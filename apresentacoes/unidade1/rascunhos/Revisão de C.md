---
marp: true
author: carlos.quintella@uva.br
background: white
paginate: true
footer: Estrutura de Dados
theme: gaia
---

<!-- _class: lead -->
![UVA 50% bg left:20%](https://uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

RASCUNHO

# Tipos Básicos em C++

## Introdução

* C++ é uma linguagem de programação com tipagem estática, o que significa que as variáveis devem ter um tipo específico atribuído a elas em tempo de compilação.

* C++ fornece uma variedade de tipos básicos que podem ser usados para definir variáveis e funções.

---

## Tipo booleano

O tipo booleano em C++ é usado para representar valores lógicos, como verdadeiro e falso. Ele tem um tamanho de 1 byte e pode ser verdadeiro (diferente de zero) ou falso (zero).

_Note: Que em C para usarmos booleaons era necessário incluir uma biblioteca adicional. Já no C++ faz parte do padrão da linguagem._

```c
int x =42;
bool truth = (x!=0)
;
```

---

## Tipo caractere

O tipo caractere em C++ é usado para representar caracteres únicos, como letras, dígitos e sinais de pontuação. Ele tem um tamanho de 1 byte e pode armazenar 256 valores possíveis.

_Nota_: NAda diferente do que já vimos no C.


---


## Tipos inteiros
C++ fornece vários tipos de inteiros, incluindo short, int, long e long long. Esses tipos são usados para representar números inteiros, tanto positivos quanto negativos. O tamanho de um tipo inteiro depende da plataforma e do compilador, mas geralmente é de 2, 4 ou 8 bytes.

---

## Tipos de ponto flutuante ##

C++ fornece dois tipos de ponto flutuante, float e double. Esses tipos são usados para representar números reais com graus variados de precisão e exatidão. O tamanho de um tipo de ponto flutuante depende da plataforma e do compilador, mas geralmente é de 4 ou 8 bytes.

---

## Tipo void ##

O tipo void em C++ representa a ausência de um tipo.

Em C++, `void` pode ser usado para:

1. Definir uma função que não retorna nada:

```cpp
void sayHello() {
  std::cout << "Hello!" << std::endl;
}
```

2. Usar um ponteiro `void` para representar um tipo desconhecido:

```cpp
void *ptr;
```

---

## Tipos enumerados

Tipos enumerados em C++ são usados para definir um conjunto de constantes nomeadas. Cada constante tem um valor inteiro associado, que pode ser usado para representar a constante.

```c++
enum Color {
  RED,
  GREEN,
  BLUE
};
```

## Tipos ponteiro
Tipos ponteiro em C++ são usados para representar endereços de memória. Eles são usados para manipular e acessar dados armazenados na memória.

## Conclusão
Os tipos básicos em C++ são blocos essenciais para programar em C++. Ao entender esses tipos e como eles são usados, os programadores podem escrever um código mais eficiente e eficaz.

---

## Tipos de variáveis no C++ ##

- C++ é uma linguagem de programação com tipagem estática, o que significa que as variáveis devem ter um tipo específico atribuído a elas em tempo de compilação

- Fornece uma variedade de tipos básicos que podem ser usados para definir variáveis e funções.

---

- Tipo booleano: O tipo booleano no C++ é usado para representar valores lógicos, como verdadeiro e falso. Ele tem um tamanho de 1 byte e pode ser verdadeiro (diferente de zero) ou falso (zero).

- Tipo caractere: O tipo caractere no C++ é usado para representar caracteres individuais, como letras, dígitos e sinais de pontuação. Ele tem um tamanho de 1 byte e pode armazenar 256 valores possíveis.

- Tipos inteiros: O C++ fornece vários tipos inteiros, incluindo short, int, long e long long. Esses tipos são usados para representar números inteiros, tanto positivos quanto negativos. O tamanho de um tipo inteiro depende da plataforma e do compilador, mas normalmente é 2, 4 ou 8 bytes.

---

- Tipos de ponto flutuante: O C++ fornece dois tipos de ponto flutuante, float e double. Esses tipos são usados para representar números reais com diferentes graus de precisão e acurácia. O tamanho de um tipo de ponto flutuante depende da plataforma e do compilador, mas normalmente é 4 ou 8 bytes.

- Tipo void: O tipo void no C++ representa a ausência de um tipo. Geralmente é usado para definir funções que não retornam um valor.

- Tipos de ponteiros: Tipos de ponteiros no C++ são usados para representar endereços de memória. Eles são usados para manipular e acessar dados armazenados na memória.

---

| Type         | Size in C  | Size in C++ |
|--------------|------------|-------------|
| Boolean      | Not defined | 1 byte      |
| Character    | 1 byte     | 1 byte      |
| Integer      | 2, 4 or 8 bytes | 2, 4 or 8 bytes |
| Floating-point | 4 or 8 bytes | 4 or 8 bytes |
| Double precision | Not defined | 8 bytes |
| Void         | Not defined | Not defined |
| Pointer      | 2 or 4 bytes | 2, 4 or 8 bytes |

---

## Tamanho dos tipos em C ##

- Os tamanhos dos tipos básicos em C e C++ podem ser afetados pelas opções do compilador e pela plataforma-alvo. Diferentes compiladores podem implementar os tipos básicos com diferentes tamanhos, dependendo de seus objetivos de otimização, da arquitetura de hardware subjacente e de outros fatores. Em geral o tamanho da palavra do computador determina o tamnho do int, para computadores de 16 bits, é 2 bytes, já os de 32 ou 64 bits é 4 bytes, pode ser até 8 bytes.

- Da mesma forma, os tipos de ponto flutuante em C e C++ também podem variar em tamanho, dependendo do compilador e da plataforma-alvo. Um compilador pode escolher usar um tamanho menor para um tipo de ponto flutuante se determinar que o desempenho do programa pode ser melhorado sem sacrificar a precisão ou acurácia.

---

## void ##

Em C e C++, `void` é uma palavra-chave que representa a ausência de um tipo e geralmente é usada para indicar que uma função não retorna valor ou que um ponteiro aponta para um tipo não específico. Não é definido como um tipo de dado porque não representa um valor que possa ser armazenado ou manipulado.

Quando declaramos uma função com retorno `void`, estamos indicando que a função não retorna um valor, e qualquer tentativa de usar o valor retornado pela função resultará em um erro de compilação. Da mesma forma, quando declaramos um ponteiro do tipo `void*`, estamos indicando que o ponteiro pode apontar para qualquer tipo de dado, mas não podemos desreferenciar diretamente o ponteiro ou manipular os dados apontados sem antes fazer um casting para um tipo de dado específico.

---

A palavra-chave auto é utilizada em C++ para definir uma variável com um tipo de dado que é automaticamente inferido pelo compilador, com base no valor atribuído à variável.

```c++
auto x=10;

std::cout << typeid(x).name() << std::endl;
````
