---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Curso de C++
theme: gaia
---

<!-- _class: lead -->
# Princípios de Design de Software OO #

## SOLID ##

SOLID é um acrônimo que representa um conjunto de princípios de design de software que promovem a construção de código limpo, modular e sustentável. Esses princípios foram formulados por Robert C. Martin (também conhecido como Uncle Bob) e são amplamente aceitos e aplicados no desenvolvimento de software.

---

1. **S - Princípio da Responsabilidade Única (Single Responsibility Principle)**: Cada classe deve ter uma única responsabilidade e motivo para mudar. Isso promove coesão e facilita a manutenção, evitando que uma classe tenha muitas responsabilidades.

---

2. **O - Princípio do Aberto/Fechado (Open/Closed Principle)**: As entidades do software devem estar abertas para extensão, mas fechadas para modificação. Isso significa que você pode adicionar novos comportamentos sem modificar o código existente.

---

3. **L - Princípio da Substituição de Liskov (Liskov Substitution Principle)**: Os objetos de uma classe derivada devem poder ser substituídos pelos objetos da classe base sem alterar a corretude do programa. Isso garante que a herança seja usada corretamente, sem violar a semântica do código.

---

4. **I - Princípio da Segregação de Interfaces (Interface Segregation Principle)**: As interfaces devem ser específicas para os clientes que as utilizam. Evita interfaces "gordas" que forçam os clientes a dependerem de funcionalidades que não utilizam.

---

5. **D - Princípio da Inversão de Dependência (Dependency Inversion Principle)**: Módulos de alto nível não devem depender de módulos de baixo nível. Ambos devem depender de abstrações. Isso permite a inversão do controle e promove a modularidade e a reutilização.

A aplicação desses princípios SOLID auxilia na construção de código flexível, extensível e de fácil manutenção. Eles visam reduzir acoplamento, aumentar coesão, promover a reusabilidade e facilitar a evolução e o teste de software.

---

## Tipos de relações entre objetos ##

### Associação ###

- Uma associação representa uma relação entre dois ou mais objetos, onde eles estão conectados ou interagem entre si.
- Pode ser uma relação simples sem dependência ou comportamento específico.
- Exemplo: Um Professor está associado a vários objetos Aluno.

### Agregação ###

- Agregação é uma forma especializada de associação, onde um objeto representa um todo e contém outros objetos como suas partes.
- As partes podem existir independentemente do todo e podem ser compartilhadas entre vários objetos completos.
- Exemplo: Uma Universidade agrega vários objetos Departamento.

### Composição ###

- Composição é uma forma mais forte de agregação, onde as partes não podem existir sem o todo. O todo assume a responsabilidade por criar e gerenciar suas partes.
- Se o todo for destruído, suas partes também serão destruídas.
- Exemplo: Um Carro é composto por um Motor, Rodas e outros componentes.

### Dependência ###

- Dependência representa uma relação onde um objeto depende de outro objeto, geralmente para sua funcionalidade ou comportamento.

---

```cpp

#include <iostream>

// Classe FileWriter
class FileWriter {
public:
    void write(const std::string& message) {  //a declaração void write(const std::string& message) indica que a função write não irá modificar o objeto FileWriter ou a string message.
        std::cout << "Escrevendo mensagem no arquivo: " << message << std::endl;
    }
};

// Classe Logger que depende de FileWriter
class Logger {
private:
    FileWriter* fileWriter;

public:
    Logger(FileWriter* writer) : fileWriter(writer) {} // Injeção de dependencia

    void log(const std::string& message) {
        fileWriter->write(message);
    }
};

int main() {
    FileWriter writer;
    Logger logger(&writer);

    logger.log("Mensagem de log.");

    return 0;
}
```

---

### Realização ###
  
- Realização representa a implementação de uma interface ou o cumprimento de um contrato definido por outra classe ou interface.

- É usado para estabelecer uma relação entre uma classe e uma interface que ela implementa.

- **Exemplo**: Uma classe Círculo realiza a interface Forma.

---

```cpp
#include <iostream>

// Interface Shape
class Shape {
public:
    virtual void draw() = 0; // Método puro virtual
};

// Classe Circle que realiza a interface Shape
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Desenhando um círculo." << std::endl;
    }
};

// Classe Rectangle que realiza a interface Shape
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Desenhando um retângulo." << std::endl;
    }
};

int main() {
    Circle circle;
    circle.draw();

    Rectangle rectangle;
    rectangle.draw();

    return 0;
}
```
