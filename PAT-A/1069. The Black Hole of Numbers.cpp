#include<stdio.h>
#include<algorithm>
using namespace std;
void ConIntToInts(int number,int num[])
{
	num[3]=number/1000;
	number=number-1000*(number/1000);
	num[2]=number/100;
	number=number-100*(number/100);
	num[1]=number/10;
	number=number-10*(number/10);
	num[0]=number;
}
int ConIntsToInt(int num[])
{
	return num[0]+10*num[1]+100*num[2]+1000*num[3];
}
bool cmpBig(int a,int b)
{
	return (a<b)>0;
}
bool cmpSmall(int a,int b)
{
	return (a>b)>0;
}
int main()
{
	int number;
	int num[4];
	int big;
	int small;
	int flag=0;
	scanf("%d",&number);
	while(flag==0)
	{
		ConIntToInts(number,num);
		sort(num,num+4,cmpBig);
		big=ConIntsToInt(num);
		sort(num,num+4,cmpSmall);
		small=ConIntsToInt(num);
		number=big-small;
		if(number==0)
		{
			printf("%04d - %04d = 0000\n",big,small);
			break;
		}
		if(number==6174)
		{
			flag=1;
		}
		printf("%04d - %04d = %04d\n",big,small,number);
	}
}