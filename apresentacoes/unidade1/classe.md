---
marp: true
theme: gaia
paginate: true
---

<!-- _class: lead -->

# Classe #

Professor: carlos Alvaro Quintella
08/04/2023

---

Uma classe em c++ é como um novo tipo tipo de dados criado pelo usuário.

alias já estamos acostumados a criar novos tipos de dados com _struct_.

uma classe define um tipo de dado que pode embutir outros dados e comportamento; no caso os comportamentos poderiam ser dados por funções. Com isso se ganha facilidade em criação do código e no processo de debugar.

Podemos construir uma classe com o conhecimento que já obtivemos por aqui.

---

## Simulando uma classe com struct ##

```cpp
#include <iostream>
#include <string>

struct Date {
    int day;
    int month;
    int year;
    
    void init(int d,int m,int  y){
        day=d;
        month=m;
        year=y;
    };
};


int main() {

Date minha_data;
minha_data.init(10,10,10);
std::string text_data=std::to_string(minha_data.day)+"/"+std::to_string(minha_data.month)+"/"+std::to_string(minha_data.year);
std::cout<<text_data<<std::endl;
}
```

Nesse exemplo, a função init está acessível e visível sempre que tivermos uma variável do tipo data. Acontece que um dos motivos da orientação a objetos é definir controle de acesso a determinadas funções dos objetos.

---

O que nos leva a parar para explicar o que é um objeto e o que é uma classe.

* Uma **classe** é um tipo de dado definido pelo programador que descreve um conjunto de propriedades e métodos. Por exemplo, se você estivesse criando um programa para uma loja de carros, poderia definir uma classe chamada Carro. Essa classe pode incluir propriedades como o modelo do carro, o ano de fabricação, a cor, a quilometragem e o preço. A classe também pode ter métodos, como ligar, desligar, acelerar e frear. A classe em si não contém dados reais, mas define a estrutura de um tipo de dados que pode ser usado para criar objetos.

---

* Um **objeto** é uma instância de uma classe. Você pode criar um objeto da classe Carro, por exemplo, que representa um carro específico. Cada objeto tem seu próprio conjunto de propriedades e métodos que foram definidos pela classe. Por exemplo, você pode criar um objeto _meuCarro_ da classe _Carro_ e definir suas propriedades para "Ford Mustang", "2018", "vermelho", "20000 km" e "$ 30.000". Você também pode chamar métodos para esse objeto, como ligar, acelerar e assim por diante.

---


