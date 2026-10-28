#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(int x) {
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root, int x) {
    if (root == NULL)
        return create(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void search(struct node *root, int x) {
    if (root == NULL)
        printf("Element not found\n");
    else if (root->data == x)
        printf("Element found\n");
    else if (x < root->data)
        search(root->left, x);
    else
        search(root->right, x);
}

void inorder(struct node *root) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nEnter element to search: ");
    scanf("%d", &x);

    search(root, x);

    return 0;
}
