#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType {
    int info;
    struct nodeType *next;
} stack;

typedef enum { false, true } boolean;

void createStack(stack **top) {
    *top = NULL;
}

boolean isEmpty(stack *top) {
    return (top == NULL ? true : false);
}

void push(stack **top, int value) {
    stack *ptr = (stack *)malloc(sizeof(stack));
    if (ptr == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    ptr->info = value;
    ptr->next = *top;
    *top = ptr;
}

int pop(stack **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    int temp = (*top)->info;
    stack *ptr = *top;
    *top = (*top)->next;
    free(ptr);
    return temp;
}

int peek(stack *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return top->info;
}

int main() {
    stack *top;
    createStack(&top);

    push(&top, 56);
    push(&top, 23);
    push(&top, 34);
    push(&top, 89);

    printf("Peek Value : %d", peek(top));
    printf("\nPop Value : %d", pop(&top));
    printf("\nPeek Value : %d", peek(top));

    return 0;
}