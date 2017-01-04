#include<stdio.h>
char Number[15][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void ReadMethod(int num)
{
	int flag=0;
	int data[4];
	for(int i=0;i<4;i++)
	{
		data[i]=num%10;
		num=num/10;	
	}
	if(data[3]!=0)
	{
		printf("%s Qian",Number[data[3]]);
	}
	if(data[2]!=0)
	{
		if(data[3]!=0)
		{
			printf(" ");
		}
		printf("%s Bai",Number[data[2]]);
	}
	else if(data[3]!=0&&data[2]==0&&(data[1]!=0||data[0]!=0))
	{
		flag=1;
		printf(" ling");
	}
	if(data[1]!=0)
	{
		if(data[2]!=0||data[3]!=0)
		{
			printf(" ");
		}
		printf("%s Shi",Number[data[1]]);
	}
	else if((data[3]!=0||data[2]!=0)&&flag==0&&data[0]!=0&&data[1]==0)
	{
		printf(" ling");
	}
	if(data[0]!=0)
	{
		if(data[3]!=0||data[2]!=0||data[1]!=0)
		{
			printf(" ");
		}
		printf("%s",Number[data[0]]);
	}
}
int main()
{
	int num;
	int flag1=0;
	int flag2=0;
	scanf("%d",&num);
	if(num==0)
	{
		printf("ling");
	}
	else if(num<0)
	{
		num=-num;
		printf("Fu ");
	}
	if(num/100000000)
	{
		flag1=1;
		printf("%s Yi",Number[num/100000000]);
		num=num%100000000;
		if(num)
		{
			printf(" ");
		}
	}
	if(num/10000)
	{
		flag2=1;
		ReadMethod(num/10000);
		printf(" Wan");
		num=num%10000;
		if(num)
		{
			printf(" ");
		}
	}
	else if(flag1==1&&num!=0)
	{
		printf("ling ");
	}
	if(flag1==0&&flag2==1&&num<1000)
	{
		printf("ling ");
	}
	if(num)
	{
		ReadMethod(num);
	}
}