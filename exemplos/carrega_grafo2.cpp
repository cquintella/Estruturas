#include<iostream>
#include <fstream> 
#include <string>
#include <sstream>

struct EdgeNode {
    int id;
    EdgeNode* next;
};

struct VertexNode {
    int id;
    EdgeNode* edgeList;
    VertexNode* next;
};

VertexNode* adiciona_vertice(VertexNode* header, int value) {
    VertexNode* new_vertex = new VertexNode;
    new_vertex->id = value;
    new_vertex->edgeList = nullptr;
    new_vertex->next = nullptr;

    if (header == nullptr) {
        header = new_vertex;
    }
    else {
        VertexNode* curr = header;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_vertex;
    }
    return header;
}

void adiciona_adjacente(VertexNode* vertice, int value) {
    EdgeNode* new_edge = new EdgeNode;
    new_edge->id = value;
    new_edge->next = nullptr;

    if (vertice->edgeList == nullptr) {
        vertice->edgeList = new_edge;
    }
    else {
        EdgeNode* curr = vertice->edgeList;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_edge;
    }
}

VertexNode* carrega_arquivo() {
    std::ifstream file("grafo.txt");
    VertexNode* header = nullptr;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string value_str;
            int node_id;

            std::getline(ss, value_str, ':');
            node_id = std::stoi(value_str);
            header = adiciona_vertice(header, node_id);

            while (std::getline(ss, value_str, ',')) {
                int value = std::stoi(value_str);
                adiciona_adjacente(header, value);
            }
        }
    }
    else {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return nullptr;
    }

    file.close();
    return header;
}

void imprimir_grafo(VertexNode* header) {
    VertexNode* curr = header;
    while (curr != nullptr) {
        std::cout << curr->id << ": ";
        EdgeNode* edge = curr->edgeList;
        while (edge != nullptr) {
            std::cout << edge->id << " ";
            edge = edge->next;
        }
        std::cout << "\n";
        curr = curr->next;
    }
}

int main() {
    VertexNode* graph = carrega_arquivo();
    imprimir_grafo(graph);
    return 0;
}
