#include <stdio.h>

int main() {
    int n, i;
    float coeff[20], x, result;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficients (highest degree first):\n");
    for(i = 0; i <= n; i++) scanf("%f", &coeff[i]);

    printf("Enter value of x: ");
    scanf("%f", &x);

    result = coeff[0];
    for(i = 1; i <= n; i++) {
        result = result * x + coeff[i];
    }

    printf("Value of polynomial at x = %.2f is %.6f\n", x, result);
    return 0;
}

