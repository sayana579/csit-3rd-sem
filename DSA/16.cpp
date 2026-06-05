#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct Node *temp = top;
        printf("The popped element is %d\n", temp->data);
        top = top->next;
        free(temp); // It's good practice to free the memory
    }
}

void display() {
    struct Node *ptr;
    if (top == NULL) {
        printf("stack is empty\n");
    } else {
        ptr = top;
        printf("Stack elements are: ");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, val;
    printf("1) Push in stack\n");
    printf("2) Pop from stack\n");
    printf("3) Display stack\n");
    printf("4) Exit\n");

    do {
        printf("Enter choice: \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to be pushed:\n");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (ch != 4);

    return 0;
}

