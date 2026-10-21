
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;

    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = top;
        printf("Deleted: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = top;

    if (top == NULL)
        printf("Stack is empty\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}
