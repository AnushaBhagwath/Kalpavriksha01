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
