#include<stdio.h>
#include<string.h>
int main()
{
	char data[1005];
	int B;
	char Q[1005];
	scanf("%s %d",data,&B);
	int i1=-1;
	int i2=0;
	int temp=0;
	memset(Q,'\0',sizeof(Q));
	while(data[++i1]!='\0')
	{
		temp=temp*10+(data[i1]-'0');
		if(i1==0&&temp<B)
		{
		}
		else
		{
			Q[i2++]=(temp/B)+'0';
			temp=temp%B;
		}	
	}
	if(strlen(data)==1&&(data[0]-'0')<B)
	{
		printf("0 %d",temp);
	}
	else
	{
		printf("%s %d",Q,temp);
	}
} 