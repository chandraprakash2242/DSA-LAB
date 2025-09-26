#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node* next;
};
typedef struct node Node;
Node* head = NULL;
Node* p;
Node* prev;
Node* temp;
Node* newNode;

void insertFirst(int value) {
    p = (Node*)malloc(sizeof(Node));
    p->info = value;
    p->next = head;
    head = p;
    printf("%d inserted at beginning\n", value);
}


void insertLast(int value) {
    p = (Node*)malloc(sizeof(Node));
    p->info = value;
    p->next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    printf("%d inserted at end\n", value);
}


void deleteNode(int value) {
     p = head;
     prev = NULL;

    if (p != NULL && p->info == value) {
        head = p->next;
        free(p);
        printf("%d deleted\n", value);
        return;
    }

    while (p != NULL && p->info != value) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("%d not found\n", value);
        return;
    }

    prev->next = p->next;
    free(p);
    printf("%d deleted\n", value);
}


void insertAfterNode(int key, int value) {
    p = head;

    while (p != NULL && p->info != key)
        p = p->next;

    if (p == NULL) {
        printf("Node %d not found\n", key);
        return;
    }

     newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = p->next;
    p->next = newNode;
    printf("%d inserted after %d\n", value, key);
}


void insertBeforeNode(int key, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->info == key) {
        insertFirst(value);
        return;
    }

    p = head;
   prev = NULL;

    while (p != NULL && p->info != key) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Node %d not found\n", key);
        return;
    }

    newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = p;
    prev->next = newNode;
    printf("%d inserted before %d\n", value, key);
}


void display() {
    p = head;
    if (p == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}


void main() {
    int choice, value, key;

   do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Insert After a Node\n");
        printf("5. Insert Before a Node\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFirst(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertLast(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                printf("Enter node after which to insert: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfterNode(key, value);
                break;

            case 5:
                printf("Enter node before which to insert: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeforeNode(key, value);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

      while(choice!=7);
    
}
