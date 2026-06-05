
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
typedef struct avl_node {
    int data;
    struct avl_node *left;
    struct avl_node *right;
    int height;
} avl_node;

avl_node* root = NULL;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(avl_node* n) {
    return n ? n->height : 0;
}

int getBalance(avl_node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

avl_node* createNode(int data) {
    avl_node* node = (avl_node*)malloc(sizeof(avl_node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

avl_node* rightRotate(avl_node* y) {
    avl_node* x = y->left;
    avl_node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

avl_node* leftRotate(avl_node* x) {
    avl_node* y = x->right;
    avl_node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

avl_node* insert(avl_node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

avl_node* minValueNode(avl_node* node) {
    avl_node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

avl_node* deleteNode(avl_node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            avl_node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            avl_node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(avl_node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(avl_node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(avl_node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void display(avl_node* ptr, int level) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        printf("\n");
        for (int i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->data);
        display(ptr->left, level + 1);
    }
}

int main() {
	system("color f0");	
    int choice, item;
        printf("Choices\n");
        printf("1. Insert Element into the tree\n");
        printf("2. Display Balanced AVL Tree\n");
        printf("3. InOrder traversal\n");
        printf("4. PreOrder traversal\n");
        printf("5. PostOrder traversal\n");
        printf("6. Delete Element from the tree\n");
        printf("7. Exit\n");
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &item);
            root = insert(root, item);
            printf("\n");
            break;
        case 2:
            printf("Balanced AVL Tree:\n");
            display(root, 1);
            printf("\n");
            break;
        case 3:
            printf("InOrder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("PreOrder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("PostOrder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}


