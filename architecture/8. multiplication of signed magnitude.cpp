#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binaryToDecimal(char bin[]) {
    int n = strlen(bin);
    int decimal = 0;
    for (int i = 1; i < n; i++) { // skip sign bit
        decimal = decimal * 2 + (bin[i] - '0');
    }
    return decimal;
}

void decimalToBinary(int num, int bits, char result[]) {
    result[bits] = '\0';
    for (int i = bits - 1; i >= 0; i--) {
        result[i] = (num % 2) + '0';
        num /= 2;
    }
}

int main() {
    char A[20], B[20], result[40];
    int signA, signB, signR;
    int magA, magB, magR;
    int n1, n2, nR;

    printf("Enter first signed magnitude binary number: ");
    scanf("%s", A);

    printf("Enter second signed magnitude binary number: ");
    scanf("%s", B);

    n1 = strlen(A);
    n2 = strlen(B);
    nR = n1 + n2 - 1; // maximum bits required for magnitude

    // Extract signs
    signA = A[0] - '0';
    signB = B[0] - '0';

    // Determine result sign (XOR of input signs)
    signR = signA ^ signB;

    // Convert magnitude to decimal
    magA = binaryToDecimal(A);
    magB = binaryToDecimal(B);

    // Multiply magnitudes
    magR = magA * magB;

    // Convert result magnitude to binary
    decimalToBinary(magR, nR, result);

    // Add sign bit at the front
    for (int i = nR; i >= 1; i--) {
        result[i] = result[i - 1];
    }
    result[0] = signR + '0';
    result[nR + 1] = '\0';

    printf("Result (Signed Magnitude) = %s\n", result);

    return 0;
}

