#include<stdio.h>

int main()
{
	int sum;
	scanf("%d",&sum);
	if(sum/100!=0)
	{
		for(int i=0;i<sum/100;i++)
		{
			printf("B");
		}
		sum=sum-100*(sum/100);
		for(int i=0;i<sum/10;i++)
		{
			printf("S");
		}
		sum=sum-10*(sum/10);
		for(int i=1;i<=sum;i++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
	else if(sum/100==0&&sum/10!=0)
	{
		for(int i=0;i<sum/10;i++)
		{
			printf("S");
		}
		sum=sum-10*(sum/10);
		for(int i=1;i<=sum;i++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
	else if(sum/100==0&&sum/10==0&&sum!=0)
	{
		for(int i=1;i<=sum;i++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
} 