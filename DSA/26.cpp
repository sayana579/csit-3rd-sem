
#include<stdio.h>
#include<iostream>
#define MAX 10
int hashtable[MAX];
void initialize()
{
	for (int i=0;i<MAX; i++)
	{
		hashtable[i]=-1;
	}
}
int hash(int key)
{
 return key%MAX;
}
void inserting(int key)
{
	int i=hash(key);
	int start=i;
	while (hashtable[i]!=-1)
	{
		i=(i+1)%MAX;
		if (i==start)
		{ 
		printf ("The hash table is full.");
		return;
		}
	}
	hashtable[i]=key;
}
int search(int target)
{
	int i=hash(target);
	int start=i;
	while (hashtable[i]!=-1)
	{
		if (hashtable[i]==target)
		return i;
		i=(i+1)%MAX;
		if (i==start)
		return -1;
	}
	return -1;
}
void display()
{
	for (int i=0;i<MAX;i++)
		printf ("Index %d: %d\n",i,hashtable[i]);
}
int main()
{
	system ("color f0");
	int a[MAX],n,target,t;
	printf ("Enter no of elements:");
	scanf ("%d",&n);
	printf ("Enter array elements: ");
	for(int i=0;i<n;i++)
	scanf ("%d",&a[i]);
	initialize();
	for(int i=0;i<n;i++)
	{
		inserting(a[i]);
	}
	printf ("Hashtable(using linear probing):\n");
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

