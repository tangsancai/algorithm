#include<stdio.h>
int data[100];
int main()
{
	int N;
	int b;
	int Num=0;
	int flag=0;
	scanf("%d%d",&N,&b);
	while(N)
	{
		data[Num]=N%b;
		Num++;
		N=N/b;	
	}
	for(int i=0;i<Num/2;i++)
	{
		if(data[i]!=data[Num-1-i])	
		{
			flag=1;
		}
	}
	if(!flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	for(int i=Num-1;i>0;i--)
	{
		printf("%d ",data[i]);
	}
	printf("%d",data[0]);
} 