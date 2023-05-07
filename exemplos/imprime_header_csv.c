#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 100
#define MAX_CHARS_PER_COL 100

int main() {
    FILE *fp;
    char filename[100], line[MAX_CHARS_PER_COL*MAX_COLS];
    char *col_names[MAX_COLS];
    int num_cols = 0;

    // Ler o nome do arquivo do usuário
    printf("Digite o nome do arquivo CSV: ");
    scanf("%s", filename);

    // Abrir o arquivo
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Ler a primeira linha do arquivo para obter os nomes das colunas
    fgets(line, sizeof(line), fp);
    char *col = strtok(line, ",");
    while (col != NULL && num_cols < MAX_COLS) {
        col_names[num_cols] = col;
        num_cols++;
        col = strtok(NULL, ",");
    }

    // Imprimir o cabeçalho das colunas
    for (int i = 0; i < num_cols; i++) {
        printf("%s", col_names[i]);
        if (i < num_cols - 1) {
            printf(" | ");
        }
    }
    printf("\n");

    // Fechar o arquivo
    fclose(fp);

    return 0;
}
