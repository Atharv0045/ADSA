#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insert(struct node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node* search(struct node *root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void main()
{
    struct node *root = NULL;
    struct node *result;
    int n, i, value, key;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter key to search: ");
    scanf("%d", &key);

    result = search(root, key);

    if(result != NULL)
        printf("Key %d is found in BST.", key);
    else
        printf("Key %d is not found in BST.", key);

    getch();
}