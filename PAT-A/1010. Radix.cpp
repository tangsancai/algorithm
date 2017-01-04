#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;
void Turn(char n1[],int N1[])
{
	int i=0;
	while(n1[i]!='\0')
	{
		if(n1[i]>='0'&&n1[i]<='9')
		{
			N1[i]=n1[i]-'0';
		}
		else
		{
			N1[i]=n1[i]-'a'+10;
		}
		i++;
	}	
}
int main()
{
	int N1[15];
	int N2[15];
	char n1[15];
	char n2[15];
	int tag;
	int radix;
	int num1=0;
	int num2;
	int flag;
	scanf("%s%s%d%d",n1,n2,&tag,&radix);
	Turn(n1,N1);
	Turn(n2,N2);
	int len1=strlen(n1);
	int len2=strlen(n2);
	if(tag==2)
	{
		swap(len1,len2);
		for(int i=0;i<15;i++)
		{
			swap(N1[i],N2[i]);
		}
	}
	for(int i=0;i<len1;i++)
	{
		num1=num1*radix+N1[i];
	}
	for(int i=0;i<=110;i++)
	{
		num2=0;
		flag=0;
		for(int j=0;j<len2;j++)
		{
			if(N2[j]>=i)
			{
				flag=1;
				break;
			}
			num2=num2*i+N2[j];
		}
		if(num2==num1&&!flag)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("Impossible");
	return 0;
}