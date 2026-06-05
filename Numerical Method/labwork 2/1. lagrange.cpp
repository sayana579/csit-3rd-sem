#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], xp, yp = 0.0, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for(i = 0; i < n; i++)
	 scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++)
	 scanf("%f", &y[i]);

    printf("Enter value to interpolate: ");
    scanf("%f", &xp);

    for(i = 0; i < n; i++) {
        term = y[i];
        for(j = 0; j < n; j++) {
            if(j != i) 
			term = term * (xp - x[j]) / (x[i] - x[j]);
        }
        yp += term;
    }

    printf("Interpolated value at %.2f = %.6f\n", xp, yp);
    return 0;
}

