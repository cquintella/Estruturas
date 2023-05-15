---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Curso de C++
theme: gaia
---

<!-- _class: lead -->

# CMake #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

CMake é uma plataforma de código aberto que permite a geração automática de arquivos de compilação. Ele é usado para controlar o processo de compilação de um software, usando arquivos de configuração simples e independentes de plataforma. O CMake pode gerar arquivos de compilação para várias plataformas e IDEs, incluindo Unix, Windows, macOS, MSVC, GCC, Clang, e outros.

---

## Por que usar o CMake? ##

O CMake é útil por várias razões:

1. **Independência de plataforma**: Você pode escrever um conjunto de instruções de compilação uma vez e usá-las em muitas plataformas diferentes.

2. **Geração automática de arquivos de compilação**: Isso economiza tempo, pois você não precisa escrever manualmente arquivos de compilação complexos.

---

3. **Integração com IDEs populares**: O CMake suporta muitos ambientes de desenvolvimento integrados (IDEs), o que facilita o uso do seu IDE favorito.

4. **Gestão de dependências**: O CMake pode automaticamente lidar com dependências entre diferentes partes do seu projeto.

---

## Como usar o CMake? ##

O CMake é controlado por arquivos de script chamados `CMakeLists.txt`. Estes scripts definem vários aspectos do seu projeto, incluindo onde estão os arquivos fonte, quais bibliotecas são necessárias, e como o projeto deve ser compilado.

Um exemplo básico de um arquivo `CMakeLists.txt` pode ser assim:

```text
cmake_minimum_required(VERSION 3.10)

project(MyProject)

add_executable(MyProject main.cpp)
```

---

Este script é bastante simples. Ele define a versão mínima requerida do CMake (3.10), o nome do projeto (MyProject), e adiciona um executável ao projeto (MyProject) que é compilado a partir do arquivo `main.cpp`.

Para usar este script, você deve criar um diretório de compilação (geralmente chamado `build`), navegar até ele, e então chamar o CMake com o diretório que contém o seu `CMakeLists.txt` como argumento:

```bash
mkdir build
cd build
cmake ..
```

---

Depois disso, você pode compilar o seu projeto. O comando exato depende do seu sistema e do gerador usado pelo CMake, mas para um gerador Unix Makefile, você pode usar o comando `make`.

```bash
make
```

