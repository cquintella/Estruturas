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

# Smart Pointers #

---

Smart pointers são uma abordagem mais segura e automática para gerenciar memória em C++. Eles são objetos que se comportam como ponteiros, mas gerenciam a memória automaticamente, eliminando a necessidade de usar explicitamente new e delete.

Smart pointers ajudam a evitar erros comuns como vazamentos de memória e acesso a memória liberada.

Existem vários tipos de smart pointers em C++, incluindo:

---

unique_ptr: Um unique_ptr possui exclusivamente o objeto apontado e garante que apenas uma instância de unique_ptr possa possuir o objeto em questão. Quando um unique_ptr é destruído, ele libera automaticamente a memória do objeto apontado.

Exemplo:

```c++
std::unique_ptr<int> p1(new int(10)); // Aloca um novo inteiro no heap e o gerencia com um unique_ptr.
```

---

**shared_ptr**: Um shared_ptr permite que vários ponteiros compartilhem a propriedade de um objeto. Ele mantém um contador de referências, que é incrementado quando um novo shared_ptr aponta para o objeto e decrementado quando um shared_ptr é destruído. Quando o contador de referências chega a zero, o objeto é automaticamente liberado.

Exemplo:

```c++
std::shared_ptr<int> p2(new int(20)); // Aloca um novo inteiro no heap e o gerencia com um shared_ptr.
```

---

weak_ptr: Um weak_ptr é uma versão "fraca" do shared_ptr que não incrementa o contador de referências.

Ele é usado para prevenir referências circulares que podem causar vazamentos de memória. Um weak_ptr pode ser convertido em um shared_ptr temporário para acessar o objeto apontado.
