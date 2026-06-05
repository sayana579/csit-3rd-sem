#include <stdio.h>

int main() {
    int m, q, ac = 0, q1 = 0, count = 4; // 4-bit implementation
    printf("Enter Multiplicand (M) and Multiplier (Q): ");
    scanf("%d %d", &m, &q);

    m &= 0xF; q &= 0xF; // Masking to 4 bits
    printf("\nStep\tAC\tQ\tQ1\n---------------------------\n");

    while (count > 0) {
        int q0 = q & 1;
        if (q0 == 1 && q1 == 0) ac -= m;      // Case 10: AC = AC - M
        else if (q0 == 0 && q1 == 1) ac += m; // Case 01: AC = AC + M

        ac &= 0xF; // Ensure AC stays 4-bit

        // Arithmetic Right Shift (ASR)
        q1 = q & 1;
        q = (q >> 1) | ((ac & 1) << 3);
        ac = (ac >> 1) | (ac & 0x8); // MSB (sign bit) preserve ????
        
        printf("%d\t%X\t%X\t%d\n", 5-count, ac, q, q1);
        count--;
    }

    int res = (ac << 4) | q;
    if (res & 0x80) res -= 256; // Signed result extension
    printf("---------------------------\nFinal Result: %d\n", res);
}

