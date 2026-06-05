#include <stdio.h>
#include <string.h>

int main() {
    char A[20], B[20], result[20];
    int signA, signB;
    int magA = 0, magB = 0, magRes = 0;
    int i, base = 1;

    printf("Enter first signed magnitude binary number: ");
    scanf("%s", A);

    printf("Enter second signed magnitude binary number: ");
    scanf("%s", B);

    /* Extract sign bits */
    signA = A[0] - '0';
    signB = B[0] - '0';

    /* Convert magnitude bits to decimal */
    for (i = strlen(A) - 1; i > 0; i--) {
        magA += (A[i] - '0') * base;
        magB += (B[i] - '0') * base;
        base *= 2;
    }

    /* Subtraction: A - B */
    if (signA == signB) {
        if (magA >= magB) {
            magRes = magA - magB;
            result[0] = signA + '0';
        } else {
            magRes = magB - magA;
            result[0] = (signA == 0) ? '1' : '0';
        }
    } else {
        magRes = magA + magB;
        result[0] = signA + '0';
    }

    /* Convert magnitude result to binary */
    int idx = strlen(A) - 1;
    while (idx > 0) {
        result[idx] = (magRes % 2) + '0';
        magRes /= 2;
        idx--;
    }
    result[strlen(A)] = '\0';

    printf("Result (Signed Magnitude) = %s\n", result);

    return 0;
}

