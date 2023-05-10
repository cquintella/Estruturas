---
marp: true
theme: gaia
paginate: true
backgroundColor: #fff
---

<!-- _class: lead -->

# Análise de Complexidade de Algoritmos: Big-O #

Professor: Carlos Alvaro Quintella

---

---

## Problema ##

- Comparar a eficiência de diferentes algoritmos em termos de tempo de execução e espaço utilizado
- Avaliar o comportamento do algoritmo quando o tamanho da entrada cresce para um valor muito grande

---

## Introdução ##

- A notação Big-O é uma forma de descrever a eficiência de um algoritmo em termos de **tempo de execução** ou **espaço utilizado**.
- Proposta por Ronald Knuth, autor dos livros "A Arte da Programação de Computadores".
- É uma medida assintótica, o que significa que **descreve o comportamento do algoritmo quando o tamanho da entrada cresce para um valor muito grande**.
- A notação Big-O é usada para expressar a complexidade de tempo ou espaço de um algoritmo como uma função do tamanho da entrada, denotada por n.

---

## Etimologia da palavra "assintótica" ##

- A palavra "assintótica" tem suas raízes no grego antigo, derivada da palavra grega "ἀσύμπτωτος" (asumptotos), que significa "não coincidente" ou "não se encontrando".
- No contexto da matemática, o termo "assintótico" é usado para descrever o comportamento de funções que se aproximam, mas nunca alcançam, um valor ou uma linha específica à medida que a variável independente tende ao infinito ou a algum limite específico.
- A linha ou o valor que a função se aproxima é chamado de "assíntota".

---

- **A análise assintótica, portanto, refere-se ao estudo do comportamento das funções à medida que elas se aproximam de seus limites ou assíntotas.**

---

## Exemplo ##

Um exemplo bem comum é uma busca sequencial. Quando estamos procurando um determinado valor único existênte dentro um arquivo sequencial ou lista, precisamos comparar cada elemento com o valor procurado até que o elemento seja encontrado.

- Com isso podemos ter no melhor caso o objeto encontrado na primeira comparação.
- Já o pior caso pode levar a comparação de todos os elementos, para só encontrar o desejado na última posição.
- Além disso temos o caso médio, onde é necessário comparar a metade dos elementos.

---

Assim, se temos 100 elementos no arquivo ou mesmo uma lista, precisamos de uma uma comparação no melhor caso, 100 comparações no pior caso e 50 no caso médio.

A situação complica se não se sabe se o elemento existe na lista.

---

## Classes de Complexidade ##

|Complexidade |Nome |Descrição
|---|---|---|
|O(1) |Constante vO |tempo de execução é constante, independentemente do tamanho da entrada.|
|O(log n)| Logarítmica | tempo de execução aumenta logaritmicamente com o tamanho da entrada.|
|O(n)| Linear |O tempo de execução é diretamente proporcional ao tamanho da entrada.|
---
|Complexidade |Nome |Descrição
|---|---|---|
|O(n log n) |Linearítmica (ou Quasilinear) |O tempo de execução aumenta linearmente e logaritmicamente com o tamanho da entrada.|
|O(n^2) |Quadrática vO | tempo de execução é proporcional ao quadrado do tamanho da entrada.|
|O(n^3) |Cúbica |O tempo de execução é proporcional ao cubo do tamanho da entrada.|

---

|Complexidade |Nome |Descrição
|---|---|---|
|O(n^k) |Polinomial (k > 1) |O tempo de execução é proporcional a uma potência do tamanho da entrada, onde k é uma constante maior que 1.|
|O(2^n) |vExponencial |O tempo de execução é proporcional a uma potência de 2 com o tamanho da entrada como expoente.|

---

|Complexidade |Nome |Descrição
|---|---|---|
|O(k^n) |vExponencial geral |O tempo de execução é proporcional a uma potência de k (uma constante) com o tamanho da entrada como expoente.
|O(n!) |Fatorial |O tempo de execução é proporcional ao fatorial do tamanho da entrada.|

---

A notação Big-O é amplamente usada para descrever a complexidade assintótica de um algoritmo, mas existem outras notações que complementam a análise de complexidade. 

* Duas dessas notações são a notação Teta (Θ) e a notação Ômega (Ω).

---

1. **Notação Teta (Θ):** Essa notação é usada quando queremos fornecer um limite assintótico superior e inferior para uma função, o que significa que a função está "limitada" por duas outras funções assintoticamente. Se uma função f(n) é Θ(g(n)), isso implica que existem constantes c1, c2 e n0, tais que para todo n ≥ n0, temos c1 * g(n) ≤ f(n) ≤ c2 * g(n). Em outras palavras, a notação Teta (Θ) fornece uma estimativa mais precisa da complexidade de tempo ou espaço de um algoritmo, indicando tanto o limite superior quanto o limite inferior.

---

2. **Notação Ômega (Ω):** Essa notação é usada para descrever o limite inferior assintótico de uma função. Se uma função f(n) é Ω(g(n)), isso significa que g(n) é um limite inferior para f(n), ou seja, a partir de um certo ponto, f(n) sempre será maior ou igual a g(n) multiplicado por uma constante. A notação Ômega (Ω) é útil para entender o pior caso de desempenho de um algoritmo em termos de tempo de execução ou espaço utilizado.

---

## Aplicando a Notação Big-O ##

Para aplicar a notação Big-O a um algoritmo, siga estas etapas:

1. Identifique a função que representa o tempo de execução ou espaço utilizado pelo algoritmo.
   - Isso geralmente envolve contar o número de operações ou a quantidade de memória necessária em relação ao tamanho da entrada.

2. Simplifique a função removendo constantes e termos de menor ordem.
   - A notação Big-O se concentra apenas no termo de maior ordem e ignora constantes multiplicativas, pois está preocupada com o comportamento assintótico.

3. Substitua a função simplificada pela notação Big-O.
   - Por exemplo, se a função simplificada for 3n^2 + 2n + 1, a notação Big-O será O(n^2), já que n^2 é o termo de maior ordem.

---

## Exemplo: Algoritmo de Ordenação por Seleção ##

O algoritmo de ordenação por seleção funciona selecionando iterativamente o menor elemento no restante da lista não ordenada e colocando-o no próximo índice não ordenado.

---

A complexidade de tempo do algoritmo de ordenação por seleção pode ser analisada da seguinte maneira:

1. No primeiro passo, o algoritmo compara n-1 elementos para encontrar o mínimo.
2. No segundo passo, o algoritmo compara n-2 elementos.
3. Continuando dessa forma, no passo i, o algoritmo compara n-i elementos.
4. No último passo, o algoritmo compara apenas 1 elemento.

---

Agora, some o número de comparações em cada passo para encontrar a função de tempo de execução:

(n - 1) + (n - 2) + ... + 1 = n(n - 1) / 2

Simplificando a função, temos:

n^2/2 - n/2

Neste caso, o termo de maior ordem é n^2, então a notação Big-O para o algoritmo de ordenação por seleção é O(n^2).

---

**Nota:** A notação Big-O fornece apenas uma estimativa aproximada do comportamento assintótico de um algoritmo. Ela não fornece informações sobre o desempenho real do algoritmo para entradas pequenas ou o tempo de execução exato. No entanto, é uma ferramenta útil para comparar a eficiência de diferentes algoritmos e ajudar a escolher a melhor solução para um problema específico.

---

## Recomendação de Vídeo ##

[Video Entrevista](https://www.youtube.com/watch?v=2BdBfsXbST8)
