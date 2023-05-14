---
marp: true
author: carlos.quintella@uva.br
background: white
paginate: true
footer: Estrutura de Dados
theme: gaia
---

<!-- _class: lead -->
![UVA 50% bg left:20%](https://uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

Professor: Carlos Alvaro Quintella

* Em C++, a classe string é uma classe de contêiner de sequência de caracteres que oferece uma maneira conveniente e eficiente de lidar com strings de texto. Ela já oferece recursos úteis, como operações de concatenação, pesquisa, extração de substrings, iteração de caracteres e muito mais.

_Nota_:A classe string é definida na biblioteca padrão de C++, string, que é incluída por padrão em programas C++.

---

Em comparação com a linguagem C, a manipulação de strings é muito mais fácil em C++. 

Em C, as strings são tratadas como matrizes de caracteres terminadas com um caractere nulo '\0'.

já em C++, a classe string fornece um conjunto completo de operações para lidar com strings de texto, o que torna o trabalho com strings muito mais fácil e seguro.

---

## Concatenação ##

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
  // criando duas strings
  string str1 = "Olá";
  string str2 = " mundo!";
  
  // concatenando as strings
  string str3 = str1 + str2;
  
  // imprimindo a string concatenada
  cout << str3 << endl;
  
  
  // outra maneira de concatenar as strings
  str1.append(" ");
  str1.append(str2);
  
  // mais uma maneira
  str2+=str1;

  // imprimindo a string concatenada novamente
  cout << str1 << endl;
  
  return 0;
}
```

---

## Pesquisa ##

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
  // criando uma string
  string str = "O rato roeu a roupa do rei de Roma";
  
  // encontrando a posição da primeira ocorrência de "roeu"
  int pos = str.find("roeu");
  if (pos != string::npos) {
    cout << "'roeu' encontrado na posição " << pos << endl;
  }
  
  // encontrando a posição da última ocorrência de "r"
  pos = str.rfind("r");
  if (pos != string::npos) {
    cout << "'r' encontrado na posição " << pos << endl;
  }
  
  return 0;
}
```

---

## Substring ##

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
  // criando uma string
  string str = "O rato roeu a roupa do rei de Roma";
  
  // extraindo um substring
  string sub = str.substr(2, 4);
  cout << "Substring: " << sub << endl;
  
  return 0;
}
```

---

## Operações de iteração de caracteres ##

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
  // criando uma string
  string str = "Hello World";
  
  // iterando sobre a string e imprimindo cada caractere
  for (char c : str) {
    cout << c << " ";
  }
  cout << endl;
  
  return 0;
}
```
