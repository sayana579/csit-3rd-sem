
#include <stdio.h>
#include<iostream>
#define MAX 20
void enter(int a[], int n)
{
	printf ("Enter the array: ");
	for (int i=0; i<n; i++)
	{
		scanf ("%d",&a[i]);
	}
}
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int a[], int n, int i) {
    int la = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[la])
        la = l;
    if (r < n && a[r] > a[la])
        la = r;
    if (la != i) {
        swap(&a[i], &a[la]);
        heapify(a, n, la);
    }
}

void heaps(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
int main() 
{
	system("color f0");
    int a[MAX],n;
    printf ("Enter the no of elements: ");
    scanf("%d",&n);
    enter(a,n);
    printf ("Unsorted array: ");
    print(a, n);
    heaps(a, n);
    printf ("Sorted array: ");
    print(a, n);
    return 0;
}



