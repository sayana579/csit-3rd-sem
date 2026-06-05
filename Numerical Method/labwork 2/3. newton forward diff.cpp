#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20], xp, h, u, yp, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values (equally spaced):\n");
    for(i = 0; i < n; i++) scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++) scanf("%f", &y[i][0]);

    for(j = 1; j < n; j++) {
        for(i = 0; i < n-j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    printf("Enter value to interpolate: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    u = (xp - x[0]) / h;
    yp = y[0][0];
    term = 1;

    for(i = 1; i < n; i++) {
        term = 1;
        for(j = 0; j < i; j++) term *= (u - j);
        yp += (term * y[0][i]) / 1; 
        // factorial division will be added below
    }

    int fact = 1;
    for(i = 1; i < n; i++) {
        fact *= i;
        yp += (y[0][i] * term) / fact;
    }

    printf("Interpolated value at %.2f = %.6f\n", xp, yp);
    return 0;
}

