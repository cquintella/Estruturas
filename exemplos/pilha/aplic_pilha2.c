#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 256
#define MAX_CARACTERES 100

typedef struct {
    char linhas[MAX_LINHAS][MAX_CARACTERES];
    int topo;
} Pilha;

void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha* pilha) {
    return pilha->topo == MAX_LINHAS - 1;
}

void push(Pilha* pilha, char linha[MAX_CARACTERES]) {
    if (pilhaCheia(pilha)) {
        printf("A pilha está cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    strcpy(pilha->linhas[++pilha->topo], linha);
}

void pop(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia. Não é possível remover elementos.\n");
        return;
    }

    pilha->topo--;
}

void imprimirPilha(Pilha* pilha) {
    system("clear");  // Limpa a tela (para sistemas Unix/Linux)
    // system("cls");  // Descomente essa linha se estiver usando Windows

    printf("Conteúdo da pilha:\n");

    for (int i = 0; i <= pilha->topo; i++) {
        printf("%s\n", pilha->linhas[i]);
    }
}

int main() {
    Pilha pilha;
    char linha[MAX_CARACTERES];

    inicializarPilha(&pilha);

    while (1) {
        printf("Digite uma linha de texto (ou .. para sair do programa):\n");
        fgets(linha, MAX_CARACTERES, stdin);

        linha[strcspn(linha, "\n")] = '\0';  // Remove o caractere de nova linha do final da string

        if (strcmp(linha, "..") == 0) {
            break;
        } else if (strcmp(linha, "<<") == 0) {
            pop(&pilha);
        } else {
            push(&pilha, linha);
        }

        imprimirPilha(&pilha);
    }

    return 0;
}

