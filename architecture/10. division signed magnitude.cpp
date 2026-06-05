#include <stdio.h>
#include <string.h>

int main() {
    char A[20], B[20], res[20];
    int signA, signB, signR, magA=0, magB=0, magR=0, i, n1, n2;

    printf("Enter dividend (signed magnitude): ");
    scanf("%s", &A);
    printf("Enter divisor (signed magnitude): ");
    scanf("%s", &B);

    n1 = strlen(A); n2 = strlen(B);
    signA = A[0]-'0'; signB = B[0]-'0';
    signR = signA ^ signB;

    for(i=1;i<n1;i++) magA = magA*2 + (A[i]-'0');
    for(i=1;i<n2;i++) magB = magB*2 + (B[i]-'0');

    if(magB==0){ printf("Error: Division by zero\n"); return 0; }

    magR = magA / magB;

    for(i=n1-1;i>=1;i--){ res[i]=(magR%2)+'0'; magR/=2; }
    res[0] = signR+'0'; res[n1]='\0';

    printf("Result (Signed Magnitude) = %s\n", res);
    return 0;
}

