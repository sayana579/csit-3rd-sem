
#include <stdio.h>
#include<iostream>
#define MAX 20
void m(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void msort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        msort(a, left, mid);
        msort(a, mid + 1, right);
        m(a, left, mid, right);
    }
}

int main() {
	system("color f0");
    int a[MAX], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the list of elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    msort(a, 0, n - 1);
    
    printf("The sorted list(using merge sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    return 0;
}

