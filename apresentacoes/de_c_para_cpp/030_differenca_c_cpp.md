---
marp: true
author: carlos.quintella@uva.br
paginate: true
backgroundColor: white
theme: gaia
---

<!-- _class: lead -->

# Diferenças entre C e C++ #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

Um programas C++ tem a seguinte estrutura:

```text

Inclusão de bibliotecas

Definição de namespace

definição de constantes

funções 

int main()
{
declaração de variáveis 
....
sentenças
....
}

```

---

C e C++ são ambas linguagens de programação que **compartilham muitas semelhanças**, já que C++ foi derivado de C. No entanto, existem várias diferenças-chave entre as duas linguagens:

- **Programação Orientada a Objetos**: C++ é uma linguagem de programação orientada a objetos, enquanto C não é. C++ suporta classes, encapsulamento, herança e polimorfismo, permitindo um código mais modular, organizado e reutilizável.

- **Templates**: C++ possui o conceito de templates, que permite a programação genérica. Já o C não possui templates, o que significa que pode ser mais difícil escrever código genérico.

---

- **Biblioteca Padrão**: C++ possui uma biblioteca padrão que fornece uma variedade de funcionalidades úteis, incluindo entrada/saída, estruturas de dados, algoritmos e funções matemáticas. C não possui uma biblioteca padrão com a mesma gama de funcionalidades.

- **Gerenciamento de Memória**: C++ oferece a capacidade de gerenciar memória através do uso dos operadores new e delete, e também fornece smart pointers para ajudar a gerenciar a memória automaticamente.

_O C não possui o mesmo nível de suporte para gerenciamento de memória, o que pode tornar mais difícil o gerenciamento de memória_.

---

- **Verificação de tipo**: C++ é uma linguagem fortemente tipada, o que significa que as variáveis devem ser declaradas com seus tipos de dados antes de poderem ser usadas. O C é uma linguagem fracamente tipada, o que significa que as variáveis podem ser usadas sem declaração prévia ou verificação de tipo.

- **Function Overloading**: C++ allows for function overloading, which means that multiple functions can have the same name, but with different parameter lists. C does not support function overloading.

- **Exception Handling**: C++ supports exception handling, which means that runtime errors can be handled in a structured way, allowing for more robust and reliable code. C does not have built-in support for exception handling.

---

## Tipos de arquivo ##

- **Arquivos de código-fonte (source files)**: Os arquivos de código-fonte possuem a extensão .cpp e contêm a implementação real das classes, funções e outros elementos definidos nos arquivos de cabeçalho. Esses arquivos são responsáveis por escrever o código executável e são compilados pelo compilador C++ para gerar o programa final.

- **Arquivos de cabeçalho (header files)**: Os arquivos de cabeçalho têm a extensão .hpp ou .h e são usados para declarar as definições de classes, funções, variáveis e outros elementos que serão utilizados em vários arquivos de código-fonte. Esses arquivos fornecem as interfaces e as declarações dos elementos, permitindo que outros arquivos de código-fonte incluam e usem essas definições. A separação entre a interface (arquivos de cabeçalho) e a implementação (arquivos de código-fonte) ajuda a organizar e modularizar o código.

Além desses dois tipos principais de arquivos, também poemos citar:

- **Arquivos de biblioteca (library files)**: São arquivos que contêm implementações de funções, classes e outros elementos que podem ser usados por vários programas. Esses arquivos são compilados separadamente e podem ser vinculados aos programas durante o processo de compilação para fornecer funcionalidades pré-definidas.

---

## A biblioteca padrão do C++ ##

(também conhecida como STL - Standard Template Library) é uma extensão e evolução da biblioteca padrão do C. 

Enquanto ambas as bibliotecas fornecem funcionalidades básicas para programação, a biblioteca padrão do C++ é mais rica em recursos e funcionalidades.

---

Aqui estão algumas diferenças entre as bibliotecas padrão do C e do C++:

**Estruturas de Dados**: A biblioteca padrão do C++ inclui uma ampla variedade de estruturas de dados, como vetores, listas, conjuntos e mapas, que são implementados como classes genéricas.

Isso permite a criação e manipulação de estruturas de dados complexas de maneira eficiente e reutilizável.

_A biblioteca padrão do C oferece apenas algumas estruturas de dados básicas, como arrays e structs_.

---

**Algoritmos**: A biblioteca padrão do C++ fornece uma ampla gama de algoritmos predefinidos, como busca, ordenação, operações matemáticas e manipulação de strings. Estes algoritmos são implementados como funções genéricas que podem ser aplicadas a qualquer tipo de dado compatível.

_A biblioteca padrão do C possui um conjunto limitado de algoritmos, e muitas vezes os programadores precisam implementar algoritmos do zero ou usar bibliotecas de terceiros_.

---

**Funções de Entrada/Saída (I/O)**: A biblioteca padrão do C++ oferece recursos avançados de entrada e saída, como fluxos de arquivos e manipulação de strings. Esses recursos permitem uma manipulação mais simples e eficiente dos dados de entrada e saída.

_A biblioteca padrão do C possui funções básicas de I/O, como printf e scanf, que são menos flexíveis e mais propensas a erros_.

---

**Gerenciamento de Memória**: C++ inclui suporte para gerenciamento de memória através dos operadores new e delete, além de smart pointers, que facilitam o gerenciamento automático de memória e reduzem a possibilidade de vazamentos de memória.

_A biblioteca padrão do C fornece funções básicas de alocação de memória, como malloc e free, mas não oferece suporte a smart pointers_.

---

**Compatibilidade com Orientação a Objetos**: A biblioteca padrão do C++ foi projetada para ser compatível com a programação orientada a objetos e aproveitar os recursos do C++ nesse sentido.

Isso permite que as classes e objetos da biblioteca padrão do C++ sejam facilmente integrados e estendidos em programas orientados a objetos.

_A biblioteca padrão do C não tem suporte a orientação a objetos e é baseada em funções e procedimentos_.

---

## Namespaces ##

É uma maneira de organizar e agrupar identificadores (como variáveis, funções e classes) sob um mesmo nome. Eles ajudam a evitar conflitos entre nomes e facilitam a organização do código, especialmente em projetos maiores.

---

Imagine que você está trabalhando em um projeto com outras pessoas, e ambos criam uma função chamada "calcular". Sem namespaces, haverá um conflito de nomes, e o compilador não saberá qual função usar. Namespaces resolvem esse problema encapsulando funções, variáveis e classes dentro de um escopo específico.

_No C era comum se colocar um prefixo nas funções, como ocorre ainda no Mac OSX; onde as chamadas de API começam com NS (de Next Step - era a empresa do Steve Jobs que estava desenvolvendo o OS que virou o Mac OSX)_.

---

### #pragma once ###

Using #pragma once ensures that the header file is included only once and avoids these issues. It is supported by most modern compilers and is a simple and efficient way to prevent multiple inclusions of the same header file.

---

## Templates ##

Em C++, templates são um recurso poderoso que permite escrever código genérico que pode funcionar com vários tipos diferentes. Os templates permitem escrever o código uma vez e usá-lo com muitos tipos diferentes sem a necessidade de código repetitivo.

Um template é basicamente um modelo para criar uma função ou classe genérica. O código do template é escrito de uma forma que é independente de qualquer tipo de dados específico, e o tipo de dados real é especificado quando o template é instanciado.

---

Por exemplo, aqui está uma simples função template que encontra o valor máximo de dois valores:

```cpp
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

Neste exemplo, a palavra-chave typename é usada para definir um parâmetro de template T, que pode representar qualquer tipo. A função tem dois parâmetros do tipo T e retorna o valor máximo dos dois valores.

---

Para usar essa função template, você precisa instanciá-la com um tipo específico:

```cpp
int a = 5, b = 10;
int max_value = max<int>(a, b); // instancia a função max com o tipo int

double c = 3.14, d = 2.71;
double max_double = max<double>(c, d); // instancia a função max com o tipo double

```

Neste exemplo, a função template max é instanciada com os tipos int e double, e retorna o valor máximo dos dois parâmetros.

---

Os templates também podem ser usados para criar classes genéricas, que podem trabalhar com vários tipos de dados. Por exemplo, uma classe genérica vector pode armazenar qualquer tipo de dados, e é criada usando um template:

```cpp
template<typename T>
class vector {
    // código da classe
};
```

Neste exemplo, a classe vector é criada usando um parâmetro de template T, que pode representar qualquer tipo. O tipo de dados real é especificado quando a classe vector é instanciada.

---

No geral, os templates são um recurso poderoso do C++ que permite escrever código genérico que pode funcionar com muitos tipos diferentes, sem a necessidade de código repetitivo. Eles são amplamente usados na biblioteca padrão do C++ e em muitas outras bibliotecas e frameworks.

---

Function overloading no C++ é uma característica que permite que você tenha várias funções com o mesmo nome, mas com diferentes listas de parâmetros (tipo e/ou quantidade de parâmetros). O compilador seleciona a função correta com base nos argumentos fornecidos na chamada da função. Isso permite que você crie várias versões de uma função com o mesmo nome, mas com comportamentos diferentes, dependendo dos argumentos passados.

Aqui está um exemplo simples de function overloading:

```cpp
#include <iostream>

// Função "somar" que aceita dois inteiros e retorna a soma deles
int somar(int a, int b) {
    return a + b;
}

// Função "somar" sobrecarregada que aceita três inteiros e retorna a soma deles
int somar(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int resultado1 = somar(3, 4); // Chama a primeira versão da função "somar"
    int resultado2 = somar(3, 4, 5); // Chama a segunda versão da função "somar"

    std::cout << "Resultado1: " << resultado1 << std::endl; // Exibe "Resultado1: 7"
    std::cout << "Resultado2: " << resultado2 << std::endl; // Exibe "Resultado2: 12"

    return 0;
}
```

---

## std::string ##

A classe std::string é uma parte da biblioteca padrão do C++ e fornece uma maneira conveniente e segura de trabalhar com strings. Em contraste, no C, as strings são representadas como arrays de caracteres terminados por um caractere nulo ('\0').

---

Aqui estão algumas diferenças e vantagens da classe std::string em relação às strings baseadas em arrays de caracteres no C:

- Gerenciamento de memória automático: Com a classe std::string, o gerenciamento de memória é feito automaticamente. Você não precisa se preocupar com a alocação e liberação de memória para armazenar as strings. No C, você deve gerenciar a memória manualmente usando funções como malloc, calloc, realloc e free.

---

- Redimensionamento dinâmico: A classe std::string pode ser redimensionada automaticamente conforme necessário. Isso significa que, quando você adiciona ou remove caracteres de uma string, a memória alocada é ajustada dinamicamente. No C, você precisa redimensionar manualmente o array de caracteres usando realloc ou gerenciá-lo por conta própria.

---

- Manipulação conveniente de strings: A classe std::string fornece várias funções e operadores para facilitar a manipulação de strings, como concatenação, comparação, busca, inserção e remoção de caracteres:
- Concatenar (juntar) strings: operador + ou a função append() para concatenar strings.
- substr() juntamente com a função find() para encontrar a posição do delimitador.
- Para copiar strings em C++, operador de atribuição = ou a função assign()

---

```c
#include <iostream>
#include <string>

int main() {
    std::string str = "Olá, mundo!";

    // Copiando strings usando o operador =
    std::string copia1 = str;
    std::cout << "Cópia 1: " << copia1 << std::endl;

    // Copiando strings usando a função assign()
    std::string copia2;
    copia2.assign(str);
    std::cout << "Cópia 2: " << copia2 << std::endl;

    return 0;
}
```

---

```c
#include <iostream>
#include <string>

int main() {
    std::string str = "Olá, mundo!";
    std::string delimiter = ", ";

    // Encontrando a posição do delimitador
    size_t pos = str.find(delimiter);

    // Dividindo a string usando a função substr()
    std::string part1 = str.substr(0, pos);
    std::string part2 = str.substr(pos + delimiter.length());

    std::cout << "Parte 1: " << part1 << std::endl;
    std::cout << "Parte 2: " << part2 << std::endl;

    return 0;
}
```

```c

#include <iostream>
#include <string>

int main() {
    std::string str1 = "Olá, ";
    std::string str2 = "mundo!";

    // Concatenando strings usando o operador +
    std::string resultado1 = str1 + str2;
    std::cout << resultado1 << std::endl;

    // Concatenando strings usando a função append()
    std::string resultado2 = str1;
    resultado2.append(str2);
    std::cout << resultado2 << std::endl;

    return 0;
}

```

---

- Segurança: Trabalhar com a classe std::string é geralmente mais seguro do que usar arrays de caracteres no C, porque a classe std::string gerencia a memória automaticamente e evita problemas comuns, como estouro de buffer (buffer overflow).

---

Aqui está um exemplo de como criar e manipular strings usando std::string no C++:

```cpp
#include <iostream>
#include <string>

int main() {
    // Criando uma string
    std::string str1 = "Olá, ";
    std::string str2 = "mundo!";

    // Concatenando strings
    std::string str3 = str1 + str2;

    // Exibindo a string resultante
    std::cout << str3 << std::endl;

    return 0;
}
```

---

### Estruturas de dados na Standard Template Library ###

A Standard Template Library (STL) é uma biblioteca fundamental em C++ que fornece várias classes e funções genéricas para facilitar a manipulação de dados e algoritmos. A STL é composta por três componentes principais: containers, iterators e algorithms.

---

**Containers**: Containers são estruturas de dados genéricas que armazenam e organizam coleções de objetos. Eles fornecem uma maneira de gerenciar conjuntos de dados de forma eficiente e abstrata. Os containers são classificados em duas categorias: containers sequenciais e containers associativos.

- **Containers sequenciais**, como std::vector, std::list e std::deque, armazenam os elementos em uma sequência linear. Eles permitem o acesso rápido e eficiente a elementos em uma ordem específica.

---

**Containers associativos**, como std::set, std::map, std::multiset e std::multimap, armazenam elementos com base em chaves e permitem pesquisas rápidas e inserções ordenadas. Esses containers são geralmente implementados usando árvores binárias de busca ou tabelas hash.

**Iterators**: Iterators são objetos que fornecem uma maneira unificada e genérica de acessar e percorrer elementos em um container. Eles funcionam como ponteiros para elementos e permitem que os algoritmos funcionem com diferentes tipos de containers sem precisar conhecer os detalhes de implementação desses containers.

---

A STL fornece vários tipos de iterators, como input iterators, output iterators, forward iterators, bidirectional iterators e random-access iterators, cada um com diferentes capacidades e restrições de uso. Os iterators são uma parte fundamental da STL, pois permitem que os algoritmos sejam genéricos e reutilizáveis.

---

```c
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Usando iterator para percorrer um std::vector
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

---

```c
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mp = {{"one", 1}, {"two", 2}, {"three", 3}};

    // Usando iterator para percorrer um std::map
    for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
````

---

**Algorithms**: Algorithms são funções genéricas que realizam operações comuns e úteis em containers, como pesquisar, ordenar, copiar e transformar elementos. A maioria dos algoritmos da STL é projetada para trabalhar com iterators, o que os torna independentes dos detalhes de implementação dos containers e amplamente aplicáveis a diferentes tipos de dados.

A STL inclui uma variedade de algoritmos, como std::sort, std::find, std::count, std::accumulate, std::transform, e muitos outros. Esses algoritmos são otimizados para eficiência e permitem que os desenvolvedores resolvam problemas complexos de forma rápida e elegante.

---

O C++ oferece várias estruturas de dados na Standard Template Library (STL) para facilitar a manipulação e armazenamento de dados.

- **std::vector**: É uma classe de array dinâmico que pode redimensionar-se automaticamente quando novos elementos são inseridos ou removidos. Os elementos são armazenados de forma contígua na memória, o que torna o acesso aos elementos muito rápido. Entretanto, inserções e remoções no meio do vetor podem ser lentas devido à movimentação dos elementos. É a estrutura de dados mais usada quando você precisa de acesso aleatório rápido aos elementos.
Exemplo de uso do std::vector:

---

```cpp

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vetor = {1, 2, 3, 4, 5};

    vetor.push_back(6); // Adicionando um elemento ao final do vetor

    for (int num : vetor) {
        std::cout << num << " ";
    }

    return 0;
}
```

---

- **std::list**: É uma classe de lista duplamente encadeada, onde cada elemento mantém ponteiros para os elementos anterior e seguinte. As inserções e remoções de elementos são rápidas, pois não exigem a movimentação dos outros elementos. No entanto, o acesso aleatório aos elementos é mais lento em comparação com std::vector, pois requer a travessia da lista.
Exemplo de uso do std::list:

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lista = {1, 2, 3, 4, 5};

    lista.push_back(6); // Adicionando um elemento ao final da lista

    for (int num : lista) {
        std::cout << num << " ";
    }

    return 0;
}

```

---

- **std::deque**: É uma classe de fila dupla (double-ended queue), que permite a inserção e remoção eficiente de elementos tanto no início quanto no fim.

A deque é implementada como uma série de blocos de memória não contíguos, o que torna o acesso aos elementos um pouco mais lento em comparação com std::vector, mas mais rápido que std::list.
Exemplo de uso do std::deque:

```cpp

#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3, 4, 5};

    deq.push_front(0); // Adicionando um elemento ao início da deque
    deq.push_back(6);  // Adicionando um elemento ao final da deque

    for (int num : deq) {
        std::cout << num << " ";
    }

    return 0;
}
```

---

- **std::set**: É uma classe de conjunto baseada em árvores balanceadas (geralmente árvores binárias de busca auto-balanceadas, como árvores AVL ou árvores vermelho-preto). Armazena elementos únicos e ordenados. A inserção, remoção e busca de elementos têm complexidade logarítmica O(log n).

---

**std::set** e **std::map** são duas estruturas de dados da Standard Template Library (STL) em C++ que armazenam elementos ordenados e fornecem acesso rápido aos elementos.

Ambas as estruturas são geralmente implementadas usando árvores balanceadas (como árvores AVL ou árvores vermelho-preto), o que garante uma complexidade de tempo logarítmico O(log n) para operações de inserção, remoção e busca.

**std::set**: É uma classe de conjunto que armazena elementos únicos e ordenados. Como os elementos são únicos, cada elemento aparece apenas uma vez no conjunto. A principal vantagem do std::set é que ele mantém os elementos automaticamente ordenados, o que é útil para operações que dependem da ordem dos elementos. Além disso, o std::set permite buscar, inserir e remover elementos de forma eficiente.

---

Exemplo de uso do std::set:

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> conjunto;

    conjunto.insert(5);
    conjunto.insert(3);
    conjunto.insert(1);
    conjunto.insert(4);

    for (int num : conjunto) {
        std::cout << num << " ";
    }

    return 0;
}
```

---

std::map: É uma classe de dicionário que armazena pares de chave-valor ordenados por chave. Como as chaves são únicas, cada chave pode estar associada a apenas um valor no mapa. O std::map é útil quando você precisa associar valores a chaves específicas e realizar buscas, inserções e remoções de pares de chave-valor de maneira eficiente.
Exemplo de uso do std::map:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mapa;

    mapa["um"] = 1;
    mapa["dois"] = 2;
    mapa["tres"] = 3;
    mapa["quatro"] = 4;

    // Acessando o valor associado à chave "dois"
    std::cout << "A chave 'dois' corresponde ao valor " << mapa["dois"] << std::endl;

    // Iterando pelos pares de chave-valor no mapa
    for (const auto& par : mapa) {
        std::cout << "Chave: " << par.first << ", Valor: " << par.second << std::endl;
    }

    return 0;
}
```

Neste exemplo, criamos um std::map que associa strings a inteiros. Inserimos alguns pares de chave-valor no mapa e, em seguida, iteramos pelos pares, imprimindo as chaves e os valores. Observe que o std::map mantém os pares ordenados por chave.

---

## Operador ternário ##

```cpp
(a > b) ? a : b;
```

Essa notação é chamada de operador ternário ou condicional, e é usada para avaliar uma condição e retornar um valor com base no resultado da condição. A notação é a seguinte:

Ou seja, a expressão avalia a condição, se ela for verdadeira, o valor após o ponto de interrogação é retornado, caso contrário, o valor após os dois pontos é retornado.

---

No exemplo:

```cpp
(a > b) ? a : b;
```

A expressão avalia se a é maior do que b. Se essa condição for verdadeira, a expressão retorna o valor de a, caso contrário, ela retorna o valor de b. Essa expressão pode ser lida como "se a for maior que b, retorne a, caso contrário, retorne b".

Essa notação é útil em situações em que você precisa escolher entre dois valores com base em uma condição, e é frequentemente usada em C++ e outras linguagens de programação.

---

### Exercício ###

Escreva um programa que leia dois números inteiros do usuário e **use o operador ternário** para determinar qual é o maior número. O programa deve imprimir na tela qual é o número maior.

---

```cpp
#include <iostream>

int maior(int a, int b){
    return (a > b) ? a : b;
}

int main() {
    int a = 10;
    int b = 100;
    std::cout << maior(a, b);
    return 0;
}
```

---

## Links ##

[Vectors C++](https://www.youtube.com/watch?v=TaySu61K6dI&list=PLYnrabpSIM--J2A1gsBmgjHfp9g9rb7vu&index=5)

[Notas de Aula UFPR](https://www.inf.ufpr.br/ci208/NotasAula.pdf)
