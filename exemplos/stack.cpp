#include <iostream>

struct Node {
    int value;
    Node *next;
};

class Stack {

    Node * top;

  public:
    Stack(){
       this->top = nullptr;
       std::cout << "Criando pilha.\n";
    }

    ~Stack(){
        while(top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void pop(){
        if(top != nullptr){
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    void push(int value){
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }

    int getTop(){
        if (top != nullptr) {
            std::cout << "Topo: " << top->value << "\n";
            return top->value;
        } else {
            std::cout << "A pilha está vazia.\n";
            return -1;
        }
    }
};

int main(){
    Stack my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.getTop(); // Deverá imprimir "Topo: 20"
    my_stack.pop();
    my_stack.getTop(); // Deverá imprimir "Topo: 10"
    return 0;
}
