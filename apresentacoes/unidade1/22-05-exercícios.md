---
marp: true
---

# Exercícos #

Dado o seguinte trecho de código em C, qual será a saída do programa?

```c
#include <stdio.h>

void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    swap(a, b);
    printf("%d %d", a, b);
    return 0;
}

```

---

Qual é a diferença entre um ponteiro e uma variável regular em C? Quando você usaria um sobre o outro?

---

Considere a seguinte função recursiva em C:

```c
void print_numbers(int n) {
    if (n > 0) {
        print_numbers(n - 1);
        printf("%d ", n);
    }
}
```

Se chamarmos print_numbers(5), qual será a saída?

---

Dado o seguinte código em C:

```c
#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;

    printf("%d\n", *ptr);
    printf("%d\n", *(ptr + 1));
    printf("%d\n", *(ptr + 2));
    
    return 0;
}
```

---

Escreva uma função recursiva em C que retorne o n-ésimo número da sequência de Fibonacci. Considere que o primeiro e o segundo números da sequência são 0 e 1, respectivamente.

- A sequência de Fibonacci é uma sequência de números na qual cada número é a soma dos dois números anteriores. Ela começa geralmente por 0 e 1, seguido por 1, 2, 3, 5, 8, 13, 21, 34, e assim por diante.

```text
0, 1, 1, 2, 3, 5, 8, ... 

```

---

```c
#include <stdio.h>

// Função para imprimir os primeiros n números da sequência de Fibonacci
void imprimeFibonacci(int quantidadeNumeros) {
    int termo1 = 0, termo2 = 1, proximoTermo;

    for (int i = 1; i <= quantidadeNumeros; i++) {
        // Nas duas primeiras iterações, imprimimos os termos iniciais da sequência
        if (i == 1) {
            printf("%d, ", termo1);
            continue;
        }
        if (i == 2) {
            printf("%d, ", termo2);
            continue;
        }

        // Calculamos o próximo termo da sequência como a soma dos dois termos anteriores
        proximoTermo = termo1 + termo2;

        // Atualizamos os termos para a próxima iteração
        termo1 = termo2;
        termo2 = proximoTermo;

        printf("%d, ", proximoTermo);
    }
}

int main() {
    // Chamamos a função para imprimir os 10 primeiros números da sequência de Fibonacci
    imprimeFibonacci(10);

    return 0;
}
```
