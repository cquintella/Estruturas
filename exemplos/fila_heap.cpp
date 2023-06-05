#include <iostream>

struct Nodo{
    int value;
    Nodo* next;
};

class Queue{
  private:     
    int size;
    struct Nodo *front;
    struct Nodo *rear;
    
  public:
    Queue(){
        this->size=0;
        front=nullptr;
        rear=nullptr;
    }
    
    void enqueue(int value){
        Nodo *new_node=new Nodo;
        new_node->next=nullptr;
        new_node->value=value;
        if(this->rear==nullptr){
            this->rear=new_node;
            this->front=new_node;
        } else {
             this->rear->next=new_node;
             this->rear=new_node;
        }
        this->size++;
    }
    
    int dequeue(){
        if (this->size<=0){
            std::cerr<<"Erro, tentando retirar com pilha vazia\n";
            return -1;
        }
        int retVal = this->front->value;
        Nodo *to_delete=this->front;
        this->front=this->front->next;
        delete to_delete;
        this->size--;
        return retVal;
    }
    int getSize(){
        return this->size;
        
    }
};


int main(){
    Queue fila;
    
    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);
    fila.enqueue(15);
    std::cout<<"tamanho da fila: "<<fila.getSize()<<std::endl;
    
    std::cout<<"desenfileirando: "<<fila.dequeue()<<std::endl;
    
    std::cout<<"tamanho da fila: "<<fila.getSize()<<std::endl;

}
