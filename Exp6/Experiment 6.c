#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int x){
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    struct node *temp;

    if (top == NULL)
        printf("Stack is empty\n");
    else {
        temp = top;
        printf("Deleted: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node *temp = top;

    if (top == NULL)
        printf("Stack is empty\n");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x;
    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);
    return 0;
}
