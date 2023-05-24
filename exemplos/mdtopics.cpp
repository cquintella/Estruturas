#include <iostream>
#include <fstream>
#include <string>

bool isTopicLine(const std::string& line) {
    return line.size() >= 2 && line[0] == '#' && line[1] != '#';
}

void printTopics(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isTopicLine(line)) {
            std::cout << line.substr(1) << std::endl;
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Uso: ./programa arquivo.md" << std::endl;
        return 1;
    }

    std::cout << "Tópicos encontrados:" << std::endl;
    printTopics(argv[1]);

    return 0;

}
