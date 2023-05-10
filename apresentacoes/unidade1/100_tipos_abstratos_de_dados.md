---
marp: true
author: carlos.quintella@uva.br

paginate: true
theme: default
style: |
  video::-webkit-media-controls {
    will-change: transform;
  }
---

<!-- _class: lead -->

# TAD - Tipo Abstrato de Dados #

Carlos Alvaro Quintella
08/05/2023

![UVA 50% bg left:20%](https://scontent.fstu1-1.fna.fbcdn.net/v/t1.18169-9/12038391_10153722080706340_7570391622888322838_n.png?_nc_cat=106&ccb=1-7&_nc_sid=174925&_nc_ohc=BefZdJ6r1a4AX-MadqL&_nc_oc=AQkw4Umxiy3CzJ0PEn0rZvyLpQua30GzJj9Fx1LH37qGS545w2GlcEKoUJBjndWHRxQ&_nc_ht=scontent.fstu1-1.fna&oh=00_AfD5qau0zNokMGdT_pEr0cwiAk9TbW2bYxm27PEXPfBhGQ&oe=6480A5AE)

---

## Definição de TAD ##

Tipo Abstrato de Dados (TAD) é uma abstração que define um tipo de dado e operações relacionadas, ocultando a implementação dos usuários. Isso permite focar na funcionalidade e lógica de alto nível, proporcionando modularidade e reutilização de código na programação orientada a objetos.

---

## Exemplo de TAD em pseudo-código, definindo uma pilha. ##

```text

**TAD Pilha**

**Estrutura**

_class Pilha:_
    elementos: lista
    topo: inteiro


_Operações_

 - Inicializar Pilha

- Verificar se a Pilha está Vazia

- Empilhar

- Desempilhar

- Consultar Topo

```

---

## Exercício: Crie um TAD para uma Lista encadeada Simples ##

---

## As vantagens de usar Tipos Abstratos de Dados (TADs) incluem: ##

1. **Encapsulamento**: TADs escondem a implementação dos dados, permitindo acesso apenas através das operações definidas. Isso separa a interface do usuário da implementação, facilitando a manutenção e evolução do código.
2. **Modularidade**: Ao utilizar TADs, é mais fácil dividir um programa em componentes menores e independentes, tornando o desenvolvimento e a depuração mais eficientes.
3. **Reutilização de código**: TADs facilitam a reutilização de código, já que permitem criar bibliotecas de estruturas de dados que podem ser aplicadas em diferentes projetos.
4. **Abstração**: TADs permitem aos programadores se concentrarem na lógica de alto nível, sem se preocupar com os detalhes de baixo nível da implementação.

---

5. **Flexibilidade**: Como a implementação dos dados é oculta, é possível modificar a implementação sem afetar o código que utiliza o TAD, o que garante maior flexibilidade na evolução do software.
6. **Robustez e segurança**: Ao limitar o acesso à implementação interna, TADs reduzem a chance de erros e aumentam a segurança do código, pois os usuários são forçados a interagir com os dados apenas por meio das operações fornecidas.

---

## Conclusão ##

- Os Tipos Abstratos de Dados desempenham um papel fundamental na programação e na estruturação de programas de maneira mais organizada e eficiente.
- Ao adotar o uso de TADs, os desenvolvedores podem se concentrar na lógica de alto nível, mantendo o código modular e facilmente adaptável a mudanças futuras.

---

## Resumo ##

TADs, ou Tipos Abstratos de Dados, são abstrações que permitem aos programadores definir tipos de dados e operações relacionadas sem expor a implementação subjacente. Essa abordagem oferece várias vantagens, incluindo encapsulamento, modularidade, reutilização de código, abstração, flexibilidade e robustez.

---

[video](https://www.youtube.com/watch?v=nX_3zUmNFFs)
