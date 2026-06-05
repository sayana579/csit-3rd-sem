
#include<stdio.h>
#include<iostream>
#define MAX 20
void ssort(int a[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		int l=i; 
		for(j=i+1;j<n;j++)
		{
			if (a[l]>a[j])
			{
				l=j;
			}
		}
		int temp=a[l];
		a[l]=a[i];
		a[i]=temp;
	}
}
int main()
{
	system ("color f0");
	int a[MAX],n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter the list of elements: ");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	ssort(a,n);
	printf ("The sorted list(using selection sort):");
	for (int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

