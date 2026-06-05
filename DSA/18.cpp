
#include<stdio.h>
#include<iostream>
#define MAX 20
void bsort(int a[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0; j<n-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
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
	bsort(a,n);
	printf ("The sorted list(using bubble sort):");
	for (int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

