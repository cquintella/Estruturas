---
marp: true
author: carlos.quintella@uva.br
paginate: true
theme: gaia
---

<!-- _class: lead -->

# Vector c++ #

Vector é a versão do array dinamico em c++.

O vector em C++ é uma classe de contêiner que permite armazenar e manipular uma sequência dinâmica de elementos de mesmo tipo. É semelhante a um array, mas com tamanho variável e recursos adicionais, como inserção, exclusão e ordenação de elementos.

O funcionamento do vector é baseado em alocação dinâmica de memória. Quando um vector é criado, um bloco de memória é alocado para armazenar um número inicial de elementos. Quando mais elementos são adicionados ao vector, mais memória é alocada conforme necessário para acomodar os novos elementos. Da mesma forma, quando os elementos são removidos do vector, a memória alocada para esses elementos é liberada.

Os elementos armazenados em um vector podem ser acessados por meio de seus índices, que começam em zero. O acesso a elementos de um vector é tão rápido quanto o acesso a elementos de um array.

O vector também fornece vários métodos para manipular os elementos armazenados nele. Alguns desses métodos são:

- push_back(): adiciona um novo elemento ao final do vector
- pop_back(): remove o último elemento do vector
- insert(): insere um ou mais elementos em uma posição especificada no vector
- erase(): remove um ou mais elementos de uma posição especificada no vector
- clear(): remove todos os elementos do vector
- size(): retorna o número de elementos atualmente armazenados no vector
- capacity(): retorna o número máximo de elementos que podem ser armazenados no vector sem alocar mais memória

O vector também suporta vários tipos de inicialização e construção, incluindo inicialização por cópia, inicialização por lista, construção de vetor vazio, construção de vetor com tamanho específico e construção de vetor com valores padrão.

O vector é uma estrutura de dados extremamente útil em C++, porque fornece uma maneira fácil e eficiente de armazenar e manipular sequências dinâmicas de elementos. Ele é frequentemente usado em programas que lidam com grandes quantidades de dados, como aplicativos de processamento de imagem, aplicativos de análise de dados e aplicativos de jogos.