#include <stdio.h>
#include <string.h>

int main() {
    char bin1[20], bin2[20], sum[20], diff[20];
    int i, carry = 0, borrow = 0;
    int len;

    printf("Enter first binary number: ");
    scanf("%s", bin1);

    printf("Enter second binary number: ");
    scanf("%s", bin2);

    len = strlen(bin1);   // assume both binaries are of same length

    /* -------- Binary Addition -------- */
    for (i = len - 1; i >= 0; i--) {
        int b1 = bin1[i] - '0';
        int b2 = bin2[i] - '0';
        int s = b1 + b2 + carry;

        sum[i] = (s % 2) + '0';
        carry = s / 2;
    }
    sum[len] = '\0';

    if (carry)
        printf("Binary Addition = 1%s\n", sum);
    else
        printf("Binary Addition = %s\n", sum);

    /* -------- Binary Subtraction -------- */
    for (i = len - 1; i >= 0; i--) {
        int b1 = bin1[i] - '0';
        int b2 = bin2[i] - '0';

        b1 = b1 - borrow;

        if (b1 < b2) {
            b1 = b1 + 2;
            borrow = 1;
        } else {
            borrow = 0;
        }

        diff[i] = (b1 - b2) + '0';
    }
    diff[len] = '\0';

    printf("Binary Subtraction = %s\n", diff);

    return 0;
}

