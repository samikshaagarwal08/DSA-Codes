#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert nodes in level order
struct Node* insert(int arr[], int i, int n) {
    struct Node* root = NULL;
    // Base case for recursion
    if (i < n) {
        root = newNode(arr[i]);
        
        // insert left child
        root->left = insert(arr, 2 * i + 1, n);
        
        // insert right child
        root->right = insert(arr, 2 * i + 2, n);
    }
    return root;
}

// Function to perform inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

//function to calculate sum of all nodes
int sumNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    int sum=root->data + sumNodes(root->left) + sumNodes(root->right);
    return sum;
}

// function to calculate product of all nodes
int productNodes(struct Node* root) {
    if (root == NULL)
        return 1;
    int product= root->data * productNodes(root->left) * productNodes(root->right);
    return product;
}

//  function to count all nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    int count= 1 + countNodes(root->left) + countNodes(root->right);
    return count;
}

//              1
//           2     3
//        4    5 6   7

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = insert(arr, 0, n);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    int sum = sumNodes(root);
    int count = countNodes(root);
    double average = (double)sum / count;
    int product = productNodes(root);
    
    printf("Sum of all nodes: %d\n", sum);
    printf("Average of all nodes: %.2f\n", average);
    printf("Product of all nodes: %d\n", product);

    return 0;
}
