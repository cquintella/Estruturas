
# Modificadores de acesso #

os modificadores de acesso (private, public e protected) são utilizados para controlar o acesso aos componentes de uma classe. Eles definem as permissões de acesso dos membros da classe para outras partes do código.

---

## private ##

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
- Os membros protected são acessíveis dentro da própria classe, bem como pelas classes derivadas (subclasses) da classe base.
- Isso significa que os membros protected não podem ser acessados por funções ou objetos fora da hierarquia de herança.
- Os membros protected são frequentemente usados para fornecer acesso controlado às subclasses, permitindo que elas herdem e manipulem os dados internos da classe base.

---

```c
class Exemplo {
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

### Uso de Setters e Getters ###

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

## Uso de const em métodos ##

O uso de const depois dos parametros como no exemplo abaixo, permite que se sinalize que o metodo nao vai mudar o estado do objeto. Isso é prequentemente em metodos que mostram informacoes do objeto.

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

### const em parâmetrode funções ou métodos ##

Existem alguns benefícios de usar o const em parâmetros de função:

- Documentação clara: Ao marcar um parâmetro como const, você está comunicando aos outros desenvolvedores que a função não irá modificar esse parâmetro. Isso torna o código mais legível e compreensível, facilitando o entendimento do comportamento da função.

- Prevenção de erros: Ao usar o const, você impede que acidentalmente modifique o parâmetro dentro da função. Isso ajuda a evitar erros sutis e facilita a manutenção do código.

- Flexibilidade: Ao marcar um parâmetro como const, você pode passar tanto objetos constantes quanto objetos não constantes como argumentos para a função. Isso aumenta a flexibilidade de uso da função, permitindo que ela seja aplicada em uma variedade de contextos.

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
