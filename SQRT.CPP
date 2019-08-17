#include<iostream.h>
#include<conio.h>

long int floorsqrt(int x)
{
    if (x == 0 || x == 1)
       return x;

    long int start = 1, end = x, ans;
    while (start <= end)
    {
	long int mid = (start + end) / 2;
	if (mid*mid == x)
	    return mid;
	if (mid*mid < x)
	{
	    start = mid + 1;
	    ans = mid;
	}
	else
	    end = mid-1;
    }
    return ans;
}
int main()
{
long int x;
clrscr();
cout<<"Enter a number to find its square root:";
cin>>x;
cout<<"Square root of "<<x<<" is "<<floorsqrt(x);
getch();
return 0;
}
