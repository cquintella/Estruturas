---
marp: true
---

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


Introduction: C++ is a statically-typed programming language, which means that variables must have a specific type assigned to them at compile time. C++ provides a variety of basic types that can be used to define variables and functions.

    Boolean type: The boolean type in C++ is used to represent logical values, such as true and false. It has a size of 1 byte and can be either true (non-zero) or false (zero).

    Character type: The character type in C++ is used to represent single characters, such as letters, digits, and punctuation marks. It has a size of 1 byte and can store 256 possible values.

    Integer types: C++ provides several integer types, including short, int, long, and long long. These types are used to represent whole numbers, both positive and negative. The size of an integer type depends on the platform and the compiler, but is typically either 2, 4, or 8 bytes.

    Floating-point types: C++ provides two floating-point types, float and double. These types are used to represent real numbers with varying degrees of precision and accuracy. The size of a floating-point type depends on the platform and the compiler, but is typically either 4 or 8 bytes.

    Void type: The void type in C++ represents the absence of a type. It is typically used to define functions that do not return a value.

    Enumerated types: Enumerated types in C++ are used to define a set of named constants. Each constant has an associated integer value, which can be used to represent the constant.

    Pointer types: Pointer types in C++ are used to represent memory addresses. They are used to manipulate and access data stored in memory.

    Conclusion: The basic types in C++ are essential building blocks for programming in C++. By understanding these types and how they are used, programmers can write more efficient and effective code.

In C++, the basic types are used to define variables and functions. They are typically used to store values in memory, perform arithmetic and logical operations, and control program flow. The basic types in C++ include:

1. Boolean: This type represents boolean values, which can be either true or false.

2. Character: This type represents single characters, such as letters, digits, and punctuation marks.

3. Integer: This type represents whole numbers, both positive and negative, with varying sizes depending on the number of bits used to represent them.

4. Floating-point: This type represents real numbers, with varying degrees of precision and accuracy depending on the number of bits used to represent them.

5. Double precision: This type represents double precision floating-point numbers, with greater precision and accuracy than the regular floating-point type.

6. Void: This type represents an absence of type, and is typically used to define functions that do not return a value.

7. Enumeration: This type represents a list of named constants, with each constant having a unique integer value.

8. Pointer: This type represents a memory address, which can be used to manipulate and access data stored in memory.

In C, the basic types are similar to those in C++, but with some differences in their sizes. The sizes of the basic types in C and C++ can vary depending on the implementation and the platform being used. However, the following table provides a general comparison of the sizes of the basic types in C and C++:

| Type         | Size in C  | Size in C++ |
|--------------|------------|-------------|
| Boolean      | Not defined | 1 byte      |
| Character    | 1 byte     | 1 byte      |
| Integer      | 2, 4 or 8 bytes | 2, 4 or 8 bytes |
| Floating-point | 4 or 8 bytes | 4 or 8 bytes |
| Double precision | Not defined | 8 bytes |
| Void         | Not defined | Not defined |
| Enumeration  | 2 or 4 bytes | 2 or 4 bytes |
| Pointer      | 2 or 4 bytes | 2, 4 or 8 bytes |

---

Note: that the sizes of the basic types in C and C++ can also be affected by the compiler options and the target platform.
The sizes of the basic types in C and C++ can vary depending on the compiler and the target platform being used. Different compilers may implement the basic types with different sizes, depending on their optimization goals, the underlying hardware architecture, and other factors.

For example, an integer in C or C++ can be represented with 2, 4, or 8 bytes, depending on the compiler and the target platform. A compiler may choose to use a smaller size for an integer type if it determines that the program's performance can be improved without sacrificing correctness or compatibility.

Similarly, the floating-point types in C and C++ can also vary in size, depending on the compiler and the target platform. A compiler may choose to use a smaller size for a floating-point type if it determines that the program's performance can be improved without sacrificing precision or accuracy.

Therefore, it is important to be aware that the sizes of the basic types in C and C++ can be affected by the compiler options and the target platform, and to write code that is compatible with different compilers and platforms. This can involve using platform-independent data types, such as int32_t and float64_t, or using platform-specific features, such as conditional compilation directives, to handle differences in the sizes of the basic types.

---

Note: In C and C++, `void` is a keyword that represents the absence of a type, and is often used to indicate that a function returns no value or that a pointer points to no specific type. It is not defined as a data type because it does not represent a value that can be stored or manipulated.

When we declare a function to return `void`, we are indicating that the function does not return a value, and any attempt to use the value returned by the function will result in a compilation error. Similarly, when we declare a pointer of type `void*`, we are indicating that the pointer can point to any data type, but we cannot directly dereference the pointer or manipulate the data pointed to without first casting it to a specific data type.

In summary, `void` is a keyword in C and C++ that represents the absence of a type and is used to indicate that a function returns no value or that a pointer points to no specific type. It is not defined as a data type because it does not represent a value that can be stored or manipulated directly.

---

A palavra-chave auto é utilizada em C++ para definir uma variável com um tipo de dado que é automaticamente inferido pelo compilador, com base no valor atribuído à variável.

```c++
auto x=10;

std::cout << typeid(x).name() << std::endl;
````
