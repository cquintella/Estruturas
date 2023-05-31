#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int size;
    int* stack;
    void (*push)(struct Stack*, int);
    void (*pop)(struct Stack*);
    int (*getSize)(struct Stack*);
    int (*isEmpty)(struct Stack*);
    int (*getTop)(struct Stack*);
} Stack;

void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->stack[++stack->top] = value;
}

void pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    stack->top--;
}

int getSize(Stack* stack) {
    return stack->top + 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int getTop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->stack[stack->top];
}

Stack* createStack(int stackSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = stackSize;
    stack->stack = (int*)malloc(stackSize * sizeof(int));
    stack->push = push;
    stack->pop = pop;
    stack->getSize = getSize;
    stack->isEmpty = isEmpty;
    stack->getTop = getTop;
    return stack;
}

void destroyStack(Stack* stack) {
    free(stack->stack);
    free(stack);
}

int main() {
    Stack* myStack = createStack(10);
    myStack->push(myStack, 10);
    printf("%i", myStack->getTop(myStack));
    myStack->pop(myStack);
    destroyStack(myStack);
    return 0;
}
