#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2329
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a node into the binary tree
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

//2323
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
