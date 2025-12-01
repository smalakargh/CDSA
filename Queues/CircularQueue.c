#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10

typedef struct nodeType{
    int front,rear;
    int element[CAPACITY];
}queue;
queue pq;

void createQueue(queue *pq){
    pq->front = pq->rear = -1;
}

typedef enum{false,true} boolean;

boolean isEmpty(queue *pq){
    if(pq->front == -1){
        return true;
    }else{
        return false;
    }
}

boolean isFull(queue *pq){
    if((pq->front == 0)&&(pq->rear == CAPACITY - 1)||(pq->front == pq->rear + 1)){
        return true;
    }else{
        return false;
    }
}

void Enque(queue *pq,int value){
    if(isEmpty(pq)){
        pq->front = pq->rear = 0;
    }else if(pq->rear == CAPACITY - 1){
        pq->rear = 0;
    }else{
        pq->rear++;
    }
    pq->element[pq->rear] = value;
}

int Dequeue(queue *pq){
    int temp;
    temp = pq->element[pq->front];
    if(pq->front == pq->rear){
        pq->front = pq->rear = -1;
    }else if(pq->front == CAPACITY - 1){
        pq->front = 0;
    }else{
        pq->front++;
    }
    return temp;
}

void isPeek(queue *pq){
    if(isEmpty(pq)){
        printf("Queue is Empty !!");
    }else{
        printf("Peek Element is %d",pq->element[pq->front]);
    }
}

int main(){
    queue p;
    createQueue(&p);
    Enque(&p,45);
    Enque(&p,56);
    Enque(&p,26);
    Enque(&p,51);
    isPeek(&p);
    printf("\nDequeue Element is %d\n",Dequeue(&p));
    isPeek(&p);
    return 0;
}