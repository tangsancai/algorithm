#include<stdio.h>
#include<math.h>
int main() 
{
	int n;
	int flag;
	int d=1;
	int num=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		flag=0;
		for(int j=2;j<=(int)sqrt(double(i));j++)//数的最大约数为为其开方 
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			if((i-d)==2)
			{
				num++;
			}
			d=i;	
		}
	}
	printf("%d\n",num);
}