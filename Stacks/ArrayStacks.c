#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct{
    int top;
    int element[max];
}stack;
stack s;
void createStack(stack *ps){
    ps->top = -1;
}
typedef enum{false,true} boolean;
boolean isEmpty(stack *ps){
    return (ps->top == -1 ? true : false);
}
boolean isFull(stack *ps){
    return (ps->top == max - 1 ? true : false);
}
void push(stack *ps,int value){
    ps->element[++ps->top] = value;
}
int pop(stack *ps){
    int temp;
    temp = ps->element[ps->top];
    ps->top--;
    return temp;
}
int peak(stack *ps){
    return (ps->element[ps->top]);
}
void main(){
    stack s;
    createStack(&s);
    push(&s,89);
    push(&s,23);
    push(&s,45);
    push(&s,72);
    printf("Peak Value : %d ",peak(&s));
    printf("\nPop value : %d\n",pop(&s));
    printf("Peak Value : %d ",peak(&s));
}