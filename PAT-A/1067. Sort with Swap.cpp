#include<stdio.h>
#include<algorithm>
using namespace std;
int num[100005];
int main()
{
	int N;
	int tag=1;
	int step=0;
	int number=0;
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num[i]); 
		if(num[i]==i)
			number++;
	}
	while(number!=N)
	{
		if(num[0]==0)
		{
			for(int i=tag;i<N;i++)
			{
				if(num[i]!=i)
				{
					swap(num[0],num[i]);
					tag=i;
					break;
				}
			}
			number--;
			step++;
		}
		swap(num[num[0]],num[num[num[0]]]);
		step++;
		number++;
		if(num[0]==0)
			number++;	
	}
	printf("%d",step);
}