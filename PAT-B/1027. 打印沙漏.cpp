#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	int sum=1;
	int i=3;
	int max1;
	int left;
	char a;
	scanf("%d %c",&n,&a);
	while(1)
	{
		left=sum;
		sum=sum+i*2;
		if(sum>n)
		{
			break;
		}
		else
		{
			i=i+2;
		}
	}
	max1=i-2;
	left=n-left;
	for(int j=max1;j>1;j=j-2)
	{
		for(int k=0;k<(max1-j)/2;k++)
		{
			printf(" ");
		}
		for(int k=0;k<j;k++)
		{
			printf("%c",a);
		}
		printf("\n");
	}
	for(int j=1;j<=max1;j=j+2)
	{
		for(int k=0;k<(max1-j)/2;k++)
		{
			printf(" ");
		}
		for(int k=0;k<j;k++)
		{
			printf("%c",a);
		}	
		printf("\n");
	}
	printf("%d",left);
}