#include<stdio.h>
#include<string.h>
int Num1[10]={0};
int Num2[10]={0};
int data[25];
int data2[25];
int main()
{
	char str1[25];
	scanf("%s",str1);
	for(int i=0;i<strlen(str1);i++)
	{
		data[strlen(str1)-i-1]=str1[i]-'0';
		Num1[str1[i]-'0']++;
	}
	int carry=0;
	for(int i=0;i<strlen(str1);i++)
	{
		data2[i]=(carry+data[i]*2)%10;
		carry=(carry+data[i]*2)/10;
		Num2[data2[i]]++;	
	}
	if(carry!=0)
	{
		printf("No\n%d",carry);
		for(int i=strlen(str1)-1;i>=0;i--)
		{
			printf("%d",data2[i]);	
		}
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			if(Num1[i]!=Num2[i])
			{
				printf("No\n");
				for(int i=strlen(str1)-1;i>=0;i--)
				{
					printf("%d",data2[i]);	
				}
				return 0;
			}
		}
		printf("Yes\n");
		for(int i=strlen(str1)-1;i>=0;i--)
		{
			printf("%d",data2[i]);	
		}
	}
}
