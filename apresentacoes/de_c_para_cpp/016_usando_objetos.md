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

## Conceito de classe ##

Conforme apresentado anteriormente, uma classe é um protótipo para a criação de objetos em C++, incluindo atributos (características) e métodos (ações).

A declaração de uma classe, contendo os atributos e métodos, pode ser estruturada de diferentes maneiras, cada uma se qadequando a um determinado estilo de programação.

---

### Exemplo de uma classe com métodos definidos internamente ###

```cpp

class Retangulo {
    private:
        double largura;
        double altura;
    
    public:
        // Construtor
        Retangulo(double l, double a) {
            largura = l;
            altura = a;
        }

        // Método para calcular a área
        double calcularArea() {
            return largura * altura;
        }

        // Método para calcular o perímetro
        double calcularPerimetro() {
            return 2 * (largura + altura);
        }
};
```

---

### Exemplo de uma classe com métodos definidos externamente à classe ###

```cpp

class Retangulo {
    private:
        double largura;
        double altura;

    public:
        // Construtor
        Retangulo(double l, double a);

        // Método para calcular a área
        double calcularArea();

        // Método para calcular o perímetro
        double calcularPerimetro();
};

// Definição do construtor
Retangulo::Retangulo(double l, double a) {
    largura = l;
    altura = a;
}

// Definição do método calcularArea
double Retangulo::calcularArea() {
    return largura * altura;
}

// Definição do método calcularPerimetro
double Retangulo::calcularPerimetro() {
    return 2 * (largura + altura);
}
```

---

a primeira coisa coisa que precisamos pensar quando criamos uma classe são os:

## Modificadores de acesso #

Em C++, a cláusula `class` é bastante similar à `struct`, mas apresenta uma diferença crucial: enquanto na `struct` todos os elementos são públicos por padrão, na `class` eles são privados.

- publico e privado no caso, se referem aos modificadores de acesso, `public`e `private`.

---

- **private**: Os componentes `private` são acessíveis apenas dentro da própria classe. Esses elementos são usados para armazenar e manipular dados internos, permanecendo ocultos para as demais classes, funções ou objetos. Caso um modificador de acesso não seja especificado, os componentes da classe são considerados `private` por padrão.

---

- **public**: Os componentes `public` estão disponíveis em qualquer parte do código, incluindo outras classes, funções e objetos. Eles compõem a interface pública da classe, oferecendo métodos e atributos que podem ser acessados externamente.

- **protected**: Os componentes `protected` possuem características combinadas dos modificadores `private` e `public`. Eles são acessíveis na própria classe e também pelas subclasses, no caso de herança; permitindo que essas manipulem os dados internos da classe base. No entanto, estão inacessíveis para funções ou objetos fora dessa hierarquia de herança.

---

Para obter o mesmo efeito de uma struct usando class, a declaração ficaria assim:

```cpp
class {
    public: 
    <declaração de atributos e métodos>
}.
```

Na `class` do C++, os componentes são privados por padrão. Para acessar ou modificar esses atributos, devemos usar os **métodos acessórios**, comumente conhecidos como 'setters' e 'getters'.

> Note que: Se sua estrutura contém apenas dados sem comportamentos específicos, struct é a escolha ideal. No entanto, se a estrutura requer comportamentos (funções), a class é a opção recomendada.

---

Portanto, s modificadores de acesso (private, public e protected) controlam o acesso aos componentes de uma classe, estabelecendo as permissões de acesso aos componentes da classe para o restante do código. Lembre-se que, se nenhum modificador de acesso for especificado, os componentes são considerados private.

---

Ao nomear uma classe em C++, adotamos a convenção de começar com uma letra maiúscula.

Os arquivos de cabeçalho (.h ou .hpp) devem conter a definição da classe, incluindo atributos e os protótipos dos métodos.

A implementação dos métodos, por sua vez, deve ser incluída no arquivo correspondente .cpp.

---

Note que, se você estiver utilizando templates, será necessário colocar a implementação dos métodos diretamente no arquivo de cabeçalho.

```cpp
// Arquivo: Box.h

#ifndef BOX_H
#define BOX_H

template <class T>
class Box {
    private:
        T content;

    public:
        // Construtor
        Box(T content) : content(content) {}

        // Método para obter o conteúdo
        T getContent() {
            return content;
        }
};

#endif  // BOX_H
```

---

Essas diretrizes de estilo de codificação contribuem para a legibilidade, manutenção e organização do seu código.

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

## construtores e destrutores ##

Conhecidos como funções membro especiais (special memberfunction), os construtores e destrutores desempenham papéis importantes em uma classe C++.

O construtor é uma função membro que é automaticamente chamada quando um objeto da classe é criado. Sua principal responsabilidade é inicializar os atributos do objeto. Ele carrega o mesmo nome da classe.

O destrutor é a função membro chamada quando o objeto de uma classe é destruído, seja ao sair do escopo ou quando deletado explicitamente. Ele cuida da limpeza do objeto, como liberar recursos alocados. O nome do destrutor é o mesmo da classe, porém precedido pelo caractere ~.

Estas funções especiais garantem que os objetos sejam apropriadamente inicializados e limpos, auxiliando no gerenciamento eficiente de recursos.

---

### Construtor ###

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

### Destrutor ###

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

## Métodos Acessórios ##

### Setters e Getters ###

Setters e Getters são métodos utilizados para acessar e modificar os atributos de um objeto em C++.

- Eles permitem que os atributos sejam protegidos, ocultando-os do código externo e proporcionando um melhor controle sobre a forma como são acessados e modificados.

---

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

---

- **Instanciação usando parênteses**: Também conhecida como instanciação por parênteses vazios, é usada para criar um objeto sem passar argumentos para o construtor.

Sintaxe: Classe objeto();

---

- **Instanciação com argumentos**: É usada para criar um objeto e passar argumentos para o construtor da classe.
Sintaxe: Classe objeto(argumentos);

- **Instanciação usando new**: Utiliza o operador new para criar um objeto dinamicamente no heap (espaço de memória dinamicamente alocado). Retorna um ponteiro para o objeto criado.
Sintaxe: Classe* objeto = new Classe();

---

- **Instanciação usando chaves (C++11 e versões posteriores)**: Utiliza a lista de inicialização usando chaves {} para inicializar os membros do objeto. Essa forma permite inicializar membros com valores específicos.

Sintaxe: Classe objeto{argumentos};

---

- **Instanciação com atribuição**: Cria um objeto e o atribui a uma variável existente.

Sintaxe: Classe objeto = outroObjeto;

No final você deve ou ter uma varável ou um pnteiro apontando para o Objeto criado.

---

### const em parâmetrode funções ou métodos ##

const safe objects

Existem alguns benefícios de usar o const em parâmetros de função:

- Documentação clara: Ao marcar um parâmetro como const, você está comunicando aos outros desenvolvedores que a função não irá modificar esse parâmetro. Isso torna o código mais legível e compreensível, facilitando o entendimento do comportamento da função.

---

- Prevenção de erros: Ao usar o const, você impede que acidentalmente modifique o parâmetro dentro da função. Isso ajuda a evitar erros sutis e facilita a manutenção do código.

- Flexibilidade: Ao marcar um parâmetro como const, você pode passar tanto objetos constantes quanto objetos não constantes como argumentos para a função. Isso aumenta a flexibilidade de uso da função, permitindo que ela seja aplicada em uma variedade de contextos.

voce pode ter duas versoes do mesmo metodo, um com uma versao imutavel com const e outra sem, numa versao mutavel.

---

**NOTA:**
Na prática para o C++ a diretiva class é muito similar a struc, com a diferença que por padrão em class os atributos e métodos são privados e em struct os componentes são sempre públicos. Uma boa prática é quando você não precisar de ter métodos (ou seja comportamentos associados ao objeto) você deve usar um struct.

---

## Tipos de Herança em C++ ##

C++ permite Herança múltiplas

Em C++, existem quatro tipos de herança possíveis:

---

### Herança Pública (public inheritance) ###

- É o tipo mais comum de herança em C++.
- Os membros públicos da classe base são herdados como membros públicos na classe derivada.
- Os membros protegidos da classe base são herdados como membros protegidos na classe derivada.
- Os membros privados da classe base não são acessíveis diretamente na classe derivada.
- A relação "é um" (is-a) é estabelecida entre a classe derivada e a classe base.
- Sintaxe: class Derivada : public Base { ... }

---

### Herança Protegida (protected inheritance) ###

- Os membros públicos e protegidos da classe base são herdados como membros protegidos na classe derivada.
- Os membros privados da classe base não são acessíveis diretamente na classe derivada.
- A relação "é implementado em termos de" (implemented-in-terms-of) é estabelecida entre a classe derivada e a classe base.
- Sintaxe: class Derivada : protected Base { ... }

---

### Herança Privada (private inheritance) ###

- Os membros públicos e protegidos da classe base são herdados como membros privados na classe derivada.
- Os membros privados da classe base não são acessíveis diretamente na classe derivada.
- A relação "é implementado em termos de" (implemented-in-terms-of) é estabelecida entre a classe derivada e a classe base.
- Sintaxe: class Derivada : private Base { ... }

---

### Herança Virtual (virtual inheritance) ###

- É usada quando há ambiguidade ou duplicação de membros devido a múltiplas heranças.
- Permite que uma classe derivada compartilhe uma única instância da classe base com várias classes derivadas.
- A herança virtual evita a duplicação de membros de classes base comuns.
- Sintaxe: class Derivada : virtual public Base { ... }

---

A escolha do tipo de herança depende do design do seu sistema e dos requisitos específicos do seu programa. Cada tipo de herança possui suas próprias características e implicações, e é importante escolher cuidadosamente a forma mais adequada para cada caso.

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

## Classe abstrata ##

Uma classe abstrata em C++ é uma classe que não pode ser instanciada diretamente. Ela é projetada para ser uma classe base ou superclasse que fornece uma estrutura comum para suas classes derivadas, mas não pode ser usada por conta própria para criar objetos.

A principal característica de uma classe abstrata é a presença de pelo menos uma função membro puramente virtual, que é declarada usando o modificador `virtual` e é seguida por `= 0`. Essas funções não possuem implementação na classe base e são destinadas a serem implementadas pelas classes derivadas.

A classe abstrata fornece uma interface comum para suas classes derivadas, definindo as funções puramente virtuais que devem ser implementadas por elas. Ela define o contrato ou conjunto de operações que as classes derivadas devem seguir.

A classe abstrata não pode ser instanciada porque não possui uma implementação completa de todas as suas funções. Ela é considerada incompleta e abstrata em termos de funcionalidade. No entanto, é possível criar ponteiros e referências para a classe abstrata.

A classe abstrata é destinada a ser apenas uma classe base, servindo como um molde para suas classes derivadas. As classes derivadas devem herdar da classe abstrata e implementar as funções puramente virtuais. Dessa forma, as classes derivadas fornecem uma implementação específica para as funções puramente virtuais definidas na classe abstrata.

A principal razão pela qual uma classe abstrata deve ser apenas herdada e não instanciada é que ela fornece apenas a estrutura e a interface para as classes derivadas. Cada classe derivada deve fornecer sua própria implementação para as funções puramente virtuais, personalizando assim o comportamento de acordo com suas necessidades específicas.

Em resumo, uma classe abstrata em C++ é uma classe que não pode ser instanciada diretamente e que contém pelo menos uma função membro puramente virtual. Ela define uma interface comum para suas classes derivadas, permitindo a criação de hierarquias de classes com comportamentos especializados e fornecendo uma estrutura geral para reutilização de código.

---

metodos virtuais

Os métodos virtuais em C++ são uma ferramenta poderosa para implementar polimorfismo, permitindo que as classes derivadas substituam a implementação de um método da classe base. Aqui estão alguns dos principais usos dos métodos virtuais:

1. Polimorfismo: Os métodos virtuais são a base para alcançar o polimorfismo em C++. Eles permitem que você chame o método apropriado da classe derivada usando um ponteiro ou referência para a classe base. Isso é útil quando você tem uma coleção de objetos de diferentes classes derivadas, mas deseja tratá-los de maneira uniforme por meio de sua classe base.

---

2. Sobrescrita de métodos: Os métodos virtuais permitem que as classes derivadas substituam a implementação do método da classe base. Isso significa que você pode fornecer uma implementação personalizada e especializada do método em cada classe derivada, adaptando-o às necessidades específicas de cada classe.

---

3. Comportamento polimórfico: Os métodos virtuais permitem que diferentes classes derivadas forneçam comportamentos diferentes para um mesmo método. Isso é particularmente útil quando você tem uma classe base abstrata e deseja que as classes derivadas forneçam uma implementação adequada para cada uma delas. Assim, você pode chamar o mesmo método em objetos diferentes e obter resultados diferentes com base no tipo real do objeto.

---

4. Herança e extensibilidade: Os métodos virtuais permitem que você estenda e adicione novas funcionalidades às classes derivadas, mantendo a interface comum da classe base. Isso facilita a criação de hierarquias de classes que podem ser estendidas com novas classes derivadas, adicionando novos comportamentos e funcionalidades específicas.

---

5. Polimorfismo de tempo de execução: Os métodos virtuais fornecem o polimorfismo de tempo de execução, o que significa que a decisão sobre qual método será chamado é tomada em tempo de execução com base no tipo real do objeto. Isso permite uma seleção dinâmica do método a ser executado, fornecendo flexibilidade e adaptabilidade em tempo de execução.

---

const em Métodos e Atributos

Em C++, o uso do qualificador const em métodos indica que esses métodos não alteram o estado do objeto, ou seja, não modificam seus atributos. Tais métodos são comumente utilizados para retornar informações do objeto.

O uso de const promove a segurança do código, prevenindo alterações indesejadas em objetos que devem permanecer imutáveis.

Como uma boa prática, é recomendável marcar como const os métodos que não alteram o estado do objeto, garantindo uma interface clara e segura para a manipulação de objetos.

---

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
    int val = obj.getValue();  // Chamando um método const

    // obj.setValue(10);  // Erro de compilação - obj é constante

    return 0;
}
```

---

Quando o const é usado em atributos, isso significa que o valor do atributo não pode ser alterado depois de ser inicializado. Isso faz do atributo uma constante, o que é útil quando você tem um valor que deve permanecer o mesmo durante todo o ciclo de vida do objeto.

```cpp
class Circle {
public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return 3.14159 * radius * radius;
    }

private:
    const double radius;  // Uma vez definido, o raio não pode ser alterado
};
```

---

## O uso do underscore _ antes do nome de um atributo ##

 é uma convenção de nomenclatura usada em muitas linguagens de programação, incluindo C++. Esta convenção é útil por várias razões:

- Distinção entre atributos e variáveis locais: Ao usar um underscore antes do nome de um atributo, você pode diferenciá-lo de uma variável local em um método ou função. Isso pode tornar o código mais legível e fácil de entender.

---

- Encapsulamento: O uso de underscore antes do nome de um atributo pode indicar que o atributo é destinado a ser privado, ou seja, acessível apenas dentro da própria classe. Embora o C++ ofereça palavras-chave de controle de acesso (public, protected, private) para controlar a visibilidade dos membros da classe, a adição de um underscore pode reforçar essa intenção visualmente.

- Evitar conflitos de nomenclatura: Em alguns casos, você pode querer nomear um atributo com um nome que seja o mesmo ou semelhante a uma palavra-chave da linguagem de programação, ou a um nome usado em um escopo mais amplo. Colocar um underscore antes do nome do atributo pode ajudar a evitar esses conflitos.

---

## Métodos Implícitos ##

Em C++, métodos implícitos são métodos especiais que são automaticamente fornecidos pelo compilador para todas as classes, a menos que sejam explicitamente definidos pelo programador. Esses métodos incluem:

1. **Construtor Padrão**: Se nenhum construtor é definido, o compilador gera um construtor padrão sem parâmetros. Este construtor padrão não fará nada para tipos primitivos, mas invocará o construtor padrão para tipos de objeto.

---

2. **Destrutor**: Se nenhum destrutor é definido, o compilador fornece um que não faz nada.

3. **Construtor de cópia**: Se não for definido, o compilador fornecerá um que copia todos os membros da classe. 

4. **Operador de atribuição de cópia**: Se não for definido, o compilador fornecerá um que atribui todos os membros da classe.

---

5. **Construtor de movimento e operador de atribuição de movimento** (desde C++11): Estes métodos são gerados se nenhum construtor de cópia, operador de atribuição de cópia ou destrutor são definidos explicitamente. Eles permitem que objetos sejam construídos ou atribuídos a partir de objetos temporários (rvalues), proporcionando um ganho de desempenho.

Por padrão, esses métodos realizam operações de membro a membro, o que é adequado para muitas classes. No entanto, para classes que gerenciam recursos, como memória dinâmica, é comum que os programadores forneçam suas próprias definições para esses métodos, a fim de garantir um gerenciamento de recursos adequado.

---

