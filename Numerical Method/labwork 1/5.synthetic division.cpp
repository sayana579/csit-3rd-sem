#include <stdio.h>

int main() {
    int n, i, j;
    float coeff[20], divisor, result[20];

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficients (highest degree first):\n");
    for(i = 0; i <= n; i++) scanf("%f", &coeff[i]);

    printf("Enter value of divisor (x - a), enter a: ");
    scanf("%f", &divisor);

    result[0] = coeff[0];
    for(i = 1; i <= n; i++) {
        result[i] = coeff[i] + result[i-1]*divisor;
    }

    printf("Quotient coefficients:\n");
    for(i = 0; i < n; i++) printf("%.6f ", result[i]);
    printf("\nRemainder = %.6f\n", result[n]);

    return 0;
}

