#include<stdio.h>
#include<math.h>
#include<vector>
#define Maxn 100010
using namespace std;
vector<int> prime;
bool isPrime(int n)
{
	if(n==1)
	{
		return false;
	}
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
void FindPrime()
{
	for(int i=1;i<Maxn;i++)
	{
		if(isPrime(i))
		{
			prime.push_back(i);
		}
	}
}
typedef struct Node
{
	int p;
	int num;
};
Node factor[10];
int main()
{
	FindPrime();
	int n;
	int num=0;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1=1");
	}
	else
	{
		printf("%d=",n);
		int sqr=(int)sqrt(1.0*n);
		for(int i=0;i<prime.size();i++)
		{
			if(n%prime[i]==0)
			{
				factor[num].p=prime[i];
				factor[num].num=0;
				while(n%prime[i]==0)
				{
					factor[num].num++;
					n=n/prime[i];
				}
				num++;
			}
			if(n==1)
			{
				break;
			}
		}
		if(n!=1)
		{
			factor[num].p=n;
			factor[num++].num=1;
		}
		for(int i=0;i<num-1;i++)
		{
			printf("%d",factor[i].p);
			if(factor[i].num>1)
			{
				printf("^%d*",factor[i].num);
			}
			else
			{
				printf("*");
			}
		}
		printf("%d",factor[num-1].p);
		if(factor[num-1].num>1)
		{
			printf("^%d",factor[num-1].num);
		}
	}
}