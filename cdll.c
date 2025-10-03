#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}


Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;

    return head;
}


Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* curr = head;
    Node* toDelete = NULL;

    do {
        if (curr->data == key) {
            toDelete = curr;
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (toDelete == NULL) {
        printf("Element %d not found in the list.\n", key);
        return head;
    }

    if (toDelete->next == toDelete && toDelete->prev == toDelete) {
        free(toDelete);
        return NULL;
    }

    if (toDelete == head) {
        head = head->next;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    free(toDelete);
    return head;
}


void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* curr = head;
    printf("List: ");
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                printf("%d inserted.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:

                printf("Exiting...\n");
               
                while (head != NULL) {
                    head = deleteNode(head, head->data);
                }
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}                                                                                                                                                                                                   
