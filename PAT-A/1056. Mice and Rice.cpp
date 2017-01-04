#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct dataInfo
{ 
	int id;
	int weight;
	int rank;
};
dataInfo temp[1005];
dataInfo data[1005];
queue<dataInfo> q;
queue<dataInfo> qtemp;
bool cmp(dataInfo a,dataInfo b)
{
	return a.weight>b.weight;
}
int main()
{
	int N;
	int K;
	int rank;
	int sum;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&data[i].weight);
		data[i].id=i;
	}
	for(int i=0;i<N;i++)
	{
		int id;
		scanf("%d",&id);
		q.push(data[id]);
	}
	sum=N;
	while(!q.empty())
	{
		while(!q.empty())
		{
			int num=0;
			for(int i=0;i<K;i++)
			{
				if(!q.empty())
				{
					temp[num++]=q.front();
					q.pop();
				}
				else
				{
					break;
				}	
			}
			if(num!=0&&sum!=1)
			{
				sort(temp,temp+num,cmp);
				qtemp.push(temp[0]);
			}
			else if(num==1&&sum==1)
			{
				data[temp[0].id].rank=1;
				break;	
			}
			if(sum%K!=0)
			{
				rank=sum/K+1;
			}
			else
			{
				rank=sum/K;
			}
			for(int i=1;i<num;i++)
			{
				data[temp[i].id].rank=rank+1;
			}
		}
		q=qtemp;
		sum=qtemp.size();
		queue<dataInfo> q2;
		qtemp=q2;
	}
	for(int i=0;i<N-1;i++)
	{
		printf("%d ",data[i].rank);
	}
	printf("%d",data[N-1].rank);
}