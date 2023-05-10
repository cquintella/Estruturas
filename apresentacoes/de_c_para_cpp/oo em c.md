---
marp: true
author: carlos.quintella@uva.br
backgroundColor: black
paginate: true
theme: gaia
---

<!-- class: invert -->
<!-- _class: lead -->
<!-- _color: white -->

# Orientação à objetos em C++ #

---

## Paradigma da Programação Orientada a Objetos ##

* Utiliza objetos e classes
* Representa e organiza dados e funcionalidades
* Promove reutilização e modularidade de código
* Princípios fundamentais: encapsulamento, herança, polimorfismo e abstração

[Video](https://www.youtube.com/watch?v=NFMeZls5DQk)
[video](https://www.youtube.com/watch?v=QY0Kdg83orY)

<!--> A orientação a objetos é um paradigma de programação que utiliza objetos e classes para representar e organizar os dados e as funcionalidades de um programa. <!-->

---

## Definição de Paradigma ##

* Conjunto compartilhado de crenças, valores, técnicas e abordagens
* Molda e orienta pensamento, resolução de problemas e abordagens a desafios
* Estruturas conceituais ou modelos mentais
Influencia a percepção da realidade
* Fornece padrões e diretrizes para a prática
* Estabelece limites do que é aceitável ou possível em um campo específico

<!--
_Um paradigma é um conjunto de crenças, valores, técnicas e abordagens compartilhadas por uma comunidade que molda e orienta a forma como os membros dessa comunidade pensam, resolvem problemas e abordam novos desafios. Em um contexto mais amplo, os paradigmas servem como estruturas conceituais ou modelos mentais que influenciam a percepção da realidade, fornecem padrões e diretrizes para a prática e estabelecem os limites do que é considerado aceitável ou possível em um campo específico_.
-->

---

* C++ é uma linguagem de programação que suporta a orientação a objetos, permitindo que os desenvolvedores criem soluções modulares, reutilizáveis e escaláveis.

---

Os principais conceitos da orientação a objetos em C++ incluem:

---

## Conceito de Classe ##

* Modelo ou projeto para objetos
* Define propriedades (atributos) e comportamentos (métodos)
* Comum a um grupo de objetos
* Semelhante a tipos para variáveis
* Serve como molde para criar objetos específicos

<!--
Classe: Uma classe é um modelo ou um projeto que define as propriedades (atributos) e comportamentos (métodos) comuns a um grupo de objetos.

assim como os tipos para a variáveis, as classes servem como um molde para criar objetos específicos.
-->
---

# Conceito de Objeto #

* Instância de uma classe
Representa uma entidade específica
* Possui atributos e comportamentos definidos pela classe
* Estado próprio determinado pelos valores dos atributos

<!--
Objeto: Um objeto é uma instância de uma classe. Ele representa uma entidade específica que possui atributos e comportamentos definidos pela classe.

Cada objeto tem seu próprio estado, que é determinado pelos valores de seus atributos.
-->
---

## Princípios da OO ##

* Encapsulamento
  * Agrupa dados e funções relacionadas
  * Protege a integridade dos dados
* Herança
  * Criação de novas classes com base em classes existentes
  * Reutilização e extensão de código
* Polimorfismo
  * Tratamento de diferentes objetos como um tipo comum
  * Flexibilidade e reutilização de código
  
---

* Abstração
  * Simplifica problemas complexos
  * Foco nas características essenciais
  
<!--
Encapsulamento, herança e polimorfismo, abstração são parte dos principais princípios da programação orientada a objetos (OOP).

Eles são usados para organizar e estruturar o código de maneira mais eficiente, promovendo a reutilização, a modularidade e a flexibilidade
-->

---

### Encapsulamento ###

* Oculta detalhes de implementação
* Exposição de uma interface pública
* Uso de modificadores de acesso (public, private, protected)
* Controle de visibilidade de atributos e métodos
* Aumenta modularidade e manutenibilidade do código

<!--
Encapsulamento: O encapsulamento é a prática de ocultar os detalhes de implementação de uma classe e expor apenas uma interface pública.

Isso é feito usando modificadores de acesso (public, private e protected) para controlar a visibilidade de atributos e métodos. O encapsulamento ajuda a aumentar a modularidade e a manutenibilidade do código.
-->

---

### Herança ###

A herança é um mecanismo que permite criar uma nova classe a partir de uma classe existente. A nova classe (subclasse) herda os atributos e métodos da classe base (superclasse) e pode adicionar ou modificar atributos e métodos conforme necessário. A herança promove a reutilização de código e a organização hierárquica de classes.

---

### Polimorfismo ###

O polimorfismo é a capacidade de tratar diferentes objetos como se fossem do mesmo tipo. Em C++, o polimorfismo pode ser realizado através da herança e do uso de ponteiros e referências de classe base para acessar objetos de subclasses. Isso permite que um único código manipule diferentes tipos de objetos de maneira genérica e extensível.

---

## Exemplo ##

```cpp
#include <iostream>

// Definição da classe Animal (classe base)
class Animal {
public:
    void comer() {
        std::cout << "O animal está comendo." << std::endl;
    }
};

// Definição da classe Cachorro, que herda de Animal (subclasse)
class Cachorro : public Animal {
public:
    void latir() {
        std::cout << "O cachorro está latindo." << std::endl;
    }
};

int main() {
    // Criando um objeto da classe Cachorro
    Cachorro dog;

    // Acessando métodos herdados da classe base Animal
    dog.comer();

    // Acessando métodos da classe Cachorro
    dog.latir();

    return 0;
}
```

---

### Abstração ###

A abstração é a capacidade de simplificar problemas complexos, representando-os com modelos mais simples e genéricos.

Isso permite que os desenvolvedores se concentrem nas características essenciais de um objeto ou sistema, ignorando os detalhes irrelevantes ou de baixo nível.

A abstração é fundamental na OOP, pois ajuda a organizar o código de maneira mais eficiente e a criar interfaces de alto nível que são mais fáceis de entender e usar.

---

### Composição ### 

A composição é um princípio que permite criar objetos complexos combinando objetos mais simples. Em vez de herdar diretamente de uma classe base, a composição permite que você reutilize e estenda a funcionalidade de outras classes, incluindo-as como membros de uma nova classe. A composição pode ser usada como uma alternativa à herança em muitos casos e oferece uma maior flexibilidade e modularidade ao projetar sistemas de software.

---

### Princípios Adicionais ###

**Princípio da responsabilidade única (SRP)**: Este princípio, que faz parte dos princípios SOLID, afirma que uma classe deve ter apenas uma razão para mudar, ou seja, deve ter apenas uma responsabilidade. Seguir esse princípio leva a um design de classe mais coeso e ajuda a evitar classes inchadas e difíceis de manter.

**Princípio aberto/fechado (OCP)**: Outro princípio SOLID, o princípio aberto/fechado, afirma que as classes devem ser abertas para extensão, mas fechadas para modificação. Isso significa que você deve ser capaz de adicionar novas funcionalidades a uma classe sem alterar o código existente. A herança e as interfaces são frequentemente usadas para implementar o OCP.

**Princípio da substituição de Liskov (LSP)**: O LSP, também parte dos princípios SOLID, afirma que os objetos de uma classe derivada devem ser capazes de substituir os objetos da classe base sem afetar a correção do programa. Seguir esse princípio garante que a herança seja usada corretamente, preservando a relação "é um" entre a classe base e a classe derivada.

**Princípio da segregação de interfaces (ISP)**: O ISP, outro princípio SOLID, sugere que muitas interfaces específicas são melhores do que uma interface geral. Classes que não precisam de todas as funcionalidades de uma interface geral não devem ser forçadas a implementá-las. Seguir esse princípio ajuda a evitar a dependência de métodos desnecessários e promove a modularidade e a flexibilidade do código.

**Princípio da inversão de dependência (DIP)**: O último princípio SOLID, o DIP, afirma que as classes de alto nível não devem depender diretamente das classes de baixo nível. Em vez disso, ambas devem depender de abstrações. Isso promove a desacoplamento e facilita a manutenção e a escalabilidade do código.

---

Slide: Construtor e Destrutor em C++

## Construtor e Destrutor

- Construtor e destrutor são métodos especiais de uma classe em C++.
- Eles são responsáveis por inicializar e destruir objetos da classe.
- O construtor é chamado automaticamente quando o objeto é criado, enquanto o destrutor é chamado automaticamente quando o objeto é destruído.
- O construtor tem o mesmo nome da classe, enquanto o destrutor tem o nome da classe precedido pelo caractere ~.

### Construtor

- O construtor é responsável por inicializar os membros de dados da classe.
- Ele pode receber parâmetros ou não.
- Se nenhum construtor é declarado, o compilador fornece um construtor padrão.
- Exemplo:

```cpp
class Exemplo {
public:
  Exemplo(int x, int y) : m_x(x), m_y(y) {}  // Construtor com parâmetros

private:
  int m_x;
  int m_y;
};
```

### Destrutor

- O destrutor é responsável por liberar a memória alocada para os membros do objeto.
- Ele não recebe parâmetros e não tem valor de retorno.
- Se nenhum destrutor é declarado, o compilador fornece um destrutor padrão que não faz nada.
- Exemplo:

```cpp
class Exemplo {
public:
  ~Exemplo() { delete m_ponteiro; }  // Destrutor

private:
  int* m_ponteiro;
};
```

### Exemplo de uso

```cpp
int main() {
  Exemplo obj1(1, 2);     // Criação do objeto com construtor com parâmetros
  Exemplo obj2 = obj1;    // Criação do objeto com construtor de cópia
  Exemplo obj3;           // Criação do objeto com construtor padrão
  obj3 = obj1;            // Atribuição de objeto
  // ...
  return 0;               // Destruição dos objetos: obj1, obj2 e obj3
}
```

---

## Uso de Setters e Getters em C++

Setters e Getters são métodos utilizados para acessar e modificar os atributos de um objeto em C++.

Eles permitem que os atributos sejam protegidos, ocultando-os do código externo e proporcionando um melhor controle sobre a forma como são acessados e modificados.

## Vantagens e Motivação do uso de Setters e Getters

Encapsulamento: Setters e Getters permitem encapsular os atributos de um objeto, escondendo a implementação dos mesmos e tornando o código mais seguro e fácil de manter.

Validação de entrada: Setters permitem que os valores de entrada sejam validados antes de serem atribuídos a um atributo, evitando erros e garantindo que os valores sejam coerentes.

Flexibilidade: Getters permitem que os atributos sejam acessados de forma flexível, permitindo que a implementação interna do objeto seja alterada sem afetar o código que utiliza os atributos.

## Exemplo de Setters e Getters em C++

```cpp

class Carro {
  private:
    string marca;
    int ano;

  public:
    // Setter da marca
    void setMarca(string marca) {
        this->marca = marca;
    }

    // Getter da marca
    string getMarca() {
        return marca;
    }

    // Setter do ano
    void setAno(int ano) {
        if (ano >= 2000 && ano <= 2023) {
            this->ano = ano;
        } else {
            cout << "Ano inválido!" << endl;
        }
    }

    // Getter do ano
    int getAno() {
        return ano;
    }
};
```

---

## Conclusão

O uso de Setters e Getters é uma prática importante na programação orientada a objetos em C++.

Eles permitem encapsular os atributos de um objeto, fornecendo controle sobre a forma como são acessados e modificados.

Além disso, eles fornecem flexibilidade e validação de entrada, tornando o código mais seguro e fácil de manter.
