#include<stdio.h>
#include<string.h>

void HelloWorld(char str[])
{
	int len=strlen(str);
	int n1,n2,n3;
	n1=n2=n3=0;
	if(len%3==0)
	{
		n1=n3=len/3;
	}
	else
	{
		n1=n3=len/3+1;
	}
	n2=len+2-n1-n3;
	for(int i=0;i<n1-1;i++)
	{
		printf("%c",str[i]);
		for(int j=0;j<n2-2;j++)
		{
			printf(" ");
		}
		printf("%c\n",str[len-i-1]);
	}
	for(int i=n1-1;i<len-n3+1;i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}

int main()
{
	char str[85];
	while(scanf("%s",str)!=EOF)
	{
		HelloWorld(str);
	}
}