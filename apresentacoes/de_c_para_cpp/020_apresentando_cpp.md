---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
---

<!-- _class: lead -->

# Introdução à Linguagem C++ #

Professor: Carlos Alvaro Quintella
5/6/2023

---

## O que é C++? ##

- Linguagem de programação de alto nível
- Criada com base na linguagem C
- Suporta programação orientada a objetos
- Usado em sistemas operacionais, jogos, aplicações desktop, etc.

---

## Hello World em C++ ##

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello World";

    return 0;
}
```

---

## siga o Padrão ##

[**C++ Standard Guidelines**](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

- _This is a set of core guidelines for modern C++ (currently C++20 and C++17). The aim is to help C++ programmers to write simpler, more efficient, more maintainable code_.

---

## Tipos de Dados Básicos ##

- `int` - inteiro
- `float` - ponto flutuante
- `double` - ponto flutuante de precisão dupla
- `char` - caractere
- `bool` - booleano

---

## Dados compostos ##

Em C++, os tipos de dados compostos são aqueles que são formados a partir de outros tipos de dados. Eles incluem:

- `Arrays`: São um tipo de dado composto que pode armazenar uma coleção fixa de elementos do mesmo tipo. Por exemplo, você pode ter um array de inteiros, um array de floats, etc.

```cpp
    int myArray[5];  // Declaração de um array de inteiros
```

---

- `Strings`: Em C++, a string é um tipo de dado composto que é usada para armazenar e manipular sequências de caracteres.

```cpp
    std::string myString = "Hello, world!";
```

---

- `Structs` (Estruturas): São tipos de dados compostos que permitem agrupar variáveis de tipos diferentes sob o mesmo nome. Por exemplo, você pode ter uma struct chamada "Student" que contém uma string (para o nome) e um inteiro (para a idade).

```cpp
    struct Student {
        std::string name;
        int age;
    };
```

---

- `Classes`: São a base da programação orientada a objetos em C++. Uma classe é semelhante a uma struct, mas pode conter funções (chamadas métodos) além de dados. As classes também suportam conceitos como herança e encapsulamento.

```cpp
    class MyClass {
        int myVariable;

        public:
            void myMethod() {
                // código do método
            }
    };
```

- `Unions`: Uma union em C++ é um tipo especial de dado que permite armazenar diferentes tipos de dados no mesmo espaço de memória. Uma union pode ter vários membros, mas apenas um membro pode conter um valor a qualquer momento.

```cpp
    union MyUnion {
        int myInt;
        double myDouble;
    };
```

- `Enumerations` (enums): São tipos de dados compostos que consistem em conjuntos de constantes nomeadas, chamadas enumeradores.

```cpp
    enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
```

---

## Estruturas de Controle de Fluxo ##

- `if`/`if-else`/`if-else-if` - estrutura condicional
- `for` - laço de repetição com número fixo de iterações
- `while` - laço de repetição com condição de parada
- `do/while` - laço de repetição com condição de parada no final

---

## Comportamentos do for em C++ ##

O laço `for` é uma das estruturas mais utilizadas em C++ e pode apresentar diferentes comportamentos.

### Comportamento padrão ###

O comportamento padrão do `for` é repetir uma sequência de comandos um número específico de vezes.

```c++
for(int i=0; i<10; i++){
    //comandos a serem executados
}
```

---

### Comportamento tipo "foreach" ###

Em C++, também é possível utilizar o "for" como um "foreach", percorrendo os elementos de uma coleção.

```c++
int vetor[5] = {1, 2, 3, 4, 5};

for(int elemento : vetor){
    //comandos a serem executados para cada elemento
}
```

---

Nota: Diferente do C, o C++ tem a abrigatóriedade de definir o tipo de dado. Portanto o seguinte for é válido em C : `for(a=0;a<10;a++){};` e em C++ não é, precisando ter o tipo do contador declarado: `for(int a=0;a<10;a++){};`

---

## Funções ##

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

## Programação Orientada a Objetos ###

- Encapsulamento
- Herança
- Polimorfismo
- Exemplo:

---

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

---

| Versão | Ano | Características Adicionadas |
|--------|-----|---------------------------|
| C++ 4.0 | 1994 | Namespaces, especificação de tipos em templates |
| C++ 11 | 2011 | Lambdas, tipos numéricos, bibliotecas padrão, threads, move semantics |
| C++ 14 | 2014 | Expressões constantes, inicialização de classe simplificada, variáveis auto |
| C++ 17 | 2017 | Fold expressions, namespaces aninhados, operadores de atribuição compostos para classes, if constexpr |
---

| Versão | Ano | Características Adicionadas |
|--------|-----|---------------------------|
| C++ 20 | 2020 | Módulos, conceitos, expressões assíncronas, operador <=>, inicialização de construtor delegado, biblioteca padrão de tempo |
| C++ 23 | 2023 | [C++ 23 Vivo e Chutando](https://www.youtube.com/watch?v=5kjvkOWhFlk) |
| C++ 26 | 2026 | Programada |

---

## Relevância ##

- C++ é uma das linguagens de programação mais antigas e ainda é amplamente usada hoje em dia

- Embora tenha uma comunidade de usuários leais, o C++ enfrenta vários desafios para continuar relevante

---

### Desafio 1: Evolução Lenta ###

- A evolução do C++ é lenta em comparação com outras linguagens modernas. Mas isso tem mudado nos últimos anos.

- Novos recursos são adicionados a cada versão, mas a taxa de adoção é relativamente baixa.

- Isso significa que as versões mais antigas do C++ ainda são usadas e que muitos desenvolvedores não estão aproveitando os recursos mais recentes da linguagem. Mas isso não é um problema, afinal as madanças tendem a ser incrementais e código antigo continua funcionando.

---

### Desafio 2: Complexidade ###

- O C++ é conhecido por ser uma linguagem complexa e difícil de aprender.

- Embora isso tenha suas vantagens em termos de desempenho e controle, também torna a linguagem menos acessível a novos desenvolvedores.

- O desenvolvimento de ferramentas de programação mais amigáveis e intuitivas pode ajudar a tornar a linguagem mais fácil de aprender e usar.

> C++ não é pro fraco de coração.

---

### Desafio 3: Competição de outras linguagens ###

- Com a crescente popularidade de linguagens de programação modernas, como Python e JavaScript, o C++ enfrenta uma forte concorrência.

- Essas linguagens são frequentemente usadas para desenvolvimento de aplicativos de ponta a ponta e para análise de dados

- O C++ precisa continuar a provar seu valor em áreas como desenvolvimento de sistemas operacionais, jogos e outras aplicações de alto desempenho

---

### Gerenciamento de Bibliotecas ainda é chato de fazer ###

- Muitas linguagens tem ferramentas automatizadas ara gerenciar as bibliotecas, o npm para o Javascript com node, o cargo para o Rust.

- A Microsoft tem o [vcpkg](https://vcpkg.io/en/).
- [Conan](https://conan.io/) é outra opção

- Os dois são baseados no CMake.

---

[TIOBE](https://www.tiobe.com/tiobe-index/cplusplus/)
[Ranking](https://distantjob.com/blog/programming-languages-rank/)

---

## Conclusão ##

- C++ é uma linguagem poderosa e versátil
- Suporta programação procedural, orientada a objetos e genérica
- Amplamente utilizada em vários campos, incluindo jogos, sistemas operacionais e aplicativos de desktop
- Possui uma curva de aprendizado íngreme, mas pode valer a pena para projetos complexos
- O C++ continua sendo uma linguagem importante e relevante para muitos desenvolvedores

---

- Para continuar relevante no futuro, o C++ precisa evoluir para atender às necessidades dos desenvolvedores modernos, enquanto mantém suas vantagens em desempenho e controle
- A complexidade da linguagem também precisa ser abordada para torná-la mais acessível a novos desenvolvedores.

---

## Links ##

[Referencia do C++](https://en.cppreference.com/w/Main_Page)
