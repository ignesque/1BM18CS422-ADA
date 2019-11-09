#include<stdio.h>
#include<conio.h>
void main()
{
int max=0,i,j=0,n,arr[100],flag=1;
clrscr();
printf("Enter the value of N:");
scanf("%d",&n);
printf("Enter the values in array\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
do
{
if(arr[j]>max)
max=arr[j];
j++;
if(j==n)
flag=0;
}
while(flag);
printf("\nMaximum of the %d integers is %d",n,max);
getch();
}


