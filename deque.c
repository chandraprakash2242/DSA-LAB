#include <stdio.h>
#define size 100
int deque[size];
int f = -1, r = -1;
int isempty() {
    return (f == -1);
}

int isfull() {
    return ((f == (r + 1) % size));
}

void insertfront(int item) {
    if (isfull()) {
        printf("Deque is full\n");
        return;
    }
    if (isempty()) {
        f = r = 0;
    } else {
        f = (f - 1 + size) % size; 
    }
    deque[f] = item;
}

void insertrear(int item) {
    if (isfull()) {
        printf("Deque is full\n");
        return;
    }
    if (isempty()) {
        f = r = 0;
    } else {
        r = (r + 1) % size; 
    }
    deque[r] = item;
}

int deletefront() {
    if (isempty()) {
        printf("Deque is empty\n");
        return -1;
    }
    int item = deque[f];
    if (f == r) {
        f = r = -1;
    } else {
        f = (f + 1) % size;
    }
    return item;
}

int deleterear() {
    if (isempty()) {
        printf("Deque is empty\n");
        return -1;
    }
    int item = deque[r];
    if (f == r) {
        f = r = -1;  
    } else {
        r = (r - 1 + size) % size;  
    }
    return item;
}

void main()
 {
    int choice, n;
    do {
        printf("\nMENU");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Status");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &n);
                insertfront(n);
                break;
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &n);
                insertrear(n);
                break;
            case 3:
                n = deletefront();
                if (n != -1) printf("Deleted element from front: %d\n", n);
                break;
            case 4:
                n = deleterear();
                if (n != -1) printf("Deleted element from rear: %d\n", n);
                break;
             case 5:
                if (isempty()) {
                    printf("Deque is empty\n");
                } else if (isfull()) {
                    printf("Deque is full\n");
                } else {
                    printf("Space available in deque\n");
                }
                break;
            case 6:
                printf("Exiting\n");
                break;
            
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
}

