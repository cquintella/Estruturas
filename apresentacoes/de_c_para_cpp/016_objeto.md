---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
backgroundColor: white
---

<!-- _class: lead -->

# Usando Objetos em C++ #

- Professor: Carlos Alvaro Quintella.
- Última Revisão: 5/6/2023.

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

## Modificadores de acesso #

os modificadores de acesso (private, public e protected) são utilizados para controlar o acesso aos componentes de uma classe. Eles definem as permissões de acesso dos membros da classe para outras partes do código.

por defualt todos os atributos são `private`.

---

### private ###

- Os membros declarados como private são acessíveis somente dentro da própria classe.
- Isso significa que eles não podem ser acessados por outras classes, funções ou objetos fora da classe em que foram declarados.
- Os membros private são frequentemente usados para armazenar e manipular dados internos da classe, ocultando-os do mundo exterior.
- Por padrão, se nenhum modificador de acesso for especificado, os membros de uma classe são considerados private.

---

### public ###

- Os membros declarados como public são acessíveis por qualquer parte do código, incluindo outras classes, funções e objetos.
- Isso significa que eles podem ser acessados e utilizados livremente fora da classe em que foram declarados.
- Os membros public geralmente são usados para definir a interface pública da classe, fornecendo métodos e atributos que podem ser acessados externamente.

---

### protected ###

- Os membros declarados como protected têm um comportamento intermediário entre private e public.
- Os membros protected são acessíveis dentro da própria classe, bem como pelas classes derivadas (subclasses) da classe base (quando existe herança).
- Isso significa que os membros protected não podem ser acessados por funções ou objetos fora da hierarquia de herança.
- Os membros protected são frequentemente usados para fornecer acesso controlado às subclasses, permitindo que elas herdem e manipulem os dados internos da classe base.

---

Ao declarar o nome de uma classe a gente usa a primeira letra maiúscula.

no arquivo `.h` ou `.hpp` vai somente a classe, os atributos e o protótipo dos métodos.

- a implementação do método vai no arquivo .cpp correnpondente.
- Se vc usar templates vai precisar colocar a implementação dentro do headr.

---

```cpp
class NomeClasse {
private:
    int atributoPrivate;      // Acessível somente dentro da classe

public:
    int atributoPublic;       // Acessível por qualquer parte do código

protected:
    int atributoProtected;    // Acessível pela classe e suas subclasses
};

```

---

## Métodos Especiais ##

### Construtor e Destrutor ###

- Construtor e destrutor são métodos especiais de uma classe em C++.
- Eles são responsáveis por inicializar e destruir objetos da classe.
- O construtor é chamado automaticamente quando o objeto é criado, enquanto o destrutor é chamado automaticamente quando o objeto é destruído.
- O construtor tem o mesmo nome da classe, enquanto o destrutor tem o nome da classe precedido pelo caractere `~`.

---

#### Construtor ###

- O construtor é responsável por inicializar os membros de dados da classe em um novo objeto criado.
- Ele pode receber parâmetros ou não.
- Se nenhum construtor é declarado, o compilador fornece um construtor padrão.
- **O construtor não define tipo de retorno**, nem mesmo void.
- O Construtor tem o mesmo nome da classe.
- **Construtor tem que ser público**.

---

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

---

O construtor padrão (**default constructor**) em C++ é um tipo especial de construtor que é gerado automaticamente pelo compilador se nenhum outro construtor for definido explicitamente na classe. Ele é chamado de "padrão" porque é usado para criar objetos sem a necessidade de passar argumentos para o construtor.

Características do construtor padrão:

- Sintaxe: O construtor padrão não possui parâmetros. Sua declaração segue a seguinte forma: Classe()

- Geração automática: Se nenhum construtor for definido na classe, o compilador fornecerá um construtor padrão implícito. Esse construtor é gerado automaticamente e permite criar objetos da classe sem especificar argumentos.

- Inicialização padrão: O construtor padrão é responsável por inicializar os membros da classe com valores padrão. Tipos primitivos, como int e float, são inicializados com zero. Objetos de classes, que possuem seus próprios construtores padrão, serão inicializados usando seus respectivos construtores padrão.

- Personalização: Se a classe possui membros ou variáveis ​​que precisam ser inicializados com valores específicos, é possível definir um construtor personalizado para realizar essa tarefa. Nesse caso, a geração automática do construtor padrão pelo compilador é suprimida.

---

```c
class Exemplo {
public:
    int numero;
    char caractere;
};

int main() {
    Exemplo objeto;  // Utilizando o construtor padrão

    // Acesso aos membros do objeto
    objeto.numero = 10;
    objeto.caractere = 'A';

    return 0;
}

```

---

#### Destrutor ####

- O destrutor é responsável por liberar a memória alocada para os membros do objeto.
- Ele não recebe parâmetros e não tem valor de retorno.
- Se nenhum destrutor é declarado, o compilador fornece um destrutor padrão que não faz nada.

---

- Exemplo:

```cpp
class Exemplo {
public:
  ~Exemplo() { delete m_ponteiro; }  // Destrutor

private:
  int* m_ponteiro;
};
```

---

### Exemplo de uso ###

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

### Setters e Getters ###

Setters e Getters são métodos utilizados para acessar e modificar os atributos de um objeto em C++.

- Eles permitem que os atributos sejam protegidos, ocultando-os do código externo e proporcionando um melhor controle sobre a forma como são acessados e modificados.

- Isso permite mais controle ao programa, garantindo que os devidos tratamentos serão dados dentro dos métodos. Eles fornecem flexibilidade e validação de entrada, tornando o código mais seguro e fácil de manter.

---

### Vantagens e Motivação do uso de Setters e Getters ###

- **Encapsulamento**: Setters e Getters permitem encapsular os atributos de um objeto, escondendo a implementação dos mesmos e tornando o código mais seguro e fácil de manter.

- **Validação de entrada**: Setters permitem que os valores de entrada sejam validados antes de serem atribuídos a um atributo, evitando erros e garantindo que os valores sejam coerentes.

- **Flexibilidade**: Getters permitem que os atributos sejam acessados de forma flexível, permitindo que a implementação interna do objeto seja alterada sem afetar o código que utiliza os atributos.

---

## Exemplo de Setters e Getters em C++ ##

```cpp

class Carro {
  private:
    string marca;
    int ano;

  public:
    void setMarca(string marca) { // Setter da marca
        this->marca = marca;
    }

    string getMarca() {  // Getter da marca
        return marca;
    }

    void setAno(int ano) {  // Setter do ano
        if (ano >= 2000 && ano <= 2023) {
            this->ano = ano;
        } else {
            cout << "Ano inválido!" << endl;
        }
    }

    int getAno() { // Getter do ano
        return ano;
    }
};
```

---

Exemplo:

```cpp
#include <iostream>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Método getter para o atributo 'name'
    std::string getName() const {
        return name;
    }

    // Método getter para o atributo 'age'
    int getAge() const {
        return age;
    }

    // Método que mostra informações do objeto Person
    void showInfo() const {
        std::cout << "Nome: " << name << std::endl;
        std::cout << "Idade: " << age << std::endl;
    }
};

int main() {
    Person person("John Doe", 30);

    std::cout << "Nome: " << person.getName() << std::endl;
    std::cout << "Idade: " << person.getAge() << std::endl;

    person.showInfo();

    return 0;
}
```

---

## Instanciação de um Objeto ##

Em C++, existem diferentes formas de instanciar um objeto. Aqui estão algumas das maneiras mais comuns:

- **Instanciação direta**: É a forma mais básica de criar um objeto e envolve a declaração e inicialização na mesma linha de código.

Sintaxe: Classe objeto;

- **Instanciação usando parênteses**: Também conhecida como instanciação por parênteses vazios, é usada para criar um objeto sem passar argumentos para o construtor.

Sintaxe: Classe objeto();

---

- **Instanciação com argumentos**: É usada para criar um objeto e passar argumentos para o construtor da classe.
Sintaxe: Classe objeto(argumentos);

- **Instanciação usando new**: Utiliza o operador new para criar um objeto dinamicamente no heap (espaço de memória dinamicamente alocado). Retorna um ponteiro para o objeto criado.
Sintaxe: Classe* objeto = new Classe();

- **Instanciação usando chaves (C++11 e versões posteriores)**: Utiliza a lista de inicialização usando chaves {} para inicializar os membros do objeto. Essa forma permite inicializar membros com valores específicos.

Sintaxe: Classe objeto{argumentos};

---

- **Instanciação com atribuição**: Cria um objeto e o atribui a uma variável existente.

Sintaxe: Classe objeto = outroObjeto;

No final você deve ou ter uma varável ou um pnteiro apontando para o Objeto criado.

---

### const em parâmetrode funções ou métodos ##

Existem alguns benefícios de usar o const em parâmetros de função:

- Documentação clara: Ao marcar um parâmetro como const, você está comunicando aos outros desenvolvedores que a função não irá modificar esse parâmetro. Isso torna o código mais legível e compreensível, facilitando o entendimento do comportamento da função.

- Prevenção de erros: Ao usar o const, você impede que acidentalmente modifique o parâmetro dentro da função. Isso ajuda a evitar erros sutis e facilita a manutenção do código.

- Flexibilidade: Ao marcar um parâmetro como const, você pode passar tanto objetos constantes quanto objetos não constantes como argumentos para a função. Isso aumenta a flexibilidade de uso da função, permitindo que ela seja aplicada em uma variedade de contextos.

---

## Tipos de Herança em C++ ##

C++ permite Herança múltiplas

Em C++, existem quatro tipos de herança possíveis:

    Herança Pública (public inheritance):
        É o tipo mais comum de herança em C++.
        Os membros públicos da classe base são herdados como membros públicos na classe derivada.
        Os membros protegidos da classe base são herdados como membros protegidos na classe derivada.
        Os membros privados da classe base não são acessíveis diretamente na classe derivada.
        A relação "é um" (is-a) é estabelecida entre a classe derivada e a classe base.
        Sintaxe: class Derivada : public Base { ... }

    Herança Protegida (protected inheritance):
        Os membros públicos e protegidos da classe base são herdados como membros protegidos na classe derivada.
        Os membros privados da classe base não são acessíveis diretamente na classe derivada.
        A relação "é implementado em termos de" (implemented-in-terms-of) é estabelecida entre a classe derivada e a classe base.
        Sintaxe: class Derivada : protected Base { ... }

    Herança Privada (private inheritance):
        Os membros públicos e protegidos da classe base são herdados como membros privados na classe derivada.
        Os membros privados da classe base não são acessíveis diretamente na classe derivada.
        A relação "é implementado em termos de" (implemented-in-terms-of) é estabelecida entre a classe derivada e a classe base.
        Sintaxe: class Derivada : private Base { ... }

    Herança Virtual (virtual inheritance):
        É usada quando há ambiguidade ou duplicação de membros devido a múltiplas heranças.
        Permite que uma classe derivada compartilhe uma única instância da classe base com várias classes derivadas.
        A herança virtual evita a duplicação de membros de classes base comuns.
        Sintaxe: class Derivada : virtual public Base { ... }

A escolha do tipo de herança depende do design do seu sistema e dos requisitos específicos do seu programa. Cada tipo de herança possui suas próprias características e implicações, e é importante escolher cuidadosamente a forma mais adequada para cada caso.

---

## Classe abstrata ##

Uma classe abstrata em C++ é uma classe que não pode ser instanciada diretamente. Ela é projetada para ser uma classe base ou superclasse que fornece uma estrutura comum para suas classes derivadas, mas não pode ser usada por conta própria para criar objetos.

A principal característica de uma classe abstrata é a presença de pelo menos uma função membro puramente virtual, que é declarada usando o modificador `virtual` e é seguida por `= 0`. Essas funções não possuem implementação na classe base e são destinadas a serem implementadas pelas classes derivadas.

A classe abstrata fornece uma interface comum para suas classes derivadas, definindo as funções puramente virtuais que devem ser implementadas por elas. Ela define o contrato ou conjunto de operações que as classes derivadas devem seguir.

A classe abstrata não pode ser instanciada porque não possui uma implementação completa de todas as suas funções. Ela é considerada incompleta e abstrata em termos de funcionalidade. No entanto, é possível criar ponteiros e referências para a classe abstrata.

A classe abstrata é destinada a ser apenas uma classe base, servindo como um molde para suas classes derivadas. As classes derivadas devem herdar da classe abstrata e implementar as funções puramente virtuais. Dessa forma, as classes derivadas fornecem uma implementação específica para as funções puramente virtuais definidas na classe abstrata.

A principal razão pela qual uma classe abstrata deve ser apenas herdada e não instanciada é que ela fornece apenas a estrutura e a interface para as classes derivadas. Cada classe derivada deve fornecer sua própria implementação para as funções puramente virtuais, personalizando assim o comportamento de acordo com suas necessidades específicas.

Em resumo, uma classe abstrata em C++ é uma classe que não pode ser instanciada diretamente e que contém pelo menos uma função membro puramente virtual. Ela define uma interface comum para suas classes derivadas, permitindo a criação de hierarquias de classes com comportamentos especializados e fornecendo uma estrutura geral para reutilização de código.

---

## Uso de const em métodos ##

O uso de const depois dos parametros, permite que se sinalize que o metodo nao vai mudar o estado do objeto. Isso é prequentemente em metodos que mostram informacoes do objeto.

---

Os métodos virtuais em C++ são uma ferramenta poderosa para implementar polimorfismo, permitindo que as classes derivadas substituam a implementação de um método da classe base. Aqui estão alguns dos principais usos dos métodos virtuais:

1. Polimorfismo: Os métodos virtuais são a base para alcançar o polimorfismo em C++. Eles permitem que você chame o método apropriado da classe derivada usando um ponteiro ou referência para a classe base. Isso é útil quando você tem uma coleção de objetos de diferentes classes derivadas, mas deseja tratá-los de maneira uniforme por meio de sua classe base.

2. Sobrescrita de métodos: Os métodos virtuais permitem que as classes derivadas substituam a implementação do método da classe base. Isso significa que você pode fornecer uma implementação personalizada e especializada do método em cada classe derivada, adaptando-o às necessidades específicas de cada classe.

3. Comportamento polimórfico: Os métodos virtuais permitem que diferentes classes derivadas forneçam comportamentos diferentes para um mesmo método. Isso é particularmente útil quando você tem uma classe base abstrata e deseja que as classes derivadas forneçam uma implementação adequada para cada uma delas. Assim, você pode chamar o mesmo método em objetos diferentes e obter resultados diferentes com base no tipo real do objeto.

4. Herança e extensibilidade: Os métodos virtuais permitem que você estenda e adicione novas funcionalidades às classes derivadas, mantendo a interface comum da classe base. Isso facilita a criação de hierarquias de classes que podem ser estendidas com novas classes derivadas, adicionando novos comportamentos e funcionalidades específicas.

5. Polimorfismo de tempo de execução: Os métodos virtuais fornecem o polimorfismo de tempo de execução, o que significa que a decisão sobre qual método será chamado é tomada em tempo de execução com base no tipo real do objeto. Isso permite uma seleção dinâmica do método a ser executado, fornecendo flexibilidade e adaptabilidade em tempo de execução.

---

O uso da palavra-chave `const` em métodos em C++ indica que esses métodos não modificam o estado interno do objeto no qual estão sendo chamados. Isso significa que eles não alteram os membros de dados não estáticos do objeto ou chamam outros métodos não constantes que possam causar modificações.

A inclusão da palavra-chave `const` no final da declaração do método é conhecida como qualificador de função `const`. Isso indica ao compilador que o método não realizará modificações nos membros de dados do objeto.

A principal razão para usar métodos `const` é garantir a imutabilidade e a consistência do objeto quando esse objeto é tratado como constante. Além disso, os métodos `const` podem ser chamados em objetos constantes e em ponteiros ou referências constantes para objetos.

Aqui está um exemplo para ilustrar o uso de métodos `const`:

```cpp
class MyClass {
public:
    int getValue() const {
        return value;
    }

    void setValue(int newValue) {
        value = newValue;
    }

private:
    int value;
};

int main() {
    const MyClass obj;  // Objeto constante
    int val = obj.getValue();  // Chama um método const

    // obj.setValue(10);  // Erro de compilação - obj é constante

    return 0;
}
```

No exemplo acima, a classe `MyClass` possui um método `getValue()` marcado com `const`, indicando que ele não altera o estado do objeto. No `main()`, um objeto constante `obj` é criado e o método `getValue()` é chamado para obter o valor do objeto. Observe que não é possível chamar o método `setValue()` no objeto constante, pois ele modifica o estado do objeto.

O uso de métodos `const` traz benefícios em termos de imutabilidade, consistência e segurança de código. Eles permitem que objetos constantes sejam tratados adequadamente e evitam modificações indesejadas em objetos que devem ser tratados como constantes.

É uma boa prática marcar métodos que não modificam o estado interno do objeto como `const` sempre que possível, para fornecer uma interface mais clara e segura para manipulação de objetos em C++.

---

## Problemas com heranca multipla ##

O problema de ambiguidade ocorre quando uma classe herda de múltiplas classes base que têm membros com o mesmo nome. Isso pode levar a ambiguidade na resolução de nomes durante a compilação, pois o compilador não consegue decidir qual membro deve ser acessado. Esse problema é conhecido como "ambiguidade de herança múltipla".

Vamos considerar um exemplo para ilustrar o problema de ambiguidade:

```cpp
#include <iostream>

class Base1 {
public:
    void print() const {
        std::cout << "Membro 'print' da Base1" << std::endl;
    }
};

class Base2 {
public:
    void print() const {
        std::cout << "Membro 'print' da Base2" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    // ...
};

int main() {
    Derived derived;
    derived.print();  // Ambiguidade de herança múltipla

    return 0;
}
```

Nesse exemplo, temos duas classes base, `Base1` e `Base2`, que possuem membros com o mesmo nome, neste caso, `print()`. A classe `Derived` herda dessas duas classes base.

Ao tentar chamar o membro `print()` do objeto `derived` da classe `Derived`, ocorre uma ambiguidade porque existem dois membros com o mesmo nome provenientes das classes base. O compilador não consegue determinar qual membro deve ser acessado, resultando em um erro de ambiguidade durante a compilação.

Existem algumas maneiras de resolver o problema de ambiguidade de herança múltipla:

1. Qualificação de membros: Você pode usar a qualificação para especificar qual membro você deseja acessar. Por exemplo:
   ```cpp
   derived.Base1::print();  // Acesso ao membro 'print' da classe Base1
   derived.Base2::print();  // Acesso ao membro 'print' da classe Base2
   ```

2. Renomear membros: Se você tiver controle sobre as classes base, pode renomear os membros para evitar a ambiguidade.

3. Herança virtual: Usar herança virtual pode resolver o problema de ambiguidade. No entanto, isso depende do design e dos requisitos específicos do seu sistema.

4. Resolução manual da ambiguidade: Em casos mais complexos, é possível criar uma função membro na classe derivada que faz a resolução manual da ambiguidade, chamando explicitamente o membro desejado de uma das classes base.

É importante ter cuidado ao usar herança múltipla para evitar problemas de ambiguidade. É recomendável projetar hierarquias de classes de forma clara e consciente para evitar possíveis ambiguidades e garantir que o código seja legível e manutenível.

---

## Interfaces ##

Em C++, o conceito de interface é geralmente implementado por meio de classes abstratas. Uma interface define um conjunto de métodos virtuais puros (também conhecidos como funções virtuais puras) que as classes derivadas devem implementar. Essa abstração permite que diferentes classes possam ser tratadas de forma uniforme por meio de sua interface comum.

Uma interface define apenas a estrutura e o contrato dos métodos que as classes derivadas devem implementar, mas não contém implementações concretas desses métodos. Por isso, uma classe que implementa uma interface é obrigada a fornecer uma implementação para todos os métodos virtuais puros definidos na interface.

A utilização de interfaces em herança de objetos permite criar hierarquias de classes que compartilham uma interface comum, mas fornecem implementações específicas para cada classe derivada. Isso permite que objetos de diferentes classes derivadas sejam tratados de forma polimórfica por meio de ponteiros ou referências à interface, permitindo a substituição dinâmica de objetos durante a execução.

Vejamos um exemplo para ilustrar como a interface é usada na herança de objetos:

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
