#include<stdio.h>
double line1[1005]={0.0};
double line2[1005]={0.0};
double sum[2005]={0.0};
int sumnumber[2005]={0};
int main()
{
	int K;
	int num;
	double data;
	int snum=0;
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%lf",&num,&data);
		line1[num]=data;
	}
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%lf",&num,&data);
		line2[num]=data;
		for(int i=1000;i>=0;i--)
		{
			if((line2[num]*line1[i])!=((double)0))
			{
				sum[num+i]=sum[num+i]+line2[num]*line1[i];
				if(sum[num+i]!=0)
				{
					if(sumnumber[num+i]!=1)
					{
						snum++;
						sumnumber[num+i]=1;
					}
				}
				else
				{
					sumnumber[num+i]=0;
					snum--;
				}	
			}
		}
	}
	printf("%d",snum);
	for(int i=2000;i>=0;i--)
	{
		if(sumnumber[i]==1)
		{
			printf(" ");
			printf("%d %.1f",i,sum[i]);
		}
	}
	
} 