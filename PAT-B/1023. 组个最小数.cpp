#include<stdio.h>
#include<string.h>
int main()
{
	int num[10];
	int number;
	memset(num,0,sizeof(num));
	int i=0;
	while(i<10)
	{
		scanf("%d",&number);
		num[i]=number;
		i++;
	}
	for(i=1;i<10;i++)
	{
		if(num[i]!=0)
		{
			printf("%d",i);
			num[i]--;
			break;
		}
	}
	int j=0;
	for(i=0;i<10;i++)
	{
		while(num[j]!=0)
		{
			printf("%d",i);
			num[j]--;
		}
		j++;
	}
} 