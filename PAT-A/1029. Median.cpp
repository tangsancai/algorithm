#include<stdio.h>
long long Num1[1000005];
long long Num2[1000005];
int main()
{
	int N;
	int M;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&Num1[i]);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		scanf("%lld",&Num2[i]);
	}
	int i=0;
	int j=0;
	int num=0;
	while(num<(N+M-1)/2)
	{
		if(i<N&&j<M)
		{
			if(Num1[i]>Num2[j])
			{
				j++;
				num++;
			}
			else
			{
				i++;
				num++;
			}
		}
		else if(i==N&&j<M)
		{
			j++;
			num++;
		}
		else if(i<N&&j==M)
		{
			i++;
			num++;
		}
	}
	if(i<N&&j<M)
	{
		if(Num1[i]<Num2[j])
		{
			printf("%lld",Num1[i]);
		}
		else
		{
			printf("%lld",Num2[j]);
		}
	}
	else if(i==N)
	{
		printf("%lld",Num2[j]);
	}
	else if(j==M)
	{
		printf("%lld",Num1[i]);
	}
}