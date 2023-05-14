---
marp: true
theme: gaia
paginate: true
backgroundColor: #fff
---

<!-- _class: lead -->

# Array Dinâmico #

Um array dinâmico em C é um array cujo tamanho pode ser alterado durante a execução do programa. Os arrays dinâmicos são criados usando ponteiros e funções de alocação de memória como malloc(), calloc() ou realloc(). Ao contrário dos arrays estáticos, cujo tamanho é fixo e determinado em tempo de compilação, os arrays dinâmicos permitem que você aloque e libere memória conforme necessário durante a execução do programa.

---

Exemplo de como criar e usar um array dinâmico em C:

```c

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    int *array_dinamico;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Alocando memória para o array dinâmico
    array_dinamico = (int *) malloc(tamanho * sizeof(int));

    // Verificando se a memória foi alocada corretamente
    if (array_dinamico == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    // Preenchendo o array dinâmico com valores
    for (int i = 0; i < tamanho; i++) {
        array_dinamico[i] = i + 1;
    }

    // Imprimindo os valores do array dinâmico
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array_dinamico[i]);
    }
    printf("\n");

    // Liberando a memória alocada para o array dinâmico
    free(array_dinamico);

    return 0;
}

```

---