#include<stdio.h> 
#include<algorithm>
using namespace std;
int data[100];
int data2Insert[100];
int data2Merge[100];
int main()
{
	int N;
	int i;
	int flag=-1;
	int temp;
	int flag2=-1;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}
	for(i=0;i<N;i++)
	{
		data2Insert[i]=data[i];
		data2Merge[i]=data[i];
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}
	for(i=2;i<=N;i++)
	{
		sort(data2Insert,data2Insert+i);
		if(flag!=0)
		{
			for(int j=0;j<N;j++)
			{
				if(data[j]!=data2Insert[j])
				{
					flag=1;
					break;
				}
				else
				{
					flag=0;
				}
			}
		}
		else
		{
			printf("Insertion Sort\n");
			for(int j=0;j<N-1;j++)
			{
				printf("%d ",data2Insert[j]);
			}
			printf("%d",data2Insert[N-1]);
			break;
		}	
	}
	if(flag!=0)
	{
		flag=-1;
		flag2=-1;
		printf("Merge Sort\n");
		for(i=1;i<N;i=2*i)
		{
			for(int j=0;(j+i)<=N;j=j+i)
			{
				sort(data2Merge+j,data2Merge+j+i);
			}
			temp=N;
			while(temp>i)
			{
				temp=temp-i;
			}
			sort(data2Merge+N-temp,data2Merge+N);
			if(flag!=0)
			{
				for(int j=0;j<N;j++)
				{
					if(data[j]!=data2Merge[j])
					{
						flag=1;
						break;
					}
					else
					{
						flag=0;
					}
				}
			}
			else
			{
				for(int j=0;j<N-1;j++)
				{
					printf("%d ",data2Merge[j]);
				}
				printf("%d",data2Merge[N-1]);
				flag2=0;
				break;
			}
		}
		if(flag2!=0)
		{
			sort(data2Merge,data2Merge+N);
			for(int j=0;j<N-1;j++)
			{
				printf("%d ",data2Merge[j]);
			}
			printf("%d",data2Merge[N-1]);
		}
	}
}