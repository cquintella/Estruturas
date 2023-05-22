#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <random>

enum Cidade {
    SAO_PAULO,
    RIO_DE_JANEIRO,
    BELO_HORIZONTE,
    BRASILIA,
    SALVADOR,
    FORTALEZA,
    CURITIBA,
    MANAUS,
    PORTO_ALEGRE,
    NUM_CIDADES
};

float gerarTemperaturaAleatoria(float ultimaTemperatura) {}
    float novaTemperatura = ultimaTemperatura + variacao;
    return novaTemperatura;
}

int main() {
    float tempVector[NUM_CIDADES] = {0.0f};

    std::ofstream outFile("temperaturas.txt");

    while (true) {
        for (int i = 0; i < NUM_CIDADES; i++) {
            outFile << gerarTemperaturaAleatoria(tempVector[i]) << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    outFile.close();

    return 0;
}
