#include <stdio.h>
#include <string.h>

int main() {
    char binary[32], ones[32], twos[32];
    int i, carry = 1;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    // 1's Complement
    for (i = 0; binary[i] != '\0'; i++) {
        if (binary[i] == '0')
            ones[i] = '1';
        else
            ones[i] = '0';
    }
    ones[i] = '\0';

    // 2's Complement
    for (i = strlen(ones) - 1; i >= 0; i--) {
        if (ones[i] == '1' && carry == 1) {
            twos[i] = '0';
        } else if (ones[i] == '0' && carry == 1) {
            twos[i] = '1';
            carry = 0;
        } else {
            twos[i] = ones[i];
        }
    }
    twos[strlen(ones)] = '\0';

    printf("1's Complement = %s\n", ones);
    printf("2's Complement = %s\n", twos);

    return 0;
}

