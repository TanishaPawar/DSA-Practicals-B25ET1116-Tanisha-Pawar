#include <stdio.h>

// STACK
void stack() {
    int stack[5];
    int top = -1;
    int choice, value;

    do {
        printf("\n\nStack Operations: \n1. Push \n2. Pop \n3. Display \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (top == 4) {
                printf("Stack Overflowed.");
            } else {
                printf("Enter value: ");
                scanf("%d", &value);
                top++;
                stack[top] = value;
                printf("Value pushed.");
            }
            break;

        case 2:
            if (top == -1) {
                printf("Stack Underflowed. ");
            } else {
                printf("Deleted value: %d", stack[top]);
                top--;
            }
            break;

        case 3:
            if (top == -1) {
                printf("Stack is empty. ");
            } else {
                printf("Stack: ");
                for (int i = top; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
            }
            break;

        case 4:
            printf("Exiting Stack...\n\n");
            break;

        default:
            printf("Invalid choice!");
        }

    } while (choice != 4);
}

// QUEUE
void queue() {
    int queue[5];
    int front = -1, rear = -1;
    int choice, value;

    do {
        printf("\n\nQueue Operations: \n1. Insert \n2. Delete \n3. Display \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (rear == 4) {
                printf("Queue Overflowed. ");
            } else {
                printf("Enter value: ");
                scanf("%d", &value);

                if (front == -1)
                    front = 0;

                rear++;
                queue[rear] = value;

                printf("Value inserted.");
            }
            break;

        case 2:
            if (front == -1 || front > rear) {
                printf("Queue Underflowed. ");
            } else {
                printf("Deleted value: %d", queue[front]);
                front++;

                if (front > rear) {
                    front = -1;
                    rear = -1;
                }
            }
            break;

        case 3:
            if (front == -1) {
                printf("Queue is empty!");
            } else {
                printf("Queue: ");
                for (int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
            }
            break;

        case 4:
            printf("Exiting Queue...\n\n");
            break;

        default:
            printf("Invalid choice!");
        }

    } while (choice != 4);
}

// MAIN
int main() {
    int choice;

    do {
        printf("STACK AND QUEUE \n1. Stack \n2. Queue \n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            stack();
            break;

        case 2:
            queue();
            break;

        case 3:
            printf("Program ended.");
            break;

        default:
            printf("Invalid choice!");
        }

    } while (choice != 3);

    return 0;
}