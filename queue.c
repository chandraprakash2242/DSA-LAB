#include <stdio.h>
#define size 100

int queue[size];
int f = -1, r = -1;

int isempty() {
    if (f == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if ((r + 1) % size == f)
        return 1;
    else
        return 0;
}

void insertque(int item) {
    if (f == -1)
        f = r = 0;
    else
        r = (r + 1) % size;
    queue[r] = item;
}

int delque() {
    int item = queue[f];
    if (f == r)
        f = r = -1;
    else
        f = (f + 1) % size;
    return item;
}

void peek() {
    printf("Element is %d\n", queue[f]);
}

int main(void) {
    int choice, n;
    do {
        printf("\nMENU");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Peek");
        printf("\n4. Status");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (isfull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter element: ");
                    scanf("%d", &n);
                    insertque(n);
                }
                break;
            }
            case 2: {
                if (isempty()) {
                    printf("Queue is empty\n");
                } else {
                    n = delque();
                    printf("Deleted element %d\n", n);
                }
                break;
            }
            case 3: {
                if (isempty()) {
                    printf("Queue is empty\n");
                } else {
                    peek();
                }
                break;
            }
            case 4: {
                if (isempty()) {
                    printf("Queue is empty\n");
                } else if (isfull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Space available\n");
                }
                break;
            }
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
