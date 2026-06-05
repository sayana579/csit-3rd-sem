#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if(top == MAX-1) printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = x;
        printf("%d pushed\n", x);
    }
}

void pop() {
    if(top == -1) printf("Stack Underflow\n");
    else {
        printf("%d popped\n", stack[top]);
        top--;
    }
}

void display() {
    if(top == -1) printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for(int i = top; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while(1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
        } else if(choice == 2) {
            pop();
        } else if(choice == 3) {
            display();
        } else if(choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

