#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20], xp, h, u, yp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values (equally spaced):\n");
    for(i = 0; i < n; i++) scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++) scanf("%f", &y[i][0]);

    for(j = 1; j < n; j++) {
        for(i = n-1; i >= j; i--) {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    printf("Enter value to interpolate: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    u = (xp - x[n-1]) / h;
    yp = y[n-1][0];
    float u_term;
    int fact;

    for(i = 1; i < n; i++) {
        u_term = 1;
        for(j = 0; j < i; j++) u_term *= (u + j);
        fact = 1;
        for(j = 1; j <= i; j++) fact *= j;
        yp += (u_term * y[n-1][i]) / fact;
    }

    printf("Interpolated value at %.2f = %.6f\n", xp, yp);
    return 0;
}


