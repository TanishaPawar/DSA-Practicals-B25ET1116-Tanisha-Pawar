#include <stdio.h>
#define SIZE 5

char buffer[SIZE];
int front = 0, rear = 0, count = 0;

void send(char ch) {
    if (count == SIZE)
        printf("Buffer full\n");
    else {
        buffer[rear] = ch;
        rear = (rear + 1) % SIZE;
        count++;
    }
}

void receive() {
    if (count == 0)
        printf("Buffer empty\n");
    else {
        printf("Received: %c\n", buffer[front]);
        front = (front + 1) % SIZE;
        count--;
    }
}

int main() {
    char ch;
    int choice;

    do {
        printf("\n1. Send\n2. Receive\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter character: ");
            scanf(" %c", &ch);
            send(ch);
        }
        else if (choice == 2)
            receive();
        
    } while (choice != 3);

    return 0;
}
