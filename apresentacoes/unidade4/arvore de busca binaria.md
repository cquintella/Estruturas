A árvore de busca binária é um tipo abstrato de dado que representa uma árvore onde cada nó contém uma chave de busca e seus subnós da esquerda e da direita obedecem a certas condições.

Se todos os nós em todos os níveis, exceto o último, tivessem dois filhos, então haveria 1=2ˆ0 nó no nível 1, 2=2ˆ1 nós no nível 2, 4=2ˆ2 nós no nível 3 e, geralmente, 2^i nós no nível i + 1.

Uma árvore que satisfaça essa condição é chamada de árvore binária completa.

---

Essa é uma explicação de como seria a estrutura de uma árvore se todos os nós em todos os níveis, exceto o último, tivessem exatamente dois filhos. A quantidade de nós em cada nível segue uma progressão geométrica com base em 2. Então, se houver 1 nó no nível 1, haverá 2 nós no nível 2, 4 nós no nível 3 e assim por diante. A fórmula para encontrar o número de nós no nível i é 2^i.

**Para todas as árvores binárias não vazias cujos nós não-terminais têm exatamente dois filhos não vazios, o número de folhas m é maior que o número de nós não-terminais k e m = k + 1.** 
- Adam Drosdek.



Em uma árvore de busca binária, as chaves de busca são organizadas de tal maneira que as chaves menores são armazenadas no subnó da esquerda, enquanto as chaves maiores são armazenadas no subnó da direita. Isso significa que, para cada nó na árvore, todas as chaves em sua subárvore esquerda são menores que a chave do nó, e todas as chaves em sua subárvore direita são maiores.

A árvore de busca binária tem as seguintes operações definidas:

    insert(key): Insere uma chave na árvore de busca binária.
    delete(key): Remove uma chave da árvore de busca binária.
    search(key): Busca uma chave na árvore de busca binária.
    traverse(): Percorre a árvore de busca binária em uma determinada ordem (preorder, inorder, postorder, etc.).
    getMin(): Retorna a chave de menor valor na árvore.
    getMax(): Retorna a chave de maior valor na árvore.