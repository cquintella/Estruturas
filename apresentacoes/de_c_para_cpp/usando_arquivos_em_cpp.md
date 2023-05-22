---
marp: true
author: caquintella@gmail.com
backgroundColor: white
paginate: true
theme: gaia
footer: Linguagem de Programação C

---

<!-- _class: lead -->

# Usando arquivos em C++ #

- Professor: Carlos Alvaro Quintella
- Revisão: 27/02/2023

![bg 80% left:30%](https://www.uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

## NULL e nullptr ##

Em C++, NULL é uma macro que representa a constante de ponteiro nulo. 

Tradicionalmente, é usada em código estilo C para indicar que um ponteiro não aponta para um objeto válido. No entanto, NULL é apenas um alias para o literal inteiro 0. Isso às vezes pode levar a um código confuso ou propenso a erros, porque 0 não é um tipo de ponteiro.

No C++ moderno (especificamente, C++11 e posterior), existe uma nova palavra-chave, nullptr, que é uma constante de ponteiro nulo. Ela pode ser atribuída a qualquer tipo de ponteiro e não pode ser confundida acidentalmente com um tipo inteiro. Isso torna nullptr mais seguro e mais expressivo do que NULL.

```cpp
int* p = nullptr;  // p é um ponteiro nulo
```

Você pode usar nullptr em condicionais assim como NULL:

```cpp
if (p == nullptr) {
    // p não aponta para um objeto válido
}
```

Outra vantagem de nullptr sobre NULL é que ele tem seu próprio tipo, chamado std::nullptr_t. Isso significa que você pode usar nullptr em sobrecarga de função, onde diferentes implementações de função são selecionadas com base nos tipos de seus argumentos. Aqui está um exemplo:

```cpp
void foo(int) {
    std::cout << "int" << std::endl;
}

void foo(std::nullptr_t) {
    std::cout << "nullptr" << std::endl;
}

int main() {
    foo(NULL);  // Imprime "int"
    foo(nullptr);  // Imprime "nullptr"
}
```

Neste exemplo, foo(NULL) chama a versão int de foo, porque NULL é na verdade apenas 0. foo(nullptr) chama a versão nullptr_t de foo, porque nullptr tem o tipo std::nullptr_t.
