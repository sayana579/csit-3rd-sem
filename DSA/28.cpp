
#include<stdio.h>
#include<iostream>
#define MAX 7
int hashtable[MAX];
void initialize()
{
	for (int i=0;i<MAX;i++)
	hashtable[i]=-1;
}
int hash1(int key)
{
	return key%MAX;
}
int hash2(int key,int R)
{
	return (R-(key%R));
}
void enter(int key)
{
	int index=hash1(key);
	for (int j=0;j<MAX;j++)
	{
	  int i= (index+j*hash2(key,index))%MAX;
	  if (hashtable[i]==-1)
			{
				hashtable[i]=key;
				return;
			}	
	}
	printf ("Hash table is full");
}
void display()
{
	for (int i=0;i<MAX; i++)
	printf ("Index %d: %d\n",i,hashtable[i]);
}
int search(int target)
{
	int index=hash1(target);
	for (int j=0;j<MAX;j++)
	{
	  int i= (index+j*hash2(target,index))%MAX;
	  if (hashtable[i]==target)
			{
				return i;
			}	
	}
	return -1;
}
	int main()
{
	system ("color f0");
	int a[MAX],n,t,target;
	printf ("Enter no of elements:");
	scanf ("%d",&n);
	printf ("Enter array elements: ");
	for(int i=0;i<n;i++)
	scanf ("%d",&a[i]);
	initialize();
	for(int i=0;i<n;i++)
	{
		enter(a[i]);
	}
	printf ("Hashtable:(using double hashing)\n");
	display();
	printf("Enter element to search: ");
	scanf("%d",&target);
	t=search(target);
	if (t==-1)
	printf("Element not found");
	else
	printf("The element is found in index %d",t);
	return 0;
}

