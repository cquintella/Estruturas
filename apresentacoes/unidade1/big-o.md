---
marp: true
theme: gaia
paginate: true
backgroundColor: #fff
---

<!-- _class: lead -->

# Big-O #

## análise de complexidade de algoritmos ##

Professor: Carlos Alvaro Quintella

---

* A notação Big-O é uma forma de descrever a eficiência de um algoritmo em termos de **tempo de execução** ou **espaço utilizado**.

* É uma medida assintótica, o que significa que **descreve o comportamento do algoritmo quando o tamanho da entrada cresce para um valor muito grande**.
  
* A notação Big-O é usada para expressar a complexidade de tempo ou espaço de um algoritmo como uma função do tamanho da entrada, denotada por n.

---

## Etmologia da palavra "assintótica" ##

A palavra "assintótica" tem suas raízes no grego antigo, derivada da palavra grega "ἀσύμπτωτος" (asumptotos), que significa "não coincidente" ou "não se encontrando". A palavra é composta por duas partes: "ἀ-" (a), um prefixo que significa "não" ou "sem", e "σύμπτωτος" (sumptotos), que significa "coincidente" ou "que se encontra".

---

No contexto da matemática, o termo "assintótico" é usado para descrever o comportamento de funções que se aproximam, mas nunca alcançam, um valor ou uma linha específica à medida que a variável independente tende ao infinito ou a algum limite específico.

A linha ou o valor que a função se aproxima é chamado de "assíntota". **A análise assintótica, portanto, refere-se ao estudo do comportamento das funções à medida que elas se aproximam de seus limites ou assíntotas.**

---

## Classes de Complexidade ##

|Complexidade	|Nome	|Descrição
|---|---|---|
|O(1)	|Constante vO |tempo de execução é constante, independentemente do tamanho da entrada.
|O(log n)|	Logarítmica	| tempo de execução aumenta logaritmicamente com o tamanho da entrada.
|O(n)|	Linear	|O tempo de execução é diretamente proporcional ao tamanho da entrada.
O(n log n)	|Linearítmica (ou Quasilinear)	|O tempo de execução aumenta linearmente e logaritmicamente com o tamanho da entrada.
|O(n^2)	|Quadrática	vO | tempo de execução é proporcional ao quadrado do tamanho da entrada.
|O(n^3)	|Cúbica	|O tempo de execução é proporcional ao cubo do tamanho da entrada.
O(n^k)	|Polinomial (k > 1)	|O tempo de execução é proporcional a uma potência do tamanho da entrada, onde k é uma constante maior que 1.
O(2^n)	|vExponencial	|O tempo de execução é proporcional a uma potência de 2 com o tamanho da entrada como expoente.
|O(k^n)	|vExponencial geral	|O tempo de execução é proporcional a uma potência de k (uma constante) com o tamanho da entrada como expoente.
|O(n!)	|Fatorial	|O tempo de execução é proporcional ao fatorial do tamanho da entrada.|

---


Para aplicar a notação Big-O a um algoritmo, siga estas etapas:

1- Identifique a função que representa o tempo de execução ou espaço utilizado pelo algoritmo.

* Isso geralmente envolve contar o número de operações ou a quantidade de memória necessária em relação ao tamanho da entrada.

2- Simplifique a função removendo constantes e termos de menor ordem.

* A notação Big-O se concentra apenas no termo de maior ordem e ignora constantes multiplicativas, pois está preocupada com o comportamento assintótico.

---

3- Substitua a função simplificada pela notação Big-O.

* Por exemplo, se a função simplificada for 3n^2 + 2n + 1, a notação Big-O será O(n^2), já que n^2 é o termo de maior ordem.

---

## Exemplo ##

Vamos aplicar a notação Big-O a um exemplo: o algoritmo de ordenação por seleção.

O algoritmo de ordenação por seleção funciona selecionando iterativamente o menor elemento no restante da lista não ordenada e colocando-o no próximo índice não ordenado.

---

A complexidade de tempo do algoritmo de ordenação por seleção pode ser analisada da seguinte maneira:

No primeiro passo, o algoritmo compara n-1 elementos para encontrar o mínimo.
No segundo passo, o algoritmo compara n-2 elementos.
Continuando dessa forma, no passo i, o algoritmo compara n-i elementos.
No último passo, o algoritmo compara apenas 1 elemento.
Agora, some o número de comparações em cada passo para encontrar a função de tempo de execução:

(n - 1) + (n - 2) + ... + 1 = n(n - 1) / 2

---

Simplificando a função, temos:

n^2/2 - n/2

Neste caso, o termo de maior ordem é n^2, então a notação Big-O para o algoritmo de ordenação por seleção é O(n^2).

---

Lembre-se de que a notação Big-O fornece apenas uma estimativa aproximada do comportamento assintótico de um algoritmo. Ela não fornece informações sobre o desempenho real do algoritmo para entradas pequenas ou o tempo de execução exato. No entanto, é uma ferramenta útil para comparar a eficiência de diferentes algoritmos e ajudar a escolher a melhor solução para um problema específico.
