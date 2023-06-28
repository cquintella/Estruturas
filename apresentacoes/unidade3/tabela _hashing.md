# Tabela Hash

## Introdução

A tabela hash é uma estrutura de dados eficiente para armazenar e recuperar informações rapidamente.
    Também é conhecida como hash table, mapa hash, mapa de dispersão, entre outros nomes.

---

## Funcionamento

- A tabela hash utiliza uma função de dispersão (hash function) para mapear chaves em índices na tabela.
- A função de dispersão transforma a chave em um valor inteiro, que é usado como índice para acessar a tabela.
- O objetivo é distribuir as chaves de forma uniforme na tabela, minimizando colisões.

---

### Funcao de Dispersão ou Algoritmo de Hash

Um [algoritmo de hash](https://en.wikipedia.org/wiki/Hash_function) é uma função matemática que recebe um valor (entrada) e produz uma sequência de bits de tamanho fixo (saída), geralmente chamada de "hash", "_gigest_"ou "valor de hash". O objetivo principal de um algoritmo de hash é mapear dados de entrada de maneira eficiente e determinística, de modo que diferentes entradas resultem em valores de hash diferentes. Além disso, um bom algoritmo de hash deve ser rápido de calcular e ter uma distribuição uniforme dos valores de hash.

---

[Imagem função de dispersão bg](https://static.mundoeducacao.uol.com.br/mundoeducacao/2020/08/4-exemplo-4.jpg)

---

Existem vários algoritmos de função de dispersão disponíveis, cada um com suas próprias características e desempenho. Alguns exemplos comuns incluem:

---

### Função de Dispersão por Multiplicação

- Multiplica a chave por um fator de escala entre 0 e 1 e extrai a parte fracionária como valor de hash.

- Produz uma melhor distribuição dos valores de hash em comparação com a função de divisão. ex: (valor-minimo)/(maximo-minimo)

---

```pseudocode

função dispersãoPorMultiplicação(chave, tamanhoDaTabela):
constante A = (√5 - 1) / 2   // Constante de propagação
    valorMultiplicado = chave * A
    parteDecimal = valorMultiplicado - inteiro(valorMultiplicado)   // Obtém a parte decimal

    índice = inteiro(tamanhoDaTabela * parteDecimal)   // Calcula o índice na tabela

    retorne índice
```

---

### Função de Dispersão por Divisão

- Divide a chave pela capacidade da tabela e usa o resto da divisão como valor de hash.
- Simples de implementar, mas pode levar a colisões se a distribuição dos valores de entrada não for uniforme.

---

O processo de hashing por divisão envolve dividir o valor da chave pela quantidade de slots disponíveis na tabela hash e usar o resto da divisão da chave como o índice para armazenar o valor na tabela hash.

Por exemplo, se a chave for 20 e a tabela hash tiver 11 slots, o índice seria 20 % 10 = 9. O valor seria então armazenado no slot 9 da tabela hash.

Se a chave for uma string, vc pode somar cada letra e obter um número e obter o resto da divisão desse número.

---

```c

int hash_simples(char str[], int m) {
    int sum = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        sum += str[i];
    }
    return (sum % m);
}

```

---

Para chaves que são números, a técnica mais comum é o hashing modular, onde o tamanho do array é escolhido como um número primo e, para qualquer número inteiro positivo de chave k, é computado o resto da divisão de k por M. Se as chaves forem reais entre 0 e 1, pode-se multiplicá-las por M e arredondá-las para o inteiro mais próximo. Já para strings, pode-se tratar cada caractere como um número inteiro, computando o hash como um número grande.

Apesar da tabela de hash ocupar espaço de memória, ela não precisa guardar o registo inteiro, apenas o ponteiro para o registro desejado. Portanto, acaba valendo a pena trocar um pouco de memória pela possibilidade de acessar rapidamente o registro.

---

## Colisões

- Colisões ocorrem quando duas chaves diferentes são mapeadas para o mesmo índice na tabela.

Exemplo de colisão:

```text
Tabela de dispersão:
0: -> 18 -> 8
1: -> 11
2: -> 
3: -> 
4: -> 4 -> 14

Nesse exemplo, temos duas chaves diferentes (18 e 8) mapeadas para o índice 0 da tabela de dispersão. Essa situação é uma colisão de hash, pois ambas as chaves estão sendo mapeadas para o mesmo slot da tabela.
```

---

### Existem várias estratégias para lidar com colisões

- Encadeamento separado (chaining): cada posição da tabela é uma lista encadeada de elementos.

- Endereçamento aberto (open addressing): as colisões são resolvidas ao buscar por uma posição alternativa na tabela. Por exemplo: o primeiro espaço disponível.

- Duplo hashing

- Sondagem Quadrática

---

## Vantagens do Uso de Hash tables

- Acesso rápido aos elementos (complexidade média O(1)).
    Eficiente em termos de espaço (espaço adicional para lidar com colisões).
- Pode ser usado em uma ampla variedade de aplicações, como bancos de dados, caches, indexação, entre outros.

---

## Desvantagens Hash tables

- Sensível à qualidade da função de dispersão.
- Colisões podem impactar o desempenho.
- O tamanho da tabela precisa ser ajustado para otimizar o desempenho.

---

## Operações básicas

- Inserir: insere um par chave-valor na tabela.
- Buscar: recupera o valor associado a uma chave.
- Remover: remove um par chave-valor da tabela.

---

## Exemplos de uso:

- Bancos de dados: tabelas hash são usadas para indexar registros e acelerar a recuperação de informações.
- Linguagens de programação: as tabelas hash são amplamente usadas em estruturas de dados, como dicionários e conjuntos.
- Sistemas de cache: tabelas hash são usadas para armazenar dados frequentemente acessados em memória para acesso rápido.

---

## Um exemplo simples de como fazer hashing

Para exemplificar a construção de uma tabela hash com simbolos, suponha que tenhamos uma agenda telefonica em uma lista encadeada, hoje temos em torno de 500 contatos, com Nome, Sobrenome, telefone e e-mail. Suponha que precisemos fazer uma busca pelo telefone do Queiroz, teremos que em média procrirar 250 registros antes de encontrar se a lista não estiver ordenada.

---

```text
  (Lista encadeada)
       
    +--------------+--+    +--------------+--+    +--------------+--+    +--------------+--+
    |  Data  |  Next  | -> |  Data  |  Next  | -> |  Data  |  Next  | -> |  Data  |  Next  | -> NULL
    +-------------+---+    +-------------+---+    +-------------+---+    +-------------+---+
         !                      !                       !                      !
         V       0x120A         V       0x00A9          V      0x12B9          V     0x2234
    +-----------------+    +-----------------+    +-----------------+    +-----------------+
    | Queiroz         |    | Lugovi          |    | Raulzin         |    | Molina          |
    | Francisco       |    | Marcos          |    | Sonia           |    | Maria           |
    | 21 9922-1133    |    | 21 9922-1133    |    | 21 9922-1133    |    | 21 9922-1133    |
    | fqueiroz@gml.co |    | mlugo@cli.com   |    | Raul@riol.co    |    | Molin@trek.com  |
    +-----------------+    +-----------------+    +-----------------+    +-----------------+
```

---

```text
        int SIZE=8;
        registro_t *TABELA_HASH[SIZE];       FUNÇÃO e RETORNO
  indice    vetor     Memória
        +---------+
    (0) | 0x00A9  |  0x4001       hash(Lugovi)=0
    (1) | NULL    |  0x4002       
    (2) | NULL    |  0x4003
    (3) | 0x2234  |  0x4004       hash(Molina)=3
    (4) | 0x12B9  |  0x4005       hash(Raulzin)=4
    (5) | NULL    |  0x4006
    (6) | NULL    |  0x4007
    (7) | 0x120A  |  0x4008       hash(Queiroz)=7
        +---------+
```

---

## Busca Hash

Como vimos a técnica de hashing é um exemplo clássico de tradeoff entre tempo e espaço. Ela permite um equilíbrio razoável entre memória e tempo para realizar operações em tabelas de símbolos que requerem tempo constante por operação em situações típicas.

O algoritmo é eficiente para operações de inserção e pesquisa, pois usa a função hash para gerar um índice em tempo constante.

No entanto, o algoritmo é propenso a colisões, ou seja, vários elementos podem ter o mesmo índice gerado pela função hash. Para lidar com isso, existem vários mecanismos, como encadeamento e resolução linear.

---

## Conclusão

- Tabelas hash são estruturas de dados eficientes para armazenamento e recuperação rápida de informações.
- Elas são amplamente utilizadas em diversas áreas, desde bancos de dados até aplicações de programação.
- A compreensão dos princípios e técnicas envolvidas nas tabelas hash é fundamental para aproveitar seus benefícios e evitar problemas de desempenho.

---

## Links

[Hash table ande hash functions - Computer Science - YouTube](https://www.youtube.com/watch?v=KyUTuwz_b7Q)
[O que é hash](https://www.techtudo.com.br/noticias/2012/07/o-que-e-hash.ghtml)
[hashing, Geek 4 Geeks](https://www.geeksforgeeks.org/hash-functions-and-list-types-of-hash-functions/)
