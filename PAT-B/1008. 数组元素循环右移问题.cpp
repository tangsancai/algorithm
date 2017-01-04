#include<stdio.h>

int main()
{
	int data[100];	
	int N;
	int M;
	int num=0;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}
	while(M>N)
	{
		M=M-N;
	}
	for(int i=N-M;i<N;i++)
	{
		printf("%d",data[i]);
		num++;
		if(num!=N)
		{
			printf(" ");
		}	
	}
	for(int i=0;i<N-M;i++)
	{
		printf("%d",data[i]);
		num++;
		if(num!=N)
		{
			printf(" ");
		}
	}
} 