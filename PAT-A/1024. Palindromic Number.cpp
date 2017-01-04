#include<stdio.h>
#include<string.h>
int Num1[400];
int Num2[400];
int Num3[400];
bool IsPalindromic(int len)
{
	for(int i=0;i<len/2;i++)
	{
		if(Num1[i]!=Num1[len-1-i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	char str1[15];
	int maxstep;
	scanf("%s%d",str1,&maxstep);
	int len=strlen(str1);
	for(int i=0;i<len;i++)
	{
		Num1[len-i-1]=str1[i]-'0';
	}
	for(int step=0;step<maxstep;step++)
	{
		if(IsPalindromic(len))
		{
			for(int i=0;i<len;i++)
			{
				printf("%d",Num1[len-i-1]);
			}
			printf("\n%d",step);
			return 0;
		}
		else
		{
			int carry=0;
			for(int i=0;i<len;i++)
			{
				Num2[i]=Num1[len-i-1];
				Num3[i]=Num1[i];
			}
			for(int i=0;i<len;i++)
			{
				Num1[i]=(Num2[i]+Num3[i]+carry)%10;
				carry=(Num2[i]+Num3[i]+carry)/10;
			}
			if(carry!=0)
			{
				Num1[len]=carry;
				len++;
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		printf("%d",Num1[len-i-1]);
	}
	printf("\n%d",maxstep);
}