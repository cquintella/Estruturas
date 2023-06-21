---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
backgroundColor: white
---

<!-- _class: lead -->

#  Interfaces #

- Professor: Carlos Alvaro Quintella.
- Última Revisão: 5/6/2023.

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

Em C++, o conceito de interface é geralmente implementado por meio de classes abstratas. Uma interface define um conjunto de métodos virtuais puros (também conhecidos como funções virtuais puras) que as classes derivadas devem implementar. Essa abstração permite que diferentes classes possam ser tratadas de forma uniforme por meio de sua interface comum.

---

Uma interface define apenas a estrutura e o contrato dos métodos que as classes derivadas devem implementar, mas não contém implementações concretas desses métodos. Por isso, uma classe que implementa uma interface é obrigada a fornecer uma implementação para todos os métodos virtuais puros definidos na interface.

A utilização de interfaces em herança de objetos permite criar hierarquias de classes que compartilham uma interface comum, mas fornecem implementações específicas para cada classe derivada. Isso permite que objetos de diferentes classes derivadas sejam tratados de forma polimórfica por meio de ponteiros ou referências à interface, permitindo a substituição dinâmica de objetos durante a execução.

---

exemplo para ilustrar como a interface é usada na herança de objetos:

```cpp
// Interface
class Animal {
public:
    virtual void emitSound() const = 0;  // Método virtual puro
};

// Classes derivadas
class Dog : public Animal {
public:
    void emitSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void emitSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

// Função genérica
void makeSound(const Animal& animal) {
    animal.emitSound();
}

int main() {
    Dog dog;
    Cat cat;

    makeSound(dog);  // Chamada polimórfica
    makeSound(cat);  // Chamada polimórfica

    return 0;
}
```

Nesse exemplo, a classe abstrata `Animal` define uma interface comum que exige que as classes derivadas implementem o método `emitSound()` como um método virtual puro. As classes `Dog` e `Cat` derivam da classe `Animal` e fornecem suas próprias implementações para o método `emitSound()`.

A função `makeSound()` é uma função genérica que aceita um objeto `Animal` (ou qualquer classe derivada de `Animal`) por referência à interface `Animal`. Isso permite que objetos de diferentes classes derivadas sejam passados ​​para essa função e chamem o método `emitSound()` correspondente de forma polimórfica.

Dessa forma, a utilização de interfaces em herança de objetos permite criar hierarquias de classes flexíveis e polimórficas, onde diferentes classes podem compartilhar uma interface comum, mas fornecer implementações específicas para cada uma delas. Isso facilita o tratamento uniforme de objetos diferentes e fornece uma maneira elegante de definir e garantir um contrato de implementação para as classes derivadas.
