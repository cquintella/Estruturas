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

# Novidades no Gerenciamento de Memória #

---

**new** e **delete** são operadores em C++ usados para alocar e desalocar memória dinamicamente no heap. Eles são uma evolução das funções malloc e free do C, mas oferecem melhorias significativas em termos de segurança e facilidade de uso.

**new**: **O operador new aloca memória no heap para armazenar um objeto do tipo especificado e retorna um ponteiro para o objeto**. Ele também chama o construtor do objeto para inicializá-lo. Isso é útil quando você precisa alocar memória dinamicamente, por exemplo, quando o tamanho do objeto é determinado em tempo de execução ou quando você precisa alocar recursos que persistem além do escopo da função.

Exemplo:

```c++

int* p = new int(10); // Aloca um novo inteiro no heap e inicializa com o valor 10.

```

---

**delete**: **O operador delete libera a memória alocada pelo operador new e chama o destrutor do objeto**. É importante liberar a memória alocada dinamicamente para evitar vazamentos de memória.

Exemplo:

```c++
delete p; // Libera a memória apontada por p.

```
