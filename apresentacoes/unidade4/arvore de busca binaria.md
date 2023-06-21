---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Estruturas de Dados
theme: gaia
---

# Árvore Binária de Busca  #

Uma árvore binária de busca (Binary Search Tree - BST) é um tipo especial de árvore binária que segue uma propriedade específica.

Na BST, todos os nós à esquerda de um nó têm valores menores que o nó, e todos os nós à direita de um nó têm valores maiores que o nó. Essa propriedade deve ser verdadeira para todos os nós na árvore.

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