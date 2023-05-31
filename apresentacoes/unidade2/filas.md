---
marp: true
author: carlos.quintella@uva.br
backgroundColor: white
paginate: true
footer: Estrutura de Dados
theme: gaia
---

<!-- _class: lead -->

# Filas #

- Professor: Carlos Alvaro Quintella
- Revisão: 10/05/2023

![UVA 70% bg left:20%](https://uva.br/wp-content/themes/uva-theme/dist/images/header_logo.svg)

---

Fila é uma estrutura de dados linear, também muito comum para organizar e manipular dados.

- Uma fila é uma coleção ordenada de elementos na qual um elemento é inserido no final (também conhecido como "cauda" da fila) e removido do início (também conhecida como "cabeça" da fila).
- Essa propriedade faz com que a fila siga o protocolo **FIFO (First In, First Out)**, ou seja, o primeiro elemento que entra na fila é o primeiro a sair.

---

## Operações Básicas ##

As operações básicas realizadas em uma fila incluem:

- Enfileirar (enqueue): Adicionar um elemento no final da fila.
- Desenfileirar (dequeue): Remover o elemento do início da fila e retorná-lo.
- Ver frente (front): Acessar o elemento no início da fila sem removê-lo.
- Verificar se está vazia (is_empty): Verificar se a fila está vazia ou não.
- Tamanho (size): Obter o número de elementos na fila.

---

As filas podem ser implementadas usando várias estruturas de dados subjacentes, como arrays, listas encadeadas ou até mesmo outras estruturas de dados como pilhas. A escolha da estrutura de dados subjacente pode afetar o desempenho e a complexidade das operações da fila.

---

TAD: Fila

```pseudocode
Tipo Fila
    Dados:
        - elementos: lista/array/lista encadeada
        - tamanho: inteiro
        
    Operações:
        - construtor(): inicializa a fila vazia
        - enfileirar(x): adiciona um elemento x ao final da fila
        - desenfileirar(): remove e retorna o elemento do início da fila
        - frente(): retorna o elemento do início da fila sem removê-lo
        - esta_vazia(): retorna verdadeiro se a fila estiver vazia, falso caso contrário
        - obter_tamanho(): retorna o número de elementos na fila
```

---

Filas são usadas em muitas situações do mundo real e em diversos problemas de computação, como:

- Gerenciamento de processos e agendamento de tarefas em sistemas operacionais.
- Controle de fluxo de dados em redes e sistemas de comunicação.
- Simulação de eventos discretos e sistemas de filas na teoria das filas.
- Navegação em grafos e árvores usando algoritmos como busca em largura.

---

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

### Filas de Prioridade ###

Uma fila de prioridade é uma variação da fila em que cada elemento possui uma prioridade associada. Os elementos são organizados na fila de acordo com suas prioridades, de modo que o elemento de maior (ou menor) prioridade fica na frente da fila. Existem várias implementações possíveis de filas de prioridade, como heaps binários, árvores de busca balanceadas, filas de prioridade baseadas em arrays, entre outros.

---
Definição do TAD da fila de prioridade

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

### Perguntas ###

1) Qual é o princípio fundamental das filas em relação à ordem de inserção e remoção de elementos?

2) Quais são as principais diferenças entre uma fila e uma pilha?

3) Explique como a operação "enfileirar" (ou "enqueue") funciona em uma fila.

4) Quais são as possíveis aplicações práticas do uso de filas em algoritmos ou sistemas?

5) Como o conceito de "prioridade" é aplicado em filas de prioridade? Explique com um exemplo.
