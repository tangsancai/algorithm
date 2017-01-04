#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct Temp
{
	int i;
	int j;
	int cha;
};
Temp temp[100000];
int diamonds[100005];
int main()
{
	int N;
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&diamonds[i]);
	}
	int i=0;
	int j=0;
	int sum=diamonds[0];
	int flag=0;
	while(1)
	{
		if(j<N-1)
		{
			if(sum==M)
			{
				flag=1;
				printf("%d-%d\n",i+1,j+1);
				j++;
				sum=sum+diamonds[j];
			}
			else if(sum<M)
			{
				j++;
				sum=sum+diamonds[j];
			}
			else
			{
				sum=sum-diamonds[i];
				i++;
			}
		}
		else if(j==N-1&&i<N)
		{
			if(sum==M)
			{
				flag=1;
				printf("%d-%d\n",i+1,j+1);
				break;
			}
			else if(sum<M)
			{
				break;
			}
			else
			{
				sum=sum-diamonds[i];
				i++;
			}
		}
		else if(j==N-1&&i==N)
		{
			break;
		}
	}
	if(flag==1)
	{
		return 0;
	}
	else
	{
		int mmin=10000;
		i=0;
		j=0;
		int num=0;
		sum=diamonds[0];
		while(1)
		{
			if(j<N-1)
			{
		 		if(sum<M)
				{
					j++;
					sum=sum+diamonds[j];
				}
				else
				{
					if(sum-M<mmin)
					{
						mmin=sum-M;
						temp[0].i=i;
						temp[0].j=j;
						temp[0].cha=mmin;
						num=1;
					}
					else if(sum-M==mmin)
					{
						num++;
						temp[num-1].i=i;
						temp[num-1].j=j;
						temp[num-1].cha=mmin;
					}
					sum=sum-diamonds[i];
					i++;
				}
			}
			else if(j==N-1&&i<N)
			{
				 if(sum<M)
			     {
					break;
   		         }
				else
				{
					if(sum-M<mmin)
					{
						mmin=sum-M;
						temp[0].i=i;
						temp[0].j=j;
						temp[0].cha=mmin;
						num=1;
					}
					else if(sum-M==mmin)
					{
						num++;
						temp[num-1].i=i;
						temp[num-1].j=j;
						temp[num-1].cha=mmin;
					}
					sum=sum-diamonds[i];
					i++;
				}
			}
			else if(j==N-1&&i==N)
			{
				break;
			}
		}
		for(int k=0;k<num;k++)
		{
			printf("%d-%d\n",temp[k].i+1,temp[k].j+1);
		}
	}
}