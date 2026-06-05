#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long n);
long long decimalToBinary(int n);

int main() {
    long long b;
    int d;

    printf("Enter a binary number: ");
    scanf("%lld", &b);
    printf("%lld in binary = %d in decimal\n", b, binaryToDecimal(b));

    // Decimal to Binary
    printf("Enter a decimal number: ");
    scanf("%d", &d);
    printf("%d in decimal = %lld in binary\n", d, decimalToBinary(d));

    return 0;
}

int binaryToDecimal(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

long long decimalToBinary(int n) {
    long long bin = 0;
    int rem, i = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

