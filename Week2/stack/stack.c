#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nData;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

void InitializeStack(Stack *stack);
void Push(Stack *stack, int nData);
int Pop(Stack *stack);


int main(void){
    Stack stack;
    InitializeStack(&stack);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);
    Push(&stack, 5);
    int a = Pop(&stack);
    printf("%d\n", a);
    a =Pop(&stack);
    printf("%d\n", a);
    a =Pop(&stack);
    printf("%d\n", a);
    a =Pop(&stack);
    printf("%d\n", a);
    a =Pop(&stack);
    printf("%d\n", a);
    return 0;
}

void InitializeStack(Stack *stack){
    stack->top = NULL;
}

void Push(Stack *stack, int nData){
    Node* add = (Node*)malloc(sizeof(Node));
    add->nData = nData;
    add->next = stack->top;
    stack->top = add;
}

int Pop(Stack *stack){
    int tempdata;
    Node* temp;
    
    if (stack->top == NULL) {
        printf("Stack is empty!");
        return -1;
    }
    tempdata = stack->top->nData;
    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return tempdata;
}



