#include<stdio.h>
#include<string.h>
int main()
{
	int A1=0;
	int A2=0;
	int A3=0;
	float A4=0.0;
	int A5=-1;
	int N;
	int num;
	int flag=0;
	int A4num=0;
	int A2num=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num);
		switch(num%5)
		{
			case 0:
				if(num%2==0)
				{
					A1=A1+num;
				}
				break;
			case 1:
				A2num++;
				if(flag==0)
				{
					A2=A2+num;
					flag=1;
				}
				else
				{
					A2=A2-num;
					flag=0;
				}
				break;
			case 2:
				A3++;
				break;
			case 3:
				A4=A4+(float)num;
				A4num++;
				break;
			case 4:
				if(num>A5)
				{
					A5=num;
				}
				break;
		}
	}
	if(A1==0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ",A1);
	}
	if(A2num==0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ",A2);
	}
	if(A3==0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ",A3);
	}
	if(A4num==0)
	{
		printf("N ");
	}
	else
	{
		printf("%.1f ",A4/((float)A4num));
	}
	if(A5==-1)
	{
		printf("N");
	}
	else
	{
		printf("%d",A5);
	}
}