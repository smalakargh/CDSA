#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a linked list with n nodes
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int num;
    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed !!\n");
            exit(1);
        }
        printf("Enter Data for Node %d: ", i);
        scanf("%d", &num);
        newNode->data = num;
        newNode->next = NULL;
        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Insert a node at a given position
void insertAtPosition(int pos, int val, struct Node** headRef) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed !!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    struct Node* temp = *headRef;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node at a given position
void deleteAtPosition(int pos, struct Node** headRef) {
    struct Node* temp = *headRef;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, p, val, choice;
    struct Node* head = NULL;

    printf("Enter No. of Nodes: ");
    scanf("%d", &n);
    head = createList(n);
    display(head);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Position\n");
        printf("2. Delete at Position\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Position to Insert: ");
                scanf("%d", &p);
                printf("Enter Value: ");
                scanf("%d", &val);
                insertAtPosition(p, val, &head);
                display(head);
                break;

            case 2:
                printf("Enter Position to Delete: ");
                scanf("%d", &p);
                deleteAtPosition(p, &head);
                display(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                freeList(head);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}