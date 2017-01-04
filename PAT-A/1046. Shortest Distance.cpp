#include<stdio.h>
#include<algorithm>
using namespace std;
int dis[100005];
int A[100005];
int main()
{
	int M;
	int N;
	int sum=0;
	int posa;
	int posb;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		sum=sum+A[i];
		dis[i]=sum;
	}
	scanf("%d",&M);
	while(M--)
	{
		scanf("%d%d",&posa,&posb);
		if(posa>posb)
		{
			swap(posa,posb);
		}
		int temp=dis[posb-1]-dis[posa-1];
		printf("%d\n",min(temp,sum-temp));
	}
		
} 