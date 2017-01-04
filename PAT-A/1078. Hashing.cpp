#include<stdio.h>
#include<math.h>
bool pos[10005]={0};
bool IsPrime(int n)
{
	if(n==1)
	{
		return false;
	}
	for(int i=2;i<=(int)sqrt(n+0.0);i++)
	{
		if(n%i==0)
		{
			return false;
		}	
	}
	return true;
}
int getMsize(int n)
{
	while(!IsPrime(n))
	{
		n++;
	}
	return n;
}
int main()
{
	int Msize;
	int N;
	int data;
	int temp;
	scanf("%d%d",&Msize,&N);
	Msize=getMsize(Msize);
	if(N>0)
	{
		scanf("%d",&data);
		temp=data%Msize;
		pos[temp]=true;
		printf("%d",temp);	
	}	
	for(int i=1;i<N;i++)
	{
		scanf("%d",&data);
		temp=data%Msize;
		if(!pos[temp])
		{
			pos[temp]=true;
			printf(" %d",temp);
		}
		else
		{
			int j1=0;
			while(1)
			{
				j1++;
				if(j1<Msize)
				{
					if(!pos[(temp+j1*j1)%Msize])
					{
						pos[(temp+j1*j1)%Msize]=true;
						printf(" %d",(temp+j1*j1)%Msize);
						break;
					}
				}
				else
				{
					printf(" -");
					break;
				}
			}	
		}
	}
}