#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // 1. If the key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // 2. If the key is greater than the element at mid, then it can only be present in the right subarray
        if (arr[mid] < key) {
            low = mid + 1;
        }

        // 3. If the key is less than the element at mid, then it can only be present in the left subarray
        else {
            high = mid - 1;
        }
    }

    // If the key is not found
    return -1;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // VLA (Variable Length Array) - supported in C99, but might be an issue in C++ (fixed with standard C syntax)
    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}

