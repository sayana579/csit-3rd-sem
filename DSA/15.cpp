
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct node {
	int item;
	struct node *next;
};
typedef struct node node;
node *head = NULL;

void createnode(int a) {
	node *n = (node*)malloc(sizeof(node));
	n->item = a;
	if (head == NULL) {
		head = n;
		n->next = head;
	} else {
		node *temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = n;
		n->next = head;
	}
}

void insertbeg(int value) {
	node *n = (node*)malloc(sizeof(node));
	n->item = value;
	if (head == NULL) {
		head = n;
		n->next = head;
	} else {
		node *temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		n->next = head;
		temp->next = n;
		head = n;
	}
}

void insertend(int value) {
	node *n = (node*)malloc(sizeof(node));
	n->item = value;
	if (head == NULL) {
		head = n;
		n->next = head;
	} else {
		node *temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = n;
		n->next = head;
	}
}

void insertpos(int value, int pos) {
	if (pos == 1) {
		insertbeg(value);
		return;
	}
	node *n = (node*)malloc(sizeof(node));
	n->item = value;
	node *temp = head;
	for (int i = 1; i < pos - 1; i++) {
		temp = temp->next;
		if (temp == head) {
			printf("Not possible\n");
			free(n);
			return;
		}
	}
	n->next = temp->next;
	temp->next = n;
}

void deletebeg() {
	if (head == NULL) {
		printf("Empty list\n");
		return;
	}
	if (head->next == head) {
		free(head);
		head = NULL;
	} else {
		node *temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		node *del = head;
		head = head->next;
		temp->next = head;
		free(del);
	}
}

void deleteend() {
	if (head == NULL) {
		printf("Empty list\n");
		return;
	}
	if (head->next == head) {
		free(head);
		head = NULL;
	} else {
		node *temp = head;
		while (temp->next->next != head) {
			temp = temp->next;
		}
		free(temp->next);
		temp->next = head;
	}
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
	node *temp = head;
	for (int i = 1; i < pos - 1; i++) {
		temp = temp->next;
		if (temp->next == head) {
			printf("Not possible\n");
			return;
		}
	}
	node *del = temp->next;
	temp->next = del->next;
	free(del);
}

void display() {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	node *temp = head;
	do {
		printf("%d ", temp->item);
		temp = temp->next;
	} while (temp != head);
	printf("\n");
}

int main() {
	system("color f0");
	insertbeg(20);
	insertbeg(35);
	insertbeg(52);
	insertbeg(68);
	printf("Circular Linked list:\n ");
	display();

	printf("Circular Linked list:(after inserting 43 at position 2)\n ");
	insertpos(43, 2);
	display();

	printf("Circular Linked list:(after inserting at the end)\n ");
	insertend(71);
	display();

	deletebeg();
	printf("Circular Linked list:(after deleting from the beginning)\n ");
	display();

	deletepos(4);
	printf("Circular Linked list:(after deleting from position 4)\n ");
	display();

	deleteend();
	printf("Circular Linked list:(after deleting from the end)\n ");
	display();

	return 0;
}


