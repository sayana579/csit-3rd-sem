#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;

void Insert()
{
   int val;

   printf("Insert the element in queue : \n");
   scanf("%d", &val);

   if (rear == NULL)
   {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   }
   else
   {
      temp = (struct node *)malloc(sizeof(struct node));
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear = temp;
   }
}

void Delete()
{
   temp = front;
   if (front == NULL)
   {
      printf("Underflow\n");
      return;
   }
   else if (temp->next != NULL)
   {
      temp = temp->next;
      printf("Element deleted from queue is : %d\n", front->data);
      free(front);
      front = temp;
   }
   else
   {
      printf("Element deleted from queue is : %d\n", front->data);
      free(front);
      front = NULL;
      rear = NULL;
   }
}

void Display()
{
   temp = front;
   if ((front == NULL) && (rear == NULL))
   {
      printf("Queue is empty\n");
      return;
   }
   printf("Queue elements are: ");
   while (temp != NULL)
   {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main()
{
   int ch;

   printf("1) Insert element to queue\n");
   printf("2) Delete element from queue\n");
   printf("3) Display all the elements of queue\n");
   printf("4) Exit\n");

   do
   {
      printf("Enter your choice : \n");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         Insert();
         break;
      case 2:
         Delete();
         break;
      case 3:
         Display();
         break;
      case 4:
         printf("Exit\n");
         break;
      default:
         printf("Invalid choice\n");
      }
   } while (ch != 4);
   return 0;
}

