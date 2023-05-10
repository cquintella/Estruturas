---
marp: true
author: carlos.quintella@uva.br
backgroundColor: black
paginate: true
theme: gaia
---

<!-- class: invert -->
<!-- _class: lead -->
<!-- _color: white -->

# Lista de Exercícios de Ponteiros #

---

1- Introdução aos ponteiros: Escreva um programa que declare uma variável inteira e um ponteiro para inteiro. Atribua o endereço da variável inteira ao ponteiro e imprima o valor e o endereço da variável inteira usando o ponteiro.

---

2- Manipulação de ponteiros: Escreva um programa que declare dois ponteiros e um array de inteiros. Utilize os ponteiros para percorrer o array, imprimindo seus elementos e endereços.

---

3- Troca de valores usando ponteiros: Escreva uma função que receba dois ponteiros para inteiros e troque os valores das variáveis apontadas pelos ponteiros.

---

4- Ponteiros para funções: Escreva um programa que declare um array de ponteiros para funções. Cada função deve realizar uma operação matemática diferente (soma, subtração, multiplicação e divisão). O programa deve permitir ao usuário escolher a operação a ser realizada e imprimir o resultado.

---

5- Alocação de memória com malloc: Escreva um programa que solicite ao usuário a quantidade de elementos de um array e aloque memória dinamicamente para armazená-los. Em seguida, peça ao usuário para preencher o array com números inteiros e imprima o array.

6- Realocação de memória com realloc: Estenda o programa do exercício 5 para permitir que o usuário adicione mais elementos ao array. Utilize a função realloc para realocar memória conforme necessário.

7- Matriz dinâmica: Escreva um programa que solicite ao usuário as dimensões de uma matriz (linhas e colunas) e aloque memória dinamicamente para armazená-la. Peça ao usuário para preencher a matriz com números inteiros e, em seguida, imprima a matriz.

8- Listas ligadas simples: Implemente uma lista ligada simples com funções para inserir elementos no início, no fim e em uma posição específica, além de uma função para imprimir a lista e outra para remover elementos da lista.

9-Pilhas usando memória dinâmica: Implemente uma pilha utilizando memória dinâmica. Inclua funções para empilhar (push), desempilhar (pop), verificar se a pilha está vazia e imprimir a pilha.

10- Filas usando memória dinâmica: Implemente uma fila utilizando memória dinâmica. Inclua funções para enfileirar (enqueue), desenfileirar (dequeue), verificar se a fila está vazia e imprimir a fila.

---

## Resolução ##

### 1 ###

````c
#include <stdio.h>

int main() {
    int variavel = 42;           // Declare uma variável inteira
    int *ponteiro;               // Declare um ponteiro para inteiro

    ponteiro = &variavel;        // Atribua o endereço da variável inteira ao ponteiro

    printf("Valor da variavel: %d\n", *ponteiro);          // Imprima o valor da variável usando o ponteiro
    printf("Endereco da variavel: %p\n", (void *)ponteiro); // Imprima o endereço da variável usando o ponteiro

    return 0;
}
````

---

### 3 ###

````c
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
````

---

### 4 ###

````c
#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

int divisao(int a, int b) {
    return a / b;
}

int main() {
    int (*operacoes[4])(int, int) = {soma, subtracao, multiplicacao, divisao};
    int opcao, a, b;
    printf("Escolha a operacao a ser realizada:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    scanf("%d", &opcao);
    printf("Entre com dois numeros: ");
    scanf("%d %d", &a, &b);
    int resultado = operacoes[opcao - 1](a, b);
    printf("Resultado: %d\n", resultado);
    return 0;
}
````

---

### 5 ###

````c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Entre com a quantidade de elementos do array: ");
    scanf("%d", &n);
    int *array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria.");
        return 1;
    }
    printf("Preencha o array com numeros inteiros:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Array preenchido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
````

---

### 6 ###

````c

````

---

### 7 ###

````c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Digite o número de linhas: ");
    scanf("%d", &rows);

    printf("Digite o número de colunas: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
````

---

### 9 ###

````c

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

// Protótipos das funções
Stack *create_stack();
void push(Stack *stack, int data);
int pop(Stack *stack);
int is_empty(Stack *stack);
void print_stack(Stack *stack);

int main() {
    Stack *stack = create_stack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    print_stack(stack);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    print_stack(stack);

    return 0;
}

// Função para criar uma nova pilha
Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Função para empilhar um elemento na pilha
void push(Stack *stack, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Função para desempilhar um elemento da pilha
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Pilha vazia.\n");
        return -1;
    }

    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;

    free(temp);
    return data;
}

// Função para verificar se a pilha está vazia
int is_empty(Stack *stack) {
    return stack->top == NULL;
}

// Função para imprimir a pilha
void print_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("Pilha vazia.\n");
        return;
    }

    Node *temp = stack->top;
    printf("Pilha: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
````

---

### 8 ###

````c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Protótipos das funções
Queue *create_queue();
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int is_empty(Queue *queue);
void print_queue(Queue *queue);

int main() {
    Queue *queue = create_queue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    print_queue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    print_queue(queue);

    return 0;
}

// Função para criar uma nova fila
Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Função para enfileirar um elemento na fila
void enqueue(Queue *queue, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

// Função para desenfileirar um elemento da fila
int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Fila vazia.\n");
        return -1;
    }

    Node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Função para verificar se a fila está vazia
int is_empty(Queue *queue) {
    return queue->front == NULL;
}

// Função para imprimir a fila
void print_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Fila vazia.\n");
        return;
    }

    Node *temp = queue->front;
    printf("Fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

````

---

## Aritmética de Ponteiros ##

A aritmética de ponteiros é um recurso da linguagem C que permite a manipulação de endereços de memória através de operações matemáticas realizadas com ponteiros. A aritmética de ponteiros é especialmente útil quando se trabalha com arrays e estruturas de dados como listas, pilhas e filas.

---

Existem quatro operações básicas na aritmética de ponteiros:

- Adição: É possível adicionar um inteiro a um ponteiro. O resultado é um novo ponteiro que aponta para uma posição de memória deslocada em relação ao ponteiro original. O deslocamento é calculado multiplicando o valor inteiro pelo tamanho do tipo de dado apontado pelo ponteiro.

Exemplo:

````c
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr; // p aponta para o primeiro elemento do array (arr[0])
p = p + 3; // p agora aponta para o quarto elemento do array (arr[3])

````

---

- Subtração: É possível subtrair um inteiro de um ponteiro, resultando em um novo ponteiro que aponta para uma posição de memória deslocada em relação ao ponteiro original. O deslocamento é calculado de forma semelhante à adição, porém na direção oposta.

Exemplo:

````c

int arr[5] = {1, 2, 3, 4, 5};
int *p = arr + 4; // p aponta para o último elemento do array (arr[4])
p = p - 2; // p agora aponta para o terceiro elemento do array (arr[2])
````

---

- Diferença entre ponteiros: É possível calcular a diferença entre dois ponteiros do mesmo tipo. O resultado é um inteiro que representa o número de elementos entre os dois ponteiros.

Exemplo:

````c
int arr[5] = {1, 2, 3, 4, 5};
int *p1 = arr;      // p1 aponta para o primeiro elemento do array (arr[0])
int *p2 = arr + 4;  // p2 aponta para o último elemento do array (arr[4])
int diff = p2 - p1; // diff é igual a 4, pois há 4 elementos entre p1 e p2
````

---

- Incremento e decremento: Os operadores de incremento (++) e decremento (--) também podem ser utilizados com ponteiros, avançando ou retrocedendo a posição de memória apontada.

Exemplo:

````c
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr; // p aponta para o primeiro elemento do array (arr[0])
p++;          // p agora aponta para o segundo elemento do array (arr[1])
p--;          // p volta a apontar para o primeiro elemento do array (arr[0])

````

É importante ressaltar que a aritmética de ponteiros leva em consideração o tamanho do tipo de dado apontado pelo ponteiro. Portanto, ao adicionar ou subtrair um valor de um ponteiro, o deslocamento é ajustado automaticamente com base no tamanho do tipo de dado. Por exemplo, se você estiver trabalhando com um ponteiro para int e incrementar o ponteiro, ele avançará o número de bytes necessários para armazenar um inteiro (geralmente 4 bytes em sistemas modernos).

_AVISO_: A aritmética de ponteiros é uma ferramenta poderosa e flexível em C, mas é essencial utilizá-la com cuidado, pois erros na manipulação de ponteiros podem levar a comportamentos indefinidos, como acessar áreas de memória não permitidas ou corromper dados.
