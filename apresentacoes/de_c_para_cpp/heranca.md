# Terminologia

1. **Base Class**: A classe base, também conhecida como classe pai ou superclasse, é a classe da qual outras classes são derivadas. Os membros (métodos e atributos) da classe base podem ser herdados pelas classes derivadas, com respeito aos especificadores de acesso.

2. **Derived Class**: A classe derivada, também conhecida como classe filha ou subclasse, é a classe que herda de uma classe base. Ela pode herdar e ter acesso aos membros da classe base, bem como adicionar seus próprios membros.

3. **Member Access Specifiers**: Os especificadores de acesso de membros em C++ controlam a acessibilidade dos membros de uma classe. Eles são:

   - **private**: Membros privados são acessíveis somente dentro da classe que os declara. Eles não são acessíveis na classe derivada nem de fora da classe.
   - **protected**: Membros protegidos são acessíveis dentro da classe que os declara e dentro das classes que dela herdam, mas não de fora da classe ou de suas subclasses.
   - **public**: Membros públicos são acessíveis dentro da classe que os declara, dentro das classes que dela herdam, e de fora da classe.

A tabela abaixo mostra o acesso aos membros da classe base em diferentes contextos:

| Member Access Specifier | Base Class | Derived Class | Outside the Class |
| --- | --- | --- | --- |
| private | Yes | No | No |
| protected | Yes | Yes | No |
| public | Yes | Yes | Yes |

4. **Friend**: Em C++, a palavra-chave `friend` é usada para conceder acesso a membros privados e protegidos de uma classe. Uma função ou classe marcada como `friend` de uma classe particular pode acessar os membros privados e protegidos dessa classe. Essa é uma maneira de permitir o acesso a determinados membros sem torná-los publicamente acessíveis a todos.
   
Por exemplo, se tivermos uma classe `Dog` que é derivada de uma classe `Animal`, e `Animal` tem um membro privado `_name`, a `Dog` não pode acessar diretamente `_name`. No entanto, se houver uma função `printName` que é um `friend` de `Animal`, então `printName` pode acessar `_name`, mesmo estando fora da classe `Animal`.

## Exemplo de herança ##

```cpp

class Animal{
   
  protected: 
    ...
    speaks (){}
    ...
}

class Dog: public Animal {
    ...
}