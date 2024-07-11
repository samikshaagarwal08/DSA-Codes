#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

struct node {
    int data, height;
    struct node *left, *right;
};

struct node *createnode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int height(struct node *r) {
    if (!r)
        return 0;
    return r->height;
}

int getbalance(struct node *root) {
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

struct node *leftRotate(struct node *root) {
    struct node *y = root->right;
    struct node *tt = y->left;
    y->left = root;
    root->right = tt;
    root->height = max(height(root->left), height(root->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct node *rightRotate(struct node *root) {
    struct node *y = root->left;
    struct node *tt = y->right;
    y->right = root;
    root->left = tt;
    root->height = max(height(root->left), height(root->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct node *createbst(struct node *root, int data) {
    if (root == NULL)
        return createnode(data);

    if (data < root->data)
        root->left = createbst(root->left, data);
    else if (data > root->data)
        root->right = createbst(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getbalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct node *q[100];
int f = -1, r = -1;

void enqueue(struct node *data) {
    if (f == -1) {
        f = r = 0;
    } else {
        r++;
    }
    q[r] = data;
}

void dequeue() {
    if (f == r) {
        f = r = -1;
    } else {
        f++;
    }
}

void levelview(struct node *root) {
    enqueue(root);
    enqueue(NULL);
    while (f != -1) {
        root = q[f];
        dequeue();
        if (root == NULL) {
            if (f == -1) {
                return;
            }
            printf("\n");
            enqueue(NULL);
            continue;
        }
        printf("%d ", root->data);
        if (root->left != NULL) {
            enqueue(root->left);
        }
        if (root->right != NULL) {
            enqueue(root->right);
        }
    }
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deletenode(struct node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getbalance(root);

    if (balance > 1 && getbalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getbalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getbalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getbalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    struct node *root = NULL;
    int choice, value;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(a[0]),i,height,key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into AVL tree\n");
        printf("2. Pre-order traversal\n");
        printf("3. Level-order traversal\n");
        printf("4. Delete from AVL tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for(i=0;i<n;i++)
                    root=createbst(root,a[i]);
                break;
            case 2:
                printf("Pre-order traversal:\n");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Level-order traversal:\n");
                levelview(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deletenode(root, value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}



//               4
        //  2               8
//       1     3        6       9
//                   5     7       10 
