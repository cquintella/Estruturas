---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
theme: gaia
---

<!-- _class: lead -->

<!-- _class: lead -->

# iostream #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

* iostream é uma biblioteca padrão em C++ que fornece funcionalidades de entrada e saída de fluxo (stream). 
* Define várias classes e objetos para lidar com operações de entrada e saída de forma abstrata, facilitando a manipulação de dados e interações com o usuário. 

---

### Algumas das classes e objetos mais importantes em iostream ###

**std::istream**: É uma classe que representa um fluxo de entrada de dados. Essa classe é usada para ler dados de uma fonte, como o teclado ou um arquivo. A biblioteca iostream fornece um objeto global chamado std::cin, que é uma instância de std::istream usada para ler dados do teclado.

---

**std::ostream**: É uma classe que representa um fluxo de saída de dados. Essa classe é usada para escrever dados em um destino, como a tela ou um arquivo.

A biblioteca iostream fornece dois objetos globais para lidar com a saída: **std::cout** e **std::cerr**. **std::cout** é uma instância de **std::ostream** usada para escrever dados na tela (saída padrão).

**std::cerr** é outra instância de std::ostream usada para escrever mensagens de erro na tela (saída de erro padrão).

---

**std::fstream**: É uma classe derivada de std::istream e std::ostream, usada para lidar com arquivos. Esta classe permite ler e escrever dados em arquivos, combinando as funcionalidades de entrada e saída de fluxo.

**std::stringstream**: É uma classe derivada de std::istream e std::ostream, usada para manipular strings como fluxos de entrada e saída. Com std::stringstream, é possível converter facilmente entre tipos de dados e strings, bem como concatenar e formatar strings.

---

A biblioteca iostream também fornece uma série de manipuladores de fluxo, como std::endl, std::setw, std::setprecision, entre outros, que podem ser usados para controlar a formatação e o comportamento dos fluxos de entrada e saída.

---

Exemplo simples de como usar iostream para ler e escrever dados:

```cpp
#include <iostream>

int main() {
    int number;

    // Ler um número inteiro do teclado usando std::cin
    std::cout << "Digite um número inteiro: ";
    std::cin >> number;

    // Escrever o número na tela usando std::cout
    std::cout << "O número digitado é: " << number << std::endl;

    return 0;
}
```

---

Neste exemplo, a biblioteca iostream é usada para ler um número inteiro do teclado e escrevê-lo na tela. A biblioteca simplifica a manipulação de entrada e saída de dados, tornando o código mais legível e fácil de entender.

---

Exemplo de manipulação de arquivo texto:

```c
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.txt";

    // Escrever em um arquivo de texto
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "Linha 1" << std::endl;
        outputFile << "Linha 2" << std::endl;
        outputFile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << " para escrita." << std::endl;
    }

    // Ler de um arquivo de texto
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << " para leitura." << std::endl;
    }

    return 0;
}
```

---

Exemplo: Arquivos binários com iostream

```c
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.txt";

    // Escrever em um arquivo de texto
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "Linha 1" << std::endl;
        outputFile << "Linha 2" << std::endl;
        outputFile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << " para escrita." << std::endl;
    }

    // Ler de um arquivo de texto
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << " para leitura." << std::endl;
    }

    return 0;
}
```
