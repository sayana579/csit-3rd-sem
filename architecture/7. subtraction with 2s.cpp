#include <stdio.h>
#include <string.h>

/* Function to find 2's complement of a binary number */
void twosComplement(char bin[], char result[], int n) {
    int i;
    // Step 1: 1's complement
    for (i = 0; i < n; i++) {
        result[i] = (bin[i] == '0') ? '1' : '0';
    }
    // Step 2: Add 1
    int carry = 1;
    for (i = n - 1; i >= 0; i--) {
        if (result[i] == '1' && carry == 1) {
            result[i] = '0';
        } else if (result[i] == '0' && carry == 1) {
            result[i] = '1';
            carry = 0;
        }
    }
}

/* Function to add two binary numbers (same length) */
void binaryAdd(char A[], char B[], char sum[], int n) {
    int carry = 0, i;
    for (i = n - 1; i >= 0; i--) {
        int bitA = A[i] - '0';
        int bitB = B[i] - '0';
        int s = bitA + bitB + carry;
        sum[i] = (s % 2) + '0';
        carry = s / 2;
    }
}

int main() {
    char A[20], B[20], B_neg[20], result[20];
    int n;

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter first binary number (A) in 2's complement: ");
    scanf("%s", A);

    printf("Enter second binary number (B) in 2's complement: ");
    scanf("%s", B);

    // Find 2's complement of B (i.e., -B)
    twosComplement(B, B_neg, n);

    // Add A + (-B)
    binaryAdd(A, B_neg, result, n);

    printf("Result of A - B (in 2's complement) = %s\n", result);

    return 0;
}

