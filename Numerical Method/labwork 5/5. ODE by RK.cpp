
#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return x * x - y * y;
}

int main()
{
    int n, i;
    float x, y, xp, h, a, b, c, d;

    printf("\nInput initial value of x: ");
    scanf("%f", &x);

    printf("Input initial value of y: ");
    scanf("%f", &y);

    printf("Input x at which y is required: ");
    scanf("%f", &xp);

    printf("Input step-size h: ");
    scanf("%f", &h);

    n = (int)((xp - x) / h + 0.5);

    for (i = 1; i <= n; i++)
    {
        a = f(x, y);
        b = f(x + 0.5 * h, y + 0.5 * a * h);
        c = f(x + 0.5 * h, y + 0.5 * b * h);
        d = f(x + h, y + c * h);
        x += h;
        y = y + (a + 2.0 * b + 2.0 * c + d) * h / 6.0;
        printf("Value of y at x = %f is %f.\n", x, y);
    }

    return 0;
}

