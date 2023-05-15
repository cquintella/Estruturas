---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Curso de C++
theme: gaia
---

<!-- _class: lead -->

# Orientação à objetos em C++ #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

A orientação a objetos é um paradigma de programação que utiliza objetos e classes para representar e organizar os dados e as funcionalidades de um programa.

## Conteúdo ##

1. [Paradigma da Programação Orientada a Objetos](#paradigma-da-programação-orientada-a-objetos)
2. [Platão e a programação orientada a objetos](#platão-e-a-programação-orientada-à-objetos)
3. [Paradigma](#definição-de-paradigma)

---

4. [Conceito de Classe](#conceito-de-classe)
5. [Conceito de Objeto](#conceito-de-objeto)
6. [Princípios da OO](#princípios-da-oo)
7. [Encapsulamento](#encapsulamento)
8. [Herança](#herança)
9. [Polimorfismo](#polimorfismo)
10. [Abstração](#abstração)
11. [Composição](#composição)
12. [Definições](#definições)

---

## Paradigma da Programação Orientada a Objetos ##

- Utiliza objetos e classes
- Representa e organiza dados e funcionalidades
- Promove reutilização e modularidade de código
- Princípios fundamentais: encapsulamento, herança, polimorfismo e abstração

---

### Platão e a POO ###

Podemos fazer uma analogia da programação orientada a objetos (POO) a Teoria do Mundo das Ideias de Platão; onde as Classes de Objetos representam os conceitos e definições perfeitas dos objetos no Mundo das Ideias, enquanto os Objetos instanciados seriam as manifestações dessas Classes no Mundo Sensível.

- [Platão x Aristóteles | Mundo das Ideias e Mundo Sensível](https://www.youtube.com/watch?v=NFMeZls5DQk)

---

Assim como Platão defendia que o Mundo Sensível é apenas uma sombra ou reflexo imperfeito do Mundo das Ideias, na POO, os Objetos são Instâncias Concretas das Classes, que são as representações ideais e conceitos relacionados aos  objetos.

- Nesse sentido, as classes atuam como modelos ou arquétipos que descrevem as características e comportamentos dos objetos.
- Encapsulam dados e funcionalidades relacionadas, permitindo a criação de múltiplas instâncias consistentes.

---

Essa conexão entre a POO e o mundo das ideias de Platão destaca a natureza conceitual e abstrata da programação orientada a objetos, onde as classes representam os ideais perfeitos e os objetos materializam esses ideais no mundo real.

- [Dicionário do Programador POO](https://www.youtube.com/watch?v=QY0Kdg83orY)

---

## Definição de [Paradigma](https://pt.wikipedia.org/wiki/Paradigma) ##

<!-- _class: invert -->

- Conjunto compartilhado de crenças, valores, técnicas e abordagens
- Molda e orienta pensamento, resolução de problemas e abordagens a desafios
- Estruturas conceituais ou modelos mentais
Influencia a percepção da realidade
- Fornece padrões e diretrizes para a prática
- Estabelece limites do que é aceitável ou possível em um campo específico

![bg Matrix](https://wallpapercave.com/dwp1x/HV4cE1h.jpg)

<!--
_Um paradigma é um conjunto de crenças, valores, técnicas e abordagens compartilhadas por uma comunidade que molda e orienta a forma como os membros dessa comunidade pensam, resolvem problemas e abordam novos desafios. Em um contexto mais amplo, os paradigmas servem como estruturas conceituais ou modelos mentais que influenciam a percepção da realidade, fornecem padrões e diretrizes para a prática e estabelecem os limites do que é considerado aceitável ou possível em um campo específico_.
-->

---

- C++ é uma linguagem de programação que suporta a orientação a objetos, permitindo que os desenvolvedores criem soluções modulares, reutilizáveis e escaláveis.

![diagrama de objetos bg 90% left:30%](https://www.tjpr.jus.br/image/image_gallery?uuid=72e79f0e-d7da-4cd0-a196-904dc23a1367&groupId=15397&t=1336154459851)

---

Os principais conceitos da orientação a objetos em C++ incluem:

---

## Conceitos Relacionados a Orientação à Objetos ##

![bg 90% right](https://media.geeksforgeeks.org/wp-content/uploads/OOPs-Concepts.jpg)

[fonte da imagem](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)

---

### Classe ###

- Modelo ou projeto para objetos (blue print)
- Define propriedades (atributos) e comportamentos (métodos)
- Comum a um grupo de objetos
- Semelhante a tipos para variáveis
- Serve como molde para criar objetos específicos

<!--
Classe: Uma classe é um modelo ou um projeto que define as propriedades (atributos) e comportamentos (métodos) comuns a um grupo de objetos.

assim como os tipos para a variáveis, as classes servem como um molde para criar objetos específicos.
-->

---

### Conceito de Objeto ###

- Instância de uma classe
Representa uma entidade específica.
- Possui atributos e comportamentos definidos pela classe.
- Estado próprio determinado pelos valores dos atributos.

<!--
Objeto: Um objeto é uma instância de uma classe. Ele representa uma entidade específica que possui atributos e comportamentos definidos pela classe.

Cada objeto tem seu próprio estado, que é determinado pelos valores de seus atributos.
-->

---

### Encapsulamento ###

- Agrupa dados e funções relacionadas
- Protege a integridade dos dados.
- Oculta detalhes de implementação
- Exposição de uma interface pública
- Uso de modificadores de acesso (public, private, protected)
- Controle de visibilidade de atributos e métodos
- Aumenta modularidade e manutenibilidade do código

<!--
Encapsulamento: O encapsulamento é a prática de ocultar os detalhes de implementação de uma classe e expor apenas uma interface pública.

Isso é feito usando modificadores de acesso (public, private e protected) para controlar a visibilidade de atributos e métodos. O encapsulamento ajuda a aumentar a modularidade e a manutenibilidade do código.
-->

---

### Herança ###

- Criação de novas classes com base em classes existentes
- Reutilização e extensão de código

A herança é um mecanismo que permite criar uma nova classe a partir de uma classe existente. A nova classe (subclasse) herda os atributos e métodos da classe base (superclasse) e pode adicionar ou modificar atributos e métodos conforme necessário. A herança promove a reutilização de código e a organização hierárquica de classes.

---

### Polimorfismo ###

- Tratamento de diferentes objetos como um tipo comum
- Flexibilidade e reutilização de código

O polimorfismo é a capacidade de tratar diferentes objetos como se fossem do mesmo tipo. Em C++, o polimorfismo pode ser realizado através da herança e do uso de ponteiros e referências de classe base para acessar objetos de subclasses. Isso permite que um único código manipule diferentes tipos de objetos de maneira genérica e extensível.

---

### Abstração ###

- Simplifica problemas complexos
- Foca nas características essenciais

<!-- A abstração é a capacidade de simplificar problemas complexos, representando-os com modelos mais simples e genéricos. 

Isso permite que os desenvolvedores se concentrem nas características essenciais de um objeto ou sistema, ignorando os detalhes irrelevantes ou de baixo nível. -->

A abstração é fundamental na OOP, pois ajuda a organizar o código de maneira mais eficiente e a criar interfaces de alto nível que são mais fáceis de entender e usar.

---

### Composição ###

- Combinação de objetos para criar estruturas mais complexas
- Promove a modularidade e a reutilização de código

<!-- A composição é um princípio que permite criar objetos complexos combinando objetos mais simples. Em vez de herdar diretamente de uma classe base, a composição permite que você reutilize e estenda a funcionalidade de outras classes, incluindo-as como membros de uma nova classe. -->

A composição pode ser usada como uma alternativa à herança em muitos casos e oferece uma maior flexibilidade e modularidade ao projetar sistemas de software.

---

## Definições ##

- **Objeto**: Uma entidade que possui atributos (estado) e comportamentos (métodos). É uma instância concreta de uma classe.

- **Instância**: Uma ocorrência específica de um objeto, criada a partir de uma classe. Cada instância possui seus próprios atributos e pode executar os métodos definidos pela classe.

- **Classe**: Um modelo ou "blueprint" a partir do qual objetos são criados. Define os atributos e métodos comuns a todos os objetos dessa classe.

---

- **Atributo de classe**: Um valor ou propriedade que pertence à classe em si, em vez de a uma instância específica. Atributos de classe são geralmente compartilhados entre todas as instâncias de uma classe.

- **Propriedade de Objeto**: também conhecido como atributo de instância, um valor ou atributo associado a um objeto específico. As propriedades de objeto armazenam informações sobre o estado de um objeto e podem variar entre diferentes instâncias da mesma classe.

- **Método**: Uma função ou procedimento associado a uma classe ou objeto, que define um comportamento específico. Métodos operam nos atributos de uma instância e podem ser chamados para executar tarefas ou manipular os dados do objeto.
