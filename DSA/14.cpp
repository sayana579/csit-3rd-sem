
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct node {
    int item;
    struct node* prev;
    struct node* next;
};
typedef struct node node;
node* head = NULL;

void createnode(int value) {
    node* n = (node*)malloc(sizeof(node));
    n->item = value;
    n->prev = NULL;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }
}

void insertbeg(int value) {
    node* n = (node*)malloc(sizeof(node));
    n->item = value;
    n->prev = NULL;
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}

void insertend(int value) {
    node* n = (node*)malloc(sizeof(node));
    n->item = value;
    n->next = NULL;
    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertpos(int value, int pos) {
    if (pos == 1) {
        insertbeg(value);
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Not possible\n");
        return;
    }
    node* n = (node*)malloc(sizeof(node));
    n->item = value;
    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = n;
    temp->next = n;
}

void deletebeg() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteend() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deletepos(int pos) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    if (pos == 1) {
        deletebeg();
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Not possible\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
	system("color f0");
	insertbeg(1);
	insertbeg(8);
	insertbeg(9);
	insertbeg(6);
	printf("Doubly Linked List:\n ");
	display();
	
	printf("Doubly Linked List:(after inserting 3 at position 3)\n ");
	insertpos(3,3);
	display();
	
	printf("Doubly Linked List:(after inserting at the end)\n ");
	insertend(12);
	display();
	
	deletebeg();
	printf("Doubly Linked List:(after deleting from the beginning)\n ");
	display();
	
	deletepos(4);
	printf("Doubly Linked List:(after deleting from position 4)\n ");
	display();
	
	deleteend();
	printf("Doubly Linked List:(after deleting from the end)\n ");
	display();
	
	return 0;
}



