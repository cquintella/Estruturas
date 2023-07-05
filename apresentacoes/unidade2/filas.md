---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Estruturas de Dados
theme: gaia
---

<!-- _class: lead -->

# Filas (Queues) #

- Professor: Carlos Alvaro Quintella
- Revisão: 05/06/2023

![UVA 70% bg left:20%](https://uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

'Uma Fila é' uma estrutura de dados linear muito comum , usada para organizar e manipular dados.

- É uma coleção ordenada de elementos na qual um elemento é inserido no final (também conhecido como "cauda" da fila) e removido do início (também conhecida como "cabeça" da fila).
- Essa propriedade faz com que a fila siga o protocolo **FIFO (First In, First Out)**, ou seja, o primeiro elemento que entra na fila é o primeiro a sair.

---

## Aplicações ##

Elas têm aplicações amplas em várias áreas:

- Ciência da Computação e TI: Usadas para controlar o fluxo de dados em buffers e gerenciar processos em sistemas operacionais.
- Simulações: Modelam eventos que ocorrem em uma sequência específica, como clientes em uma fila de supermercado.
- Jogos: Gerenciam tarefas que precisam ser executadas em uma ordem específica, como a sequência de movimentos dos jogadores.

---

- Atendimento ao Cliente: Gerenciam chamadas em centros de atendimento ao cliente, colocando os clientes em uma fila até que um representante esteja disponível.
- Sistemas de Mensagens: São fundamentais para sistemas de mensagens como Kafka ou RabbitMQ, permitindo a entrega confiável e ordenada de mensagens.
- Transações comerciais, logistica, trânsito, sistemas bancários e financeiros.
- Gerenciamento de processos e agendamento de tarefas em sistemas operacionais.

---

- Controle de fluxo de dados em redes e sistemas de comunicação.
- Simulação de eventos discretos e sistemas de filas na teoria das filas.

---

## Operações Básicas ##

As operações básicas realizadas em uma fila incluem:

- Enfileirar (enqueue): Adicionar um elemento no final da fila.
- Desenfileirar (dequeue): Remover o elemento do início da fila e retorná-lo.
- Ver frente (front): Acessar o elemento no início da fila sem removê-lo.
- Verificar se está vazia (is_empty): Verificar se a fila está vazia ou não.
- Tamanho (size): Obter o número de elementos na fila.

---

As filas podem ser implementadas usando várias estruturas de dados subjacentes, como arrays, listas encadeadas ou até mesmo outras estruturas de dados como pilhas.

- A escolha da estrutura de dados subjacente pode afetar o desempenho e a complexidade das operações da fila.

- Se olharmos bem, podemos que o código para implementar uma fila é bem parecido com o código de uma pilha.

---

Tipo Abstrato de Dados: Fila

```pseudocode
Tipo Fila
    Dados:
        - elementos: lista/array/lista encadeada
        - tamanho: inteiro
        
    Operações:
        - construtor(): inicializa a fila vazia
        - destruto(): liberar memória
        - enfileirar(x): adiciona um elemento x ao final da fila
        - desenfileirar(): remove e retorna o elemento do início da fila
        - frente(): retorna o elemento do início da fila sem removê-lo
        - esta_vazia(): retorna verdadeiro se a fila estiver vazia, falso caso contrário
        - obter_tamanho(): retorna o número de elementos na fila
```

---

Fila usando memória dinâmica:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

```

---

```c
void enfileirar(Fila* fila, int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo_no;
    } else {
        fila->fim->prox = novo_no;
    }
    fila->fim = novo_no;
}

int desenfileirar(Fila* fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "A fila está vazia\n");
        exit(1);
    }

    No* no_removido = fila->inicio;
    int valor = no_removido->valor;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(no_removido);
    return valor;
}
```

---

```c
int frente(Fila* fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "A fila está vazia\n");
        exit(1);
    }

    return fila->inicio->valor;
}

int esta_vazia(Fila* fila) {
    return fila->inicio == NULL;
}

void destruir_fila(Fila* fila) {
    while (!esta_vazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}
```

---

```c
int main() {
    Fila* minha_fila = criar_fila();

    enfileirar(minha_fila, 1);
    enfileirar(minha_fila, 2);
    enfileirar(minha_fila, 3);

    printf("Frente da fila: %d\n", frente(minha_fila));
    printf("Desenfileirando: %d\n", desenfileirar(minha_fila));
    printf("Frente da fila: %d\n", frente(minha_fila));

    destruir_fila(minha_fila);
    return 0;
}
```

---

```cpp
#include <iostream>

class Fila {
private:
    int* elementos;
    int tamanho;
    int capacidade;
    int inicio;
    int fim;

public:
    // Construtor
    Fila(int capacidade) {
        this->capacidade = capacidade;
        this->elementos = new int[capacidade];
        this->tamanho = 0;
        this->inicio = 0;
        this->fim = -1;
    }

    // Destrutor
    ~Fila() {
        delete[] elementos;
    }

    // Adiciona um elemento ao final da fila
    void enfileirar(int x) {
        if (tamanho == capacidade) {
            std::cerr << "Erro, fila cheia.\n";
            return;
        }
        fim = (fim + 1) % capacidade;
        elementos[fim] = x;
        tamanho++;
    }

    // Remove e retorna o elemento do início da fila
    int desenfileirar() {
        if (esta_vazia()) {
            std::cerr << "Erro, fila vazia.\n";
            return -1;
        }
        int valor = elementos[inicio];
        inicio = (inicio + 1) % capacidade;
        tamanho--;
        return valor;
    }

    // Retorna o elemento do início da fila sem removê-lo
    int frente() {
        if (esta_vazia()) {
            std::cerr << "Erro, fila vazia.\n";
            return -1;
        }
        return elementos[inicio];
    }

    // Retorna verdadeiro se a fila estiver vazia, falso caso contrário
    bool esta_vazia() {
        return tamanho == 0;
    }

    // Retorna o número de elementos na fila
    int obter_tamanho() {
        return tamanho;
    }
};

int main() {
    Fila fila(5);

    fila.enfileirar(1);
    fila.enfileirar(2);
    fila.enfileirar(3);

    std::cout << "Desenfileirando: " << fila.desenfileirar() << std::endl;
    std::cout << "Frente da fila: " << fila.frente() << std::endl;
    std::cout << "Tamanho da fila: " << fila.obter_tamanho() << std::endl;

    return 0;
}
```

---

### Filas de Prioridade ###

Uma fila de prioridade é uma variação da fila em que cada elemento possui uma prioridade associada. Os elementos são organizados na fila de acordo com suas prioridades, de modo que o elemento de maior (ou menor) prioridade fica na frente da fila. Existem várias implementações possíveis de filas de prioridade, como heaps binários, árvores de busca balanceadas, filas de prioridade baseadas em arrays, entre outros.

---

TAD da fila de prioridade

```pseudocode
Tipo FilaComPrioridade:
    Tipo Prioridade
    Tipo Elemento
    função vazia() -> booleano
    função tamanho() -> inteiro
    procedimento enfileirar(elemento: Elemento, prioridade: Prioridade)
    função desenfileirar() -> Elemento
    função frente() -> Elemento
```

---

```cpp
#include <iostream>
#include <queue>

class Task {
public:
    int priority;
    std::string name;

    Task(int priority, std::string name) : priority(priority), name(name) {}

    // Overload the less than operator for priority comparison
    bool operator<(const Task& t) const {
        return priority < t.priority;
    }
};

int main() {
    // Create a priority queue of Tasks
    std::priority_queue<Task> taskQueue;

    // Add tasks to the queue
    taskQueue.push(Task(3, "Task 1"));
    taskQueue.push(Task(2, "Task 2"));
    taskQueue.push(Task(5, "Task 3"));
    taskQueue.push(Task(1, "Task 4"));
    taskQueue.push(Task(1, "Task 5"));
    taskQueue.push(Task(5, "Task 6"));
    taskQueue.push(Task(4, "Task 7"));
    taskQueue.push(Task(2, "Task 8"));
    taskQueue.push(Task(4, "Task 9"));

    // Process tasks
    while (!taskQueue.empty()) {
        Task task = taskQueue.top();
        std::cout << "Processing " << task.name << " with priority " << task.priority << std::endl;
        taskQueue.pop();
    }

    return 0;
}
```

---

### Filas circulares ###

Filas circulares: Uma fila circular é uma variação da fila em que o início e o fim da fila estão conectados, formando um ciclo. Isso permite que a fila seja reutilizada sem necessidade de realocação de memória, uma vez que os elementos são enfileirados e desenfileirados em posições circulares. Essa abordagem é especialmente útil quando há um limite fixo de elementos na fila e se deseja evitar a realocação frequente de memória.

---

Além disso, as filas circulares oferecem uma implementação eficiente das operações de enfileirar e desenfileirar, uma vez que a posição do início da fila é mantida e atualizada de forma circular. Isso evita a necessidade de mover todos os elementos restantes quando ocorre uma desenfileiração, como é o caso em filas lineares.

![fila circular](https://mermaid.ink/img/pako:eNqd0r-vwiAQB_B_hZxLm7SDVl_yGEz6c3LSlYXIYRspbSqNGuP_LqUxj_V14-5zX4aDF5w7gUDhMvC-Jocj04SkQVAqbFGbjqzDkMTxnmRebxOG01jmIPcgmSF3UHiwnaFwUHqwm6F0UHnwM0PlIGV6Km7mqZCkRDZK0ZX8lZFtDd0V6SpJkm8R3xtharrpH3-ZbEEmX5ApFmTKBZnqHxmIoMWh5Y2wz_ya7mBgartmBtQeBUo-KsOA6bcd5aPpTk99BmqGESMYe8ENFg23H6QFKrm64fsDR-Kxvg)

---

```pseudocode
Tipo FilaCircular:
    variável início: inteiro
    variável fim: inteiro
    variável capacidade: inteiro
    variável elementos: vetor de elementos
    função vazia() -> booleano
    função cheia() -> booleano
    função tamanho() -> inteiro
    procedimento enfileirar(elemento)
    função desenfileirar() -> elemento
    função frente() -> elemento
```

---

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int capacity;
    int front;
    int rear;
    int size;
} CircularQueue;

// Função para criar uma nova fila circular
CircularQueue* createQueue(int capacity) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(CircularQueue* queue) {
    return (queue->size == 0);
}

// Função para verificar se a fila está cheia
int isFull(CircularQueue* queue) {
    return (queue->size == queue->capacity);
}
```

---

```cpp
// Função para enfileirar um elemento na fila
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Erro: a fila está cheia\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    if (queue->front == -1)
        queue->front = queue->rear;
}

// Função para desenfileirar um elemento da fila
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: a fila está vazia\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Função para obter o elemento da frente da fila
int front(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: a fila está vazia\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Função para imprimir os elementos da fila
void printQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia\n");
        return;
    }
    printf("Elementos da fila: ");
    int i;
    for (i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->array[index]);
    }
    printf("\n");
}

```

---

```cpp

// Função para liberar a memória alocada pela fila
void destroyQueue(CircularQueue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    int capacity = 5;
    CircularQueue* queue = createQueue(capacity);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printQueue(queue);  // Output: Elementos da fila: 1 2 3

    int frontElement = front(queue);
    printf("Elemento da frente: %d\n", frontElement);  // Output: Elemento da frente: 1

    int dequeuedElement = dequeue(queue);
    printf("Elemento desenfileirado: %d\n", dequeuedElement);  // Output: Elemento desenfileirado: 1

    printQueue(queue);  // Output: Elementos da fila: 2 3

    destroyQueue(queue);

    return 0;
}
```

---

### Perguntas ###

1) Qual é o princípio fundamental das filas em relação à ordem de inserção e remoção de elementos?

2) Quais são as principais diferenças entre uma fila e uma pilha?

3) Explique como a operação "enfileirar" (ou "enqueue") funciona em uma fila.

4) Quais são as possíveis aplicações práticas do uso de filas em algoritmos ou sistemas?

5) Como o conceito de "prioridade" é aplicado em filas de prioridade? Explique com um exemplo.

---

Implemente uma fila usando duas pilhas, enfileirar e desenfileirar. Quando a fila desenfilarar esvazir passe os elementos de enfileirar para desenfileirar.

---

## Recursos Adicionais ##
