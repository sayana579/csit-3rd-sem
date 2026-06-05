#include <stdio.h>
#include <string.h>

int main() {
    char bin1[20], bin2[20], result[20];
    int sign1, sign2;
    int mag1 = 0, mag2 = 0, magRes = 0;
    int i, base = 1;

    printf("Enter first signed magnitude binary number: ");
    scanf("%s", bin1);

    printf("Enter second signed magnitude binary number: ");
    scanf("%s", bin2);

    /* Extract sign bits */
    sign1 = bin1[0] - '0';
    sign2 = bin2[0] - '0';

    /* Convert magnitude bits to decimal */
    for (i = strlen(bin1) - 1; i > 0; i--) {
        mag1 += (bin1[i] - '0') * base;
        mag2 += (bin2[i] - '0') * base;
        base *= 2;
    }

    /* Signed magnitude addition logic */
    if (sign1 == sign2) {
        magRes = mag1 + mag2;
        result[0] = sign1 + '0';
    } else {
        if (mag1 > mag2) {
            magRes = mag1 - mag2;
            result[0] = sign1 + '0';
        } else {
            magRes = mag2 - mag1;
            result[0] = sign2 + '0';
        }
    }

    /* Convert magnitude result back to binary */
    int idx = strlen(bin1) - 1;
    while (idx > 0) {
        result[idx] = (magRes % 2) + '0';
        magRes /= 2;
        idx--;
    }
    result[strlen(bin1)] = '\0';

    printf("Result (Signed Magnitude) = %s\n", result);

    return 0;
}

