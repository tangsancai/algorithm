#include<stdio.h>
#include <iostream>  
using namespace std; 
typedef struct Node
{
	int xi;
	int zhi;
};
Node node[2010];
int main()
{
	int xi;
	int zhi;
	int num=0;
	while(scanf("%d%d",&xi,&zhi)!=EOF)//��G++���е�ͨ����cfree���в�ͨ 
	//while(cin >> xi >> zhi)//��cfree��G++�ж��е�ͨ 
	//while(scanf("%d%d",&xi,&zhi))//��cfree���е�ͨ����G++���в�ͨ 
	{
		node[num].xi=xi;
		node[num].zhi=zhi;
		num++;
	}
	for(int j=0;j<num;j++)
	{
		node[j].xi=node[j].xi*node[j].zhi;
		node[j].zhi=node[j].zhi-1;
	}
	for(int j=0;j<num;j++)
	{
		if(node[j].xi==0)
		{
			for(int k=j;k<num-1;k++)
			{
				node[k].xi=node[k+1].xi;
				node[k].zhi=node[k+1].zhi;
			}
			num--;
		}
	}
	if(num==0)
	{
		printf("0 0");
	}
	else
	{
		for(int j=0;j<num-1;j++)
		{
			printf("%d %d ",node[j].xi,node[j].zhi);
		}
		printf("%d %d",node[num-1].xi,node[num-1].zhi);
	}
}