
#include<stdio.h>
#include<iostream>
#define MAX 10
int hashtable[MAX];
void initialize()
{
	for(int i=0;i<MAX;i++)
	hashtable[i]=-1;
}
int hash(int key)
{
	return key%MAX;
}
void enter(int key)
{
	int index=hash(key);
		for (int j=0;j<MAX;j++)
		{
			int i=(index+j*j)%MAX;
			if (hashtable[i]==-1)
			{
				hashtable[i]=key;
				return;
			}		
		}
		printf ("Hash table is full");
}
int search(int target)
	{
	int i=hash(target);
		for (int j=1;j<MAX;j++)
		{
			if (hashtable[i]==target)
			{
				return i;
			}
				i=(i+j*j)%MAX;	
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
	printf ("Hashtable:(using quadratic probing)\n");
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

