//系数为0不输出 
#include<stdio.h>
double line1[1005]={0.0};
double line2[1005]={0.0};
int number[1005]={0};
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
		number[num]=1;
		snum++;
	}
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%lf",&num,&data);
		line2[num]=data; 
		if(number[num]!=1)
		{
			snum++;
			number[num]=1;
		}
		else
		{
			if((line1[num]+line2[num])==0)
			{
				snum--;
				number[num]=0;
			}
		}
	}
	printf("%d",snum);
	for(int i=1000;i>=0;i--)
	{
		line2[i]=line2[i]+line1[i];
		if(number[i]==1)
		{
			printf(" ");
			printf("%d %.1f",i,line2[i]);
		}
	}
}