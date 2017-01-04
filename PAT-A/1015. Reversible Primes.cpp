#include<stdio.h>
#include<math.h>
using namespace std;
bool IsPrime(int n)
{
	if(n==1||n==0)
	{
		return false;
	}
	for(int i=2;i<=(int)sqrt(n+0.0);i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int Reversible(int n,int radix)
{
	int data[200];
	int num=-1;
	int sum=0;
	while(n)
	{
		data[++num]=n%radix;
		n=n/radix;
	}
	for(int i=0;i<=num;i++)
	{
		sum=sum*radix+data[i];
	}
	return sum;
}
int main()
{
	int N;
	int radix;
	while(1)
	{
		scanf("%d",&N);
		if(N<0)
		{
			return 0;
		}
		scanf("%d",&radix);
		if(IsPrime(N)&&IsPrime(Reversible(N,radix)))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
}