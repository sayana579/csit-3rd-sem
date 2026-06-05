#include<stdio.h>
#include<iostream>
int gcd(int a, int b)
{
	if (b==0)
	{
		return a;
	}
	else
	{
		return (gcd(b,a%b));
	}
}
int main()
{
	system("color f0");
	int a,b;
	printf("Enter two integers: ");
	scanf("%d %d",&a,&b);
	int g=gcd(a,b);
	printf ("GCD of %d and %d is %d: ",a,b,g);
	return 0;
}
