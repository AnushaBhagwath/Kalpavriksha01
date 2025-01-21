#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert functions
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int position, int value) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    for (int pos = 1; pos < position - 1 && temp; pos++) {
        temp = temp->next;
    }
    if (!temp) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display function
void display() {
    if (!head) {
        printf("\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Main function
int main() {
    int n, op, pos, value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                scanf("%d %d", &pos, &value);
                insertAtPosition(pos, value);
                break;
            case 4:
                display();
                break;
            case 5:
                scanf("%d %d", &pos, &value);
                updateAtPosition(pos, value);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}
