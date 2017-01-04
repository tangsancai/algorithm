#include<stdio.h>
#include<string.h>
int main()
{
	int a;
	int b;
	int num=0;
	int data[20];
	scanf("%d%d",&a,&b);
	a=a+b;
	if(a<0)
	{
		a=-a;
		printf("-");
	}
	while(a/10)
	{
		data[num++]=a%10;
		a=a/10;
	}
	data[num++]=a;
	for(int i=num-1;i>=0;i--)
	{
		printf("%d",data[i]);
		if(i%3==0&&i!=0)
		{
			printf(",");
		}
	}
}