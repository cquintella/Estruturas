---
marp: true
---

# Introdução à Linguagem C++

Professor: Carlos Alvaro Quintella
5/6/2023

---

## O que é C++?

- Linguagem de programação de alto nível
- Criada com base na linguagem C
- Suporta programação orientada a objetos
- Usado em sistemas operacionais, jogos, aplicações desktop, etc.

---

## Hello World em C++

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

---

## Tipos de Dados Básicos

- `int` - inteiro
- `float` - ponto flutuante
- `double` - ponto flutuante de precisão dupla
- `char` - caractere
- `bool` - booleano

---

## Estruturas de Controle de Fluxo

- `if`/`else` - estrutura condicional
- `for` - laço de repetição com número fixo de iterações
- `while` - laço de repetição com condição de parada
- `do/while` - laço de repetição com condição de parada no final

---

## Funções

- Bloco de código com um nome
- Pode receber argumentos e retornar um valor
- Permite reutilização de código
- Exemplo:

```cpp
int square(int x) {
    return x * x;
}
```

---

## Programação Orientada a Objetos

- Encapsulamento
- Herança
- Polimorfismo
- Exemplo:

```cpp
class Shape {
public:
    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }
private:
    double radius_;
};
```

---

## Timeline do C++ ##

Claro! Aqui está uma tabela em Markdown com as principais versões e revisões do C++:

| Versão | Ano | Características Adicionadas |
|--------|-----|---------------------------|
| C++ 1.0 | 1985 | Classes, herança, polimorfismo, encapsulamento |
| C++ 2.0 | 1989 | Exceções, templates |
| C++ 3.0 | 1991 | Tipos de dados abstratos, gerenciamento automático de memória, classes de modelos |
| C++ 4.0 | 1994 | Namespaces, especificação de tipos em templates |
| C++ 11 | 2011 | Lambdas, tipos numéricos, bibliotecas padrão, threads, move semantics |
| C++ 14 | 2014 | Expressões constantes, inicialização de classe simplificada, variáveis auto |
| C++ 17 | 2017 | Fold expressions, namespaces aninhados, operadores de atribuição compostos para classes, if constexpr |
| C++ 20 | 2020 | Módulos, conceitos, expressões assíncronas, operador <=>, inicialização de construtor delegado, biblioteca padrão de tempo |
| C++ 23 | 2023 | [C++ 23 Vivo e Chutando](https://www.youtube.com/watch?v=5kjvkOWhFlk) |

---

## Relevância ##

[TIOBE](https://www.tiobe.com/tiobe-index/cplusplus/)
[Ranking](https://distantjob.com/blog/programming-languages-rank/)

---

## Conclusão

- C++ é uma linguagem poderosa e versátil
- Suporta programação procedural, orientada a objetos e genérica
- Amplamente utilizada em vários campos, incluindo jogos, sistemas operacionais e aplicativos de desktop
- Possui uma curva de aprendizado íngreme, mas pode valer a pena para projetos complexos
