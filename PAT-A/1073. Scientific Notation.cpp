#include<stdio.h>
#include<string.h>
using namespace std;
char data[100000];
char A[100000];
int main()
{
	int B=0;
	int signB;
	int num=0;
	int anum=0;
	scanf("%s",data);
	memset(A,'\0',sizeof(A));
	if(data[num++]=='-')
	{
		printf("-");
	}
	while(data[num]!='E')
	{
		if(data[num]>='0'&&data[num]<='9')
		{
			A[anum++]=data[num];
		}
		num++;
	}
	if(data[++num]=='+')
	{
		num++;
		signB=1;
	}
	else
	{
		num++;
		signB=-1;
	}
	while(data[num]!='\0')
	{
		B=B*10+(data[num]-'0');
		num++;
	}
	if(signB==-1)
	{
		B=-B;
	}
	B=B+1;
	if(B>0)
	{
		if(B<anum)
		{
			for(int i=0;i<B;i++)
			{
				printf("%c",A[i]);
			}
			printf(".");
			for(int i=B;i<anum;i++)
			{
				printf("%c",A[i]);
			}
		}
		else if(B>anum)
		{
			printf("%s",A);
			for(int i=anum;i<B;i++)
			{
				printf("0");
			}
		}
		else
		{
			printf("%s",A);
		}
	}
	else if(B<0)
	{
		printf("0.");
		for(int i=0;i<-B;i++)
		{
			printf("0");
		}
		printf("%s",A);
	}
	else
	{
		printf("0.%s",A);
	}
}