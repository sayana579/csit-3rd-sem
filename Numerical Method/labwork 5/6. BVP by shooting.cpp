#include <stdio.h>

int main() {
    float x0, y0, xn, yn, h;
    float z1, z2, y1, y2, z_final;
    float x, y, z, k1, k2;

    // 1. ????? Boundary Conditions
    printf("Enter x0 and y0: ");
    scanf("%f %f", &x0, &y0);
    printf("Enter xn and yn: ");
    scanf("%f %f", &xn, &yn);
    printf("Enter step size h: ");
    scanf("%f", &h);

    // 2. ?? ??????? ???? (guesses) ???
    printf("Enter two initial slope guesses (z1 and z2): ");
    scanf("%f %f", &z1, &z2);

    // ???? guess (z1) ?? ??? ?? ????
    x = x0; y = y0; z = z1;
    while(x < xn) {
        k1 = h * z;       // dy/dx = z
        k2 = h * (6 * x); // dz/dx = 6x
        y = y + k1;
        z = z + k2;
        x = x + h;
    }
    y1 = y; // z1 ?? ??? ??????? ????? y

    // ????? guess (z2) ?? ??? ?? ????
    x = x0; y = y0; z = z2;
    while(x < xn) {
        k1 = h * z;
        k2 = h * (6 * x);
        y = y + k1;
        z = z + k2;
        x = x + h;
    }
    y2 = y; // z2 ?? ??? ??????? ????? y

    // 3. Linear Interpolation ?? ??? ???? ???????
    z_final = z1 + (z2 - z1) * (yn - y1) / (y2 - y1);

    // 4. ??? ???? ?? ??? ????? ?????? ???????
    x = x0; y = y0; z = z_final;
    printf("\n--- Final Calculation ---\n");
    while(x <= xn) {
        printf("At x = %.2f, y = %.4f\n", x, y);
        k1 = h * z;
        k2 = h * (6 * x);
        y = y + k1;
        z = z + k2;
        x = x + h;
    }

    printf("\nCorrect Initial Slope found: %f\n", z_final);

    return 0;
}

