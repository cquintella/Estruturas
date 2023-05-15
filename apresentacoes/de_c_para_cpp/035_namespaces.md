---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
theme: gaia
---

<!-- _class: lead -->

# Como usar namespaces no C++ #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

Definindo um namespace:
Para criar um namespace, use a palavra-chave namespace seguida do nome desejado e um bloco de código entre chaves:

```cpp
namespace MeuNamespace {
    int calcular() {
        // Código da função calcular
    }
}
```

---

Usando elementos de um namespace:

Para acessar elementos de um namespace, você deve usar o operador de resolução de escopo :::

```cpp
int resultado = MeuNamespace::calcular();
```

---

Diretiva using:

Se você quiser usar elementos de um namespace sem precisar usar o operador de resolução de escopo, pode utilizar a diretiva using:

```cpp
using namespace MeuNamespace;

int resultado = calcular(); // Agora você pode chamar a função diretamente
```

---

No entanto, usar a diretiva using com muita frequência pode levar a conflitos de nomes, especialmente se você incluir muitos namespaces. Portanto, é recomendável usá-la com moderação.

---
Namespaces aninhados:
Você pode ter namespaces dentro de outros namespaces:

```cpp
namespace A {
    namespace B {
        int calcular() {
            // Código da função calcular
        }
    }
}

```

---

Para acessar a função calcular neste exemplo, use o operador de resolução de escopo duas vezes:

```cpp
int resultado = A::B::calcular();
```

---

Namespaces são uma parte importante da organização e estruturação do código em C++, e seu uso adequado pode ajudar a evitar conflitos de nomes e tornar o código mais legível e fácil de manter.

---

### pragma once ###

- Diretiva do pré-processador utilizada para evitar múltiplas inclusões de um mesmo arquivo de cabeçalho em um programa em C ou C++
- Garante que o arquivo de cabeçalho seja incluído apenas uma vez, mesmo que seja referenciado em diferentes partes do código
- Substituto da tradicional técnica de proteção de inclusão de arquivos de cabeçalho, que utiliza o ifndef, define e endif

Como utilizar pragma once?

-  Adicione a diretiva "#pragma once" na primeira linha do arquivo de cabeçalho, logo após a diretiva #ifndef

---

```c
#ifndef MEU_ARQUIVO_H
#define MEU_ARQUIVO_H

// código do arquivo de cabeçalho aqui

#endif
```

```c++
#pragma once

// código do arquivo de cabeçalho aqui
```

---

Vantagens de utilizar pragma once

- Maior facilidade e clareza no código
- Evita erros comuns de digitação ao definir os macros ifndef e define
-Melhora a legibilidade e a manutenibilidade do código
-Economiza tempo de compilação em projetos grandes, evitando a recompilação desnecessária de arquivos de cabeçalho já incluídos.

