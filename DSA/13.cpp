
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
struct node
{
	int item;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void createnode(int a)
{
	node *n=(node*)malloc(sizeof(node));
	n->item=a;
	n->next=NULL;
	if(head==NULL)
	head=n;
	else
	{
		node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=n;
	}
}
void insertbeg(int value)
{
	node *n=(node*)malloc(sizeof(node));
	n->item=value;
	n->next=head;
	head=n;
}
void insertend(int value)
{
	node *n=(node*)malloc(sizeof(node));
	n->item=value;
	n->next=NULL;
	node *temp=head;
	while (temp->next!=NULL)
	temp=temp->next;
	temp->next=n;
}
void insertpos(int value,int pos)
{
	if (pos == 1) {
        insertbeg(value);
        return;
    }
	node *n=(node*)malloc(sizeof(node));
	n->item=value;
	node *temp=head;
	for(int i=1;i<pos-1;i++)
	temp=temp->next;
	
	if (temp == NULL) 
	{
        printf("Not possible");
        free(n);
        return;
    }
	n->next=temp->next;
	temp->next=n;
}
void deletebeg()
{
	if (head == NULL) {
        printf("Empty list");
        return;
    }
	head=head->next;
}
void deleteend()
{
	if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    if (head->next == NULL) 
	{
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
}
void deletepos(int pos)
{
	if (pos == 1) {
        deletebeg();
        return;
    }
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    node* temp = head;
    for(int i=1;i<pos-1;i++)
	temp=temp->next;
	
	node* n = temp->next;
    temp->next = n->next;
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
	insertbeg(2);
	insertbeg(3);
	insertbeg(5);
	insertbeg(6);
	printf("Linked list:\n ");
	display();
	printf("Linked list:(after inserting 4 at position 2)\n ");
	insertpos(4,2);
	display();
	printf("Linked list:(after inserting at the end)\n ");
	insertend(7);
	display();
	
	deletebeg();
	printf("Linked list:(after deleting from the beginning)\n ");
	display();
	deletepos(4);
	printf("Linked list:(after deleting from position 4)\n ");
	display();
	deleteend();
	printf("Linked list:(after deleting from the end)\n ");
	display();
	return 0;
}

