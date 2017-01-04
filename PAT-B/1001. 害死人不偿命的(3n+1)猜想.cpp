#include<stdio.h>
int step=0;
int Callatz(int n)
{
	if(n==1)
	{
		return step;
	}
	else
	{
		if(n%2==0)
		{
			step++;
			Callatz(n/2);
		}
		else
		{
			step++;
			Callatz((3*n+1)/2);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",Callatz(n));
}