#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;

Node *newNode(int item){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key){
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void preOrder(Node *root){
    if (root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root ->right);
    }
}

void inOrder(Node *root){
    if (root != NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root ->right);
    }
}

void postOrder(Node *root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root ->right);
        printf("%d ", root->key);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);

    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Binary Tree in PreOrder : ");
    preOrder(root);
    printf("\n");

    printf("Binary Tree in InOrder  : ");
    inOrder(root);
    printf("\n");

    printf("Binary Tree in PostOrder: ");
    postOrder(root);
    printf("\n");


    return 0;
}

