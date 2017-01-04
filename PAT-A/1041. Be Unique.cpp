#include<stdio.h>
int number[10005]={0};
int num[100005];
int main()
{
	int N;
	int flag=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
		number[num[i]]++;	
	}
	for(int i=0;i<N;i++)
	{
		if(number[num[i]]==1)
		{
			flag=1;
			printf("%d",num[i]);
			break;
		}
	}
	if(!flag)
	{
		printf("None");
	}
}