---
marp: true
---

# Introdução aos Tipos Definidos pelo Usuário

- Conceito de Tipos Definidos pelo Usuário
- Por que usar tipos definidos pelo usuário?
- Exemplos de tipos definidos pelo usuário

--

## Definição de Tipos Definidos pelo Usuário

- O que são Tipos Definidos pelo Usuário?
- Aumentam a legibilidade e organização do código
- Permitem manipular dados complexos de forma eficiente

---

## Vantagens dos Tipos Definidos pelo Usuário

- Facilitam a modularização do código
- Melhoram a manutenção e expansão do projeto
- Facilitam a comunicação entre desenvolvedores

## Exemplos de Tipos Definidos pelo Usuário

- Estruturas (struct)
- Classes (class)
- Enumerações (enum)
- Uniões (union)

## Estruturas (struct)

- Agrupam variáveis relacionadas sob um único nome
- Exemplo: `struct Ponto { int x; int y; };`

---

## Classes (class)**
- Semelhante às estruturas, mas com suporte a métodos e encapsulamento
- Exemplo: `class Circulo { private: double raio; public: double area(); };`

--

## Enumerações (enum)**
- Lista de constantes nomeadas, úteis para representar conjuntos de valores discretos
- Exemplo: `enum class DiasDaSemana { Dom, Seg, Ter, Qua, Qui, Sex, Sab };`

--

## Uniões (union)**
- Permitem armazenar diferentes tipos de dados na mesma região de memória
- Exemplo: `union Dado { int i; float f; char c; };`

---

## Conclusão
- Tipos definidos pelo usuário são fundamentais para criar programas eficientes e organizados
- Escolha o tipo adequado para cada situação e melhore a qualidade do seu código

---

## Variável de um Struct

- Podemos acessar os componentes de um Struct usando o operador "." (ponto)

```c++
struct Pessoa {
    std::string nome;
    int idade;
};

int main() {
    Pessoa p;
    p.nome = "João";
    p.idade = 25;
}
```

---

## Ponteiro de um Struct

- Podemos acessar os componentes de um Struct usando o operador "->" (seta)

```c++
struct Pessoa {
    std::string nome;
    int idade;
};

int main() {
    Pessoa *p = new Pessoa;
    p->nome = "João";
    p->idade = 25;
    delete p;
}
```

---

- Ao usar o ponteiro, podemos passar o endereço de um Struct como argumento de função para modificar os seus componentes:

```c++
void aumenta_idade(Pessoa *p, int anos) {
    p->idade += anos;
}

int main() {
    Pessoa *p = new Pessoa;
    p->nome = "João";
    p->idade = 25;
    aumenta_idade(p, 5);
    std::cout << p->idade; // imprime 30
    delete p;
}
```

---

