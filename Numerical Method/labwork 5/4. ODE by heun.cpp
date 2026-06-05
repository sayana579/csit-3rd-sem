#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return 2 * y / x;
}

int main()
{
    int n, i;
    float x, y, xp, h, a, b;

    printf("Input initial values of x: ");
    scanf("%f", &x);

    printf("Input initial values of y: ");
    scanf("%f", &y);

    printf("Input x at which y is required: ");
    scanf("%f", &xp);

    printf("Input step-size h: ");
    scanf("%f", &h);

    n = (int)((xp - x) / h + 0.5);

    for (i = 1; i <= n; i++)
    {
        a = f(x, y);
        b = f(x + h, y + a * h);
        x += h;
        y = y + 0.5 * h * (a + b);
        printf("\n%d\t%f\t%f\n", i, x, y);
    }
    printf("\nValue of y at x = %f is %f\n", xp, y);

    return 0;
}
