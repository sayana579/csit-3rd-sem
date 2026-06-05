
#include<stdio.h>
#include<iostream>
 void print (int a[],int n)
 {
 	for (int i=0; i<n; i++)
 	{
 	 printf ("%d ",a[i]);	
	}
	printf ("\n");
 }
 int ssearch (int a[],int n,int target)
 {
 	for (int i=0;i<n;i++)
 	{
 		if (a[i]==target)
 		return i;
	 }
	 return -1;
 }
 int main()
 {
 	system ("color f0");
 	int a[]={35,7,40,10,52};
 	int target;
 	int n=sizeof(a)/sizeof(a[0]);
 	printf ("Given Array: ");
 	print(a,n);
 	printf ("\n");
 	printf ("Enter the target element:");
 	scanf ("%d",&target);
 	printf ("\n");
 	int t=ssearch(a,n,target);
 	if (t==-1)
 	printf ("Target not found");
 	else 
 	printf ("The target element is in index %d",t);
 	return 0;
 }

