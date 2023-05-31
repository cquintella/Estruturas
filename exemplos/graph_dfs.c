#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int num[MAX_VERTICES];  // Array para armazenar o número de visitação de cada vértice
int i = 1;  // Variável para atribuir o número de visitação
int edges[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjacência para armazenar as arestas

void DFS(int v, int n) {
    num[v] = i++;  // Atribui um número de visitação ao vértice v

    for (int u = 0; u < n; u++) {
        if (edges[v][u] == 1) {  // Se u é adjacente a v
            if (num[u] == 0) {  // Se u ainda não foi visitado
                printf("Edge (%d, %d)\n", v, u);
                DFS(u, n);  // Chama DFS recursivamente para o vértice u
            }
        }
    }
}

void depthFirstSearch(int n) {
    for (int v = 0; v < n; v++) {
        num[v] = 0;  // Inicializa todos os números de visitação como 0
    }

    for (int v = 0; v < n; v++) {
        if (num[v] == 0) {  // Se v ainda não foi visitado
            DFS(v, n);  // Chama DFS para o vértice v
        }
    }
}

void loadEdgesFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    int vertex1, vertex2;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%d,%d", &vertex1, &vertex2) == 2) {
            edges[vertex1][vertex2] = 1;
        }
    }

    fclose(file);
}

int main() {
    int n;  // Número de vértices

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    loadEdgesFromFile("arestas.txt");

    printf("Depth-First Search:\n");
    depthFirstSearch(n);

    return 0;
}
