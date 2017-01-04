#include<stdio.h>
#include<math.h>
int main()
{
	int M;
	int N;
	scanf("%d%d",&M,&N);
	int i=0;
	int Num=2;
	int flag=0;
	int huan=0;
	while(i<=N)
	{
		for(int j=2;j<=(int)sqrt((double)Num);j++)
		{
			if(Num%j==0)
			{
				flag=1;
				break;
			}	
		}
		if(flag==1)
		{
			flag=0;
		}
		else
		{
			i++;
			
			if(i>=M&&i<N)
			{
				huan++;
				printf("%d",Num);
				if(huan==10)
				{
					printf("\n");
					huan=0;
				}
				else
				{
					printf(" ");
				}	
			}
			else if(i>=M&&i==N)
			{
				printf("%d\n",Num);
			}	
		}
		Num++;
	}
}