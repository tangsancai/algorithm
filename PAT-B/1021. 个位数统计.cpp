#include<stdio.h>
#include<string.h>
int main()
{
	int number[10];
	memset(number,0,sizeof(number));
	char num[1005];
	scanf("%s",num);
	int i=-1;
	while(num[++i]!='\0')
	{
		number[num[i]-'0']++;	
	}
	for(int j=0;j<10;j++)
	{
		if(number[j]!=0)
		{
			printf("%d:%d\n",j,number[j]);
		}
	}	
}