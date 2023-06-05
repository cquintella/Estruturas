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
