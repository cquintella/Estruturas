#include<iostream>

class Stack {
    private:
        int top;
        int size; 
        int *stack;
    public:
        Stack(int stackSize) {
            top = -1;
            size = stackSize;
            stack = new int[size];
        }
        
        ~Stack() {
            delete[] stack;
        }
                void push(int value) {
            if (top == size - 1) {
                std::cout << "Stack Overflow!" << std::endl;
                return;
            }
            stack[++top] = value;
        }
        
        int pop() {
            if (top == -1) {
                std::cout << "Stack Underflow!" << std::endl;
                return -1;
            }
            return stack[top--];
        }
        
        int getSize() {
            return top + 1;
        }
        
        bool isEmpty() {
            return top == -1;
        }
        
        int getTop() {
            if (isEmpty()) {
                std::cout << "Stack is empty!" << std::endl;
                return -1;
            }
            return stack[top];
        }
};

int main(){

    Stack myStack(10);
    myStack.push(10);
    myStack.push(3);
    myStack.push(5);
    std::cout<<myStack.getTop();
    myStack.pop();
    std::cout<<myStack.getTop();
    return 0;

}