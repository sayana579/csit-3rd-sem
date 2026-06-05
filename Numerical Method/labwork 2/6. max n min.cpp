#include <stdio.h>

int main() {
    int n, i;
    float x[20], y[20];

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for(i = 0; i < n; i++) scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++) scanf("%f", &y[i]);

    for(i = 1; i < n-1; i++) {
        if(y[i] > y[i-1] && y[i] > y[i+1]) 
            printf("Local Maximum at x = %.2f, y = %.2f\n", x[i], y[i]);
        if(y[i] < y[i-1] && y[i] < y[i+1]) 
            printf("Local Minimum at x = %.2f, y = %.2f\n", x[i], y[i]);
    }

    return 0;
}

