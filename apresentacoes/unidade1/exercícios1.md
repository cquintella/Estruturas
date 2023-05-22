# Exercícios - 1 #

- Professor: Carlos Alvaro Quintella
- Revisão: 27/02/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

## Exercícios de Vetores ##

Leia o arquivo de usuários do Linux, ele é o `/etc/passwd`, em um array de struct.

---

## Lendo Arquivos texto em cpp ##

Passo 1: Incluir a biblioteca necessária.

Para ler arquivos em C++, precisamos incluir a biblioteca <fstream>, que fornece classes e funções para manipulação de arquivos.

```cpp
#include <fstream>
```

---

Passo 2: Abrir o arquivo.
Antes de ler um arquivo, precisamos abri-lo. Vamos criar um objeto da classe ifstream e abrir o arquivo desejado. Veja um exemplo:

```cpp
std::ifstream arquivo("arquivo.txt");
if (arquivo.is_open()) {
    // Aqui vem o código para ler o arquivo
} else {
    // Tratamento de erro caso o arquivo não possa ser aberto
}
```



Nesse exemplo, arquivo.txt é o nome do arquivo que queremos ler. Verificamos se o arquivo foi aberto com sucesso usando o método is_open() da classe ifstream.

Passo 3: Ler o conteúdo do arquivo.
Agora que o arquivo está aberto, podemos ler o seu conteúdo. Existem várias maneiras de fazer isso. Vou mostrar duas abordagens comuns: lendo linha por linha ou lendo o arquivo inteiro.

Opção 1: Lendo linha por linha.

```c
std::string linha;
while (std::getline(arquivo, linha)) {
    // Processar cada linha do arquivo
}
```
Nesse exemplo, usamos o laço while em conjunto com a função getline() para ler o arquivo linha por linha. A cada iteração, a função getline() extrai uma linha do arquivo e a armazena na variável linha. Dentro do laço, você pode processar cada linha como desejar.

Opção 2: Lendo o arquivo inteiro.
```cpp
std::string conteudo((std::istreambuf_iterator<char>(arquivo)), std::istreambuf_iterator<char>());

```
Nessa abordagem, usamos um construtor especial da classe std::string para ler todo o conteúdo do arquivo de uma só vez. O construtor recebe dois iteradores: um que aponta para o início do arquivo (std::istreambuf_iterator<char>(arquivo)) e outro que aponta para o final do arquivo (std::istreambuf_iterator<char>()). O conteúdo completo do arquivo é armazenado na variável conteudo como uma string.

Passo 4: Fechar o arquivo.
Após concluir a leitura do arquivo, é importante fechá-lo para liberar os recursos do sistema. Podemos fazer isso chamando o método close() do objeto ifstream:

```cpp
arquivo.close();
```

Ao chamar close(), o arquivo é fechado e todas as operações de leitura são encerradas.

---

O arquivo /etc/passwd é um arquivo de texto que armazena informações sobre os usuários do sistema em sistemas operacionais baseados em Unix, como Linux e macOS. Cada linha do arquivo representa um usuário e contém várias informações separadas por dois-pontos (:). A seguir, explicarei o formato e o significado de cada campo presente no arquivo /etc/passwd:

```text
username:password:uid:gid:gecos:home_directory:shell
```

- username: É o nome de usuário (login) do usuário no sistema. Geralmente, é usado para identificar e autenticar o usuário durante o login.
- password: Anteriormente, esse campo continha a senha criptografada do usuário. No entanto, a maioria dos sistemas modernos armazena as senhas em um arquivo separado, como o /etc/shadow. Por padrão, o campo password agora é preenchido com um caractere x para indicar que a senha está em outro arquivo.
- uid: É o identificador único do usuário (User ID). É um número inteiro que identifica exclusivamente o usuário no sistema.
- gid: É o identificador único do grupo (Group ID) primário do usuário. É um número inteiro que identifica o grupo principal do usuário no sistema.
- gecos: É uma série de informações separadas por vírgulas que descrevem o usuário. Geralmente, essas informações incluem o nome completo do usuário e outros detalhes como número de telefone ou local de trabalho. No entanto, nem todos os sistemas usam todos os campos do gecos para esses fins.
- home_directory: É o diretório principal do usuário, onde ele armazena seus arquivos pessoais. Geralmente, é o diretório em que o usuário é direcionado após fazer login no sistema.
- shell: É o interpretador de linha de comando (shell) padrão para o usuário. Especifica qual shell será executado quando o usuário fizer login no sistema. Por exemplo, /bin/bash indica o Bash como o shell padrão.

Cada usuário do sistema é representado por uma linha no arquivo /etc/passwd, seguindo esse formato. O arquivo /etc/passwd é de leitura geralmente acessível apenas pelo usuário root ou por usuários com permissões administrativas. Ele é usado principalmente para fins de consulta e para obter informações básicas sobre os usuários do sistema.

```text
...
user3:x:1002:1002:User 3:/home/user3:/bin/bash
user4:x:1003:1003:User 4:/home/user4:/bin/bash
user5:x:1004:1004:User 5:/home/user5:/bin/bash
user6:x:1005:1005:User 6:/home/user6:/bin/bash
user7:x:1006:1006:User 7:/home/user7:/bin/bash
user8:x:1007:1007:User 8:/home/user8:/bin/bash
user9:x:1008:1008:User 9:/home/user9:/bin/bash
user10:x:1009:1009:User 10:/home/user10:/bin/bash
user11:x:1010:1010:User 11:/home/user11:/bin/bash
user12:x:1011:1011:User 12:/home/user12:/bin/bash
root:x:0:0:root:/root:/bin/bash
user1:x:1000:1000:User 1:/home/user1:/bin/bash
user2:x:1001:1001:User 2:/home/user2:/bin/bash
```

---

## struct para ler /etc/passwd ##

```cpp
struct UserInfo {
    std::string username;
    std::string password;
    int uid;
    int gid;
    std::string gecos;
    std::string homeDirectory;
    std::string shell;
};
```

---

## Solucao com array dinamico ##

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct UserInfo {
    std::string username;
    std::string password;
    int uid;
    int gid;
    std::string gecos;
    std::string homeDirectory;
    std::string shell;
};

// Função para ler o arquivo /etc/passwd e armazenar as informações em um vetor de structs UserInfo
std::vector<UserInfo> readPasswdFile(const std::string& filename) {
    std::vector<UserInfo> users;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string field;
        UserInfo user;

        // Extrai os campos da linha usando ':' como delimitador
        std::getline(iss, user.username, ':');
        std::getline(iss, user.password, ':');
        iss >> user.uid >> user.gid;
        std::getline(iss >> std::ws, user.gecos, ':');
        std::getline(iss, user.homeDirectory, ':');
        std::getline(iss, user.shell, ':');

        users.push_back(user);
    }

    file.close();
    return users;
}

// Função para imprimir as informações de um usuário
void printUserInfo(const UserInfo& user) {
    std::cout << "Username: " << user.username << std::endl;
    std::cout << "UID: " << user.uid << std::endl;
    std::cout << "GID: " << user.gid << std::endl;
    std::cout << "Gecos: " << user.gecos << std::endl;
    std::cout << "Home Directory: " << user.homeDirectory << std::endl;
    std::cout << "Shell: " << user.shell << std::endl;
    std::cout << "---------------------------" << std::endl;
}

// Função para imprimir as informações de todos os usuários
void printUsersInfo(const std::vector<UserInfo>& users) {
    for (const auto& user : users) {
        printUserInfo(user);
    }
}

int main() {
    const std::string passwdFile = "/etc/passwd";

    // Lê as informações do arquivo /etc/passwd
    std::vector<UserInfo> users = readPasswdFile(passwdFile);

    // Imprime as informações dos usuários
    printUsersInfo(users);

    return 0;
}
```

---

## Solucao com array Padrão C ##

```c
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct UserInfo {
    std::string username;
    std::string password;
    int uid;
    int gid;
    std::string gecos;
    std::string homeDirectory;
    std::string shell;
};

const int MAX_USERS = 100;  // Tamanho máximo do array de UserInfo

int readPasswdFile(UserInfo users[], const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int count = 0;  // Contador de usuários

    while (std::getline(file, line) && count < MAX_USERS) {
        std::istringstream iss(line);
        std::string field;

        // Extrai os campos da linha usando ':' como delimitador
        std::getline(iss, users[count].username, ':');
        std::getline(iss, users[count].password, ':');
        iss >> users[count].uid >> users[count].gid;
        std::getline(iss >> std::ws, users[count].gecos, ':');
        std::getline(iss, users[count].homeDirectory, ':');
        std::getline(iss, users[count].shell, ':');

        count++;
    }

    file.close();
    return count;  // Retorna o número de usuários lidos
}

void printUserInfo(const UserInfo& user) {
    std::cout << "Username: " << user.username << std::endl;
    std::cout << "UID: " << user.uid << std::endl;
    std::cout << "GID: " << user.gid << std::endl;
    std::cout << "Gecos: " << user.gecos << std::endl;
    std::cout << "Home Directory: " << user.homeDirectory << std::endl;
    std::cout << "Shell: " << user.shell << std::endl;
    std::cout << "---------------------------" << std::endl;
}

void printUsersInfo(UserInfo users[], int count) {
    for (int i = 0; i < count; i++) {
        printUserInfo(users[i]);
    }
}

int main() {
    const std::string passwdFile = "/etc/passwd";
    UserInfo users[MAX_USERS];

    // Lê as informações do arquivo /etc/passwd e retorna o número de usuários lidos
    int userCount = readPasswdFile(users, passwdFile);

    // Imprime as informações dos usuários
    printUsersInfo(users, userCount);

    return 0;
}
```




Exercícios de Ponteiros