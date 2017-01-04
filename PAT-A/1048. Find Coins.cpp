#include<stdio.h>
#include<algorithm>
using namespace std;
int coin[100005];
int main()
{
	int N;
	int payment;
	scanf("%d%d",&N,&payment);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+N);
	int i=0;
	int j=N-1;
	while((coin[i]+coin[j])!=payment&&i<j)
	{
		if((coin[i]+coin[j])<payment)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	if(i==j)
	{
		printf("No Solution");
	}
	else if((coin[i]+coin[j])==payment)
	{
		printf("%d %d",coin[i],coin[j]);
	}
}
