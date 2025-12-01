#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
    int info;
    struct nodeType *next;
}node;

typedef struct{
    node *front;
    node *rear;
}queue;
queue pq;

void createQueue(queue *pq){
    pq->front = pq->rear = NULL;
}

typedef enum{false,true} boolean;

boolean isEmpty(queue *pq){
    return (pq->front == NULL ? true : false);
}

void Enque(queue *pq,int value){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = value;
    ptr->next = NULL;
    if(pq->rear == NULL){
        pq->front = pq->rear = ptr;
    }else{
        (pq->rear)->next = ptr;
        pq->rear = ptr;
    }
}

int Dequeue(queue *pq){
    int temp;
    node *ptr;
    temp = (pq->front)->info;
    if(pq->front == pq->rear){
        pq->front = pq->rear = NULL;
    }else{
        pq->front = (pq->front)->next;
    }
    free(ptr);
    return temp;
}

void disposeQueue(queue *pq){
    node *ptr;
    while(pq->front != NULL){
        ptr = pq->front;
        pq->front = (pq->front)->next;
        free(ptr);
    }
    pq->rear = (node *)NULL;
}
void isPeek(queue *pq){
    if(isEmpty(pq)){
        printf("Queue is Empty !!");
    }else{
        printf("Peek Element is %d",(pq->front)->info);
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