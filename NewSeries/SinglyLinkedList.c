#include <stdio.h>
#include <stdlib.h>
struct Node{ //creating structure of Node
    int data;
    struct Node* next;
};
struct Node* createNode(int n){  // creating Node
    struct Node *head = NULL, *temp = NULL, *newNode = NULL; // Intializing head temp newNode
    int num; 
    for(int i=1;i<=n;i++){ // creating a Loop for multiple Node Entry
        newNode = (struct Node*)malloc(sizeof(struct Node)); // creating Memory for newNode
        if(newNode == NULL){
            printf("Memory Allocation Failed!!");  // If Memory allocation Failed
            exit(1);
        }
        printf("Input Data of %d: ", i); 
        scanf("%d",&num); // take value for each Node's
        newNode->data = num; // placing in each Node
        newNode->next = NULL; // pointing next to NULL
        
        if(head == NULL){ // for first Node it will Run 
            head = newNode; // head will point to new Node {head->newNode}
            temp = newNode; // {temp->newNode}
        }else{
            temp->next = newNode; //After First Node {temp->next pointed to newNode}
            temp = newNode; // After Pointing to newNode it Point move to newNode 
        }
    }
    return head; // returning head for Printing or Display Node
}
int main(){
    int n;
    printf("Enter the Number of Node: ");
    scanf("%d",&n); // Taking input from user for no. of Node
    struct Node* head = createNode(n); // give head from {function: createNode}
    // for Displaying Linked List
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }printf("NULL\n");
    return 0;
}