---
marp: true
theme: gaia
paginate: true
---

<!-- _class: lead -->

# Métodos #

Professor: Carlos Alvaro Quintella
07/05/2023

---

* Em C++, os métodos são funções que pertencem a uma classe e podem acessar os dados membros dessa classe.

* São utilizados para realizar operações sobre esses dados, ou seja, para implementar o comportamento da classe.

---

```cpp
class Retangulo {
  private:
    int largura, altura;
  public:
    void setValores(int, int);
    int area() {return largura * altura;}
};

void Retangulo::setValores(int x, int y) {
  largura = x;
  altura = y;
}

int main() {
  Retangulo r;
  r.setValores(3, 4);
  cout << "Area: " << r.area() << endl;
  return 0;
}
```

---

* Métodos são uma parte importante da programação orientada a objetos em C++.

* Permitem que os dados membros de uma classe sejam manipulados e o comportamento da classe seja implementado.

---

## Modificadores de Método ##

Em C++, os modificadores de método são usados para indicar como um método deve ser tratado pela linguagem. 

Modificadores de acesso:

### Public ###

Indica que o método pode ser acessado de fora da classe, ou seja, ele pode ser chamado por qualquer objeto da classe ou mesmo por funções que não fazem parte da classe.

### Private ###

Indica que o método só pode ser acessado de dentro da classe. Ou seja, ele não pode ser chamado por objetos da classe ou por funções externas à classe.

### Protected ###

Esse modificador é semelhante ao modificador private, mas permite que as subclasses (herdeiras) acessem o método.

Além desses modificadores, existem também outros que podem ser usados em combinação com os modificadores de acesso, como:

### Static ###

Indica que o método pertence à classe em vez de pertencer a cada objeto criado a partir da classe.

### Virtual ###

É usado em métodos que podem ser sobrescritos pelas subclasses.

### Override ###

Esse modificador é usado em métodos de subclasses que estão sobrescrevendo um método da classe pai.

### Final ###

É usado em métodos de uma classe pai para indicar que eles não podem ser sobrescritos por suas subclasses.

Esses modificadores são úteis para controlar o acesso a métodos e garantir a integridade dos dados em uma classe.

---

### Outros modificadores que podemos encontrar ###

#### const ####

O modificador const é usado para indicar que um método não modifica o estado interno do objeto em que está sendo chamado. Isso pode ajudar a prevenir bugs em código complexo, permitindo que o compilador detecte tentativas de modificar objetos que deveriam ser imutáveis.

---

```c++
class Exemplo {
private:
  int valor;

public:
  void setValor(int novoValor) {
    valor = novoValor;
  }

  int getValor() const {
    return valor;
  }
};
```

---

O modificador `const` indica que o método não irá modificar o estado do objeto. Isso permite que o compilador faça otimizações e ajuda a garantir que o código seja seguro contra alterações acidentais. No exemplo acima, o método `getValor` não modifica o objeto, então é seguro marcá-lo como `const`.

---

#### inline ####

O modificador inline é usado para indicar que o compilador deve tentar expandir o corpo da função diretamente no local onde a função foi chamada, em vez de gerar uma chamada de função. Isso pode ajudar a melhorar o desempenho em determinadas situações, reduzindo o overhead de uma chamada de função.

---

```c++
class Exemplo {
public:
  inline void metodoInline() {
    // código do método
  }
};
```

O modificador `inline` sugere ao compilador que o método seja executado diretamente no local onde é chamado, em vez de criar uma chamada de função. Isso pode melhorar o desempenho, mas é importante lembrar que o compilador pode decidir ignorar o modificador em alguns casos, se julgar que não há benefício em usá-lo.

---

#### auto ####

O modificador auto é usado para permitir que o compilador deduza automaticamente o tipo de retorno de uma função, com base no tipo do valor retornado pela função. Isso pode ser útil para simplificar a sintaxe de declaração de funções.

---

```c++
class Exemplo {
public:
  auto metodoAuto() {
    // código do método que retorna um tipo deduzido pelo compilador
  }
};
```

---

O modificador `auto` permite que o compilador deduza automaticamente o tipo de retorno do método com base no que é retornado pelo corpo do método. Isso pode tornar o código mais conciso e fácil de ler, mas também pode tornar o código menos explícito e mais difícil de depurar em alguns casos.

---

#### friend ####

* Em C++, é possível declarar funções ou classes como "amigas" de uma classe.

* Isso significa que essas funções ou classes têm acesso aos membros privados e protegidos da classe.

* A declaração de amizade é feita através da palavra-chave friend dentro da classe.

```cpp
class MinhaClasse {
private:
  int membro_privado;
public:
  friend void minha_funcao_amiga(MinhaClasse& obj);
};
```

```cpp
class MinhaClasse {
private:
  int membro_privado;
public:
  friend void minha_funcao_amiga(MinhaClasse& obj);
};

void minha_funcao_amiga(MinhaClasse& obj) {
  obj.membro_privado = 42;
}

```

Neste exemplo, a função minha_funcao_amiga é declarada como amiga da classe MinhaClasse. Isso permite que a função acesse o membro privado membro_privado. O uso da declaração friend é útil em situações em que é necessário permitir que uma função ou classe específica acesse os membros privados de uma classe, sem precisar expô-los publicamente.