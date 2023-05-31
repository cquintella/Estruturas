
/* Este programa lê um arquivo texto representando um grafo com lista de adjacencia, no formato:
vertice:vertice, vertice, vertice
onde os vertices são inteiros, o primeiro é da linha é o vertice chave e os seguintes os adjacentes.
Ex: 1:2,3,4
    3:1,4

Em seguida armazena em uma lista adjacencia na memoria heap.

*/

#include<iostream>
#include <fstream> 
#include <string>
#include <sstream>

struct EdgeNode {
    int id1;
    int id2;
    EdgeNode* next;
};

struct VertexNode {
    int id;
    EdgeNode* edgeList;
    VertexNode* next;
};

VertexNode *adiciona_vertice(VertexNode *header, int value){
    if (header==nullptr){ // se a lista está vazia
        header=new VertexNode;
        header->id=value;
        header->edgeList=new EdgeNode;
        return header;
    } else { // se já existe vertice, procura o final
      VertexNode *vert_ptr;
      vert_ptr=header;
      while (vert_ptr->next!=nullptr){
        vert_ptr=vert_ptr->next;
      }
      //inserir novo vertice
      VertexNode *new_vertex=new VertexNode;
      vert_ptr->next=new_vertex;
      vert_ptr->id=value;
      vert_ptr->edgeList=nullptr;
      vert_ptr->next=nullptr;
      return vert_ptr;
    }
    return nullptr;

}

adciona_adjacente(VertexNode* vertice, int value){

}

EdgeNode* carrega_arquivo(VertexNode *header){
    std::ifstream file("matriz.txt");  // Abri o arquivo
    if (file.is_open()) {  // ok, abriu ...
        std::string line;  // um string paa guardar linha
        while (std::getline(file, line)) { // Ler linha a linha enquanto tem linha para lear
            
            std::stringstream ss(line); // ss = string stream, para separar os campos
            std::string value_str;  // precisa de uma string para armazenar cada entrada
            int node_id;
            // Processa o id do nó
            
            std::getline(ss, value_str, ':'); // processa o primeiro item
             // adiciona na lista de vertices
            VertexNode *vertice=adiciona_vertice(header, atoi(value_str));
            // verifica se existe adjacente, se houver, processa colocando na lista de adjacentes.
            while (std::getline(ss, value_str, ',')) {  // Lê cada valor separado por vírgula
                 int value = std::stoi(value_str);  // Converte a string para inteiro
                 adiciona_adjacentes(vertice, atoi(value_str));
                
        }
    }
        }
    }
    else {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return nullptr;
    }
    
    std::string linha;
    
    while (std::getline(file, linha)) {  // lê cada linha do arquivo
        std::cout << linha << "\n";  // imprime a linha
    }

    file.close();  // fecha o arquivo
}

int main(){


    
    return 0;
}