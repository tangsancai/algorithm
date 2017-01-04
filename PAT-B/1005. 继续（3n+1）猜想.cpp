#include<stdio.h>
int data[105];
int data2[105];
int Callatz(int n)
{
	if(n==1)
	{
		data[n]=1;
		return 0;
	}
	else
	{
		if(n%2==0)
		{
			if(n/2<101)
			{
				data[n/2]=1;
			}
			Callatz(n/2);
		}
		else
		{
			if((3*n+1)/2<101)
			{
				data[(3*n+1)/2]=1;
			}
			Callatz((3*n+1)/2);
		}
	}
}
int main()
{
	int N;
	int m;
	for(int i=0;i<105;i++)
	{
		data[i]=-1;
	}
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&m);
		if(data[m]==-1)
		{
			data[m]=0;
		}
		Callatz(m);
	}
	int Num=0;
	for(int i=0;i<105;i++)
	{
		if(data[i]==0)
		{
			data2[Num++]=i;
		}
	}
	for(int i=Num-1;i>0;i--)
	{
		printf("%d ",data2[i]);
	}
	printf("%d",data2[0]);
}