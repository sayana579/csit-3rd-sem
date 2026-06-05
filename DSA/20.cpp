
#include<stdio.h>
#include<iostream>
#define MAX 20
void ssort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap =gap/ 2) 
	{    
        for (int i = gap; i < n; i++) 
		{
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j =j-gap;
            }
            a[j] = temp;
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
	ssort(a,n);
	printf ("The sorted list(using shell sort):");
	for (int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

