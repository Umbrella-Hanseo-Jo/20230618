#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in a binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into a binary search tree
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, create a new node and return it
    if (node == NULL)
        return createNode(key);
        
    // Find the appropriate position to insert and recursively insert
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
        
    return node;
}

// Function to perform inorder traversal of a binary search tree
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->key);
        inorderTraversal(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    // Insert the given keys into the binary search tree
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);
    
    // Print the result of inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    
    return 0;
}