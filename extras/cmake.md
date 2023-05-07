# CMAKE #

O CMake é uma ferramenta de código aberto usada para gerar arquivos de configuração de compilação para diferentes sistemas operacionais e plataformas de desenvolvimento.

Com o CMake, é possível criar um arquivo de configuração único que descreve os detalhes do projeto, como os arquivos fonte, bibliotecas necessárias, flags de compilação, entre outros, e a partir dele gerar automaticamente os arquivos de configuração necessários para a compilação do projeto em diferentes plataformas.

---

Isso significa que, ao usar o CMake, você pode gerar facilmente um arquivo de configuração para o Visual Studio, para o Makefile do Unix, para o Xcode do macOS, entre outros. Isso torna o processo de compilação do projeto muito mais fácil e eficiente, pois você não precisa escrever manualmente os arquivos de configuração para cada plataforma em que deseja compilar o seu projeto.

---

## Como usar ##

O CMake é uma ferramenta de linha de comando, então é preciso acessar o terminal do seu sistema operacional para utilizá-lo. Aqui está um tutorial básico de como usar o CMake em um projeto C++:

Crie uma pasta para o seu projeto e acesse-a pelo terminal.

Crie um arquivo chamado CMakeLists.txt na raiz do seu projeto. Esse arquivo é onde você irá definir as instruções de compilação do seu projeto.

---

Abra o arquivo CMakeLists.txt em um editor de texto e adicione as seguintes linhas:

````text
cmake_minimum_required(VERSION 3.10)

project(nome_do_projeto)

add_executable(nome_do_executavel arquivo1.cpp arquivo2.cpp)
````

---

Substitua "nome_do_projeto" pelo nome do seu projeto e "nome_do_executavel" pelo nome do arquivo executável que será gerado a partir do código-fonte. Você também deve incluir todos os arquivos fonte que serão compilados.

---

Execute o CMake para gerar os arquivos de configuração. Para isso, execute o seguinte comando no terminal:

````bash
cmake .
````

Esse comando irá gerar os arquivos de configuração necessários para compilar o seu projeto.

---

Compile o seu projeto. Para isso, execute o seguinte comando no terminal:

````bash
make
````

Esse comando irá compilar o seu projeto e gerar o arquivo executável definido no arquivo CMakeLists.txt.

---

Execute o seu programa. Para isso, execute o seguinte comando no terminal:

````bash
./nome_do_executavel
````

Substitua "nome_do_executavel" pelo nome do arquivo executável definido no arquivo CMakeLists.txt.

---

Esses são os passos básicos para usar o CMake em um projeto C++. Há muitas outras instruções que podem ser adicionadas ao arquivo CMakeLists.txt para personalizar a compilação do seu projeto, como flags de compilação, bibliotecas adicionais, etc.
