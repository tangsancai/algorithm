#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
bool vis[505]={false};
int G[505][505];
int teamNum[505];

int num[505]={0};
int theMax[505]={0};
int dis[505];
void Dijkstra(int C1,int N)
{
	fill(dis,dis+N,INT_MAX);
	dis[C1]=0;
	num[C1]=1;
	theMax[C1]=teamNum[C1];
	for(int j=0;j<N;j++)
	{
		int u=-1;
		int Min=INT_MAX;
		for(int i=0;i<N;i++)
		{
			if(vis[i]==false&&dis[i]<Min)
			{
				u=i;
				Min=dis[i];
			}
		}
		if(u==-1)
		{
			return;
		}
		vis[u]=true;
		for(int i=0;i<N;i++)
		{
			if(G[u][i]!=INT_MAX&&vis[i]==false)
			{
				if(dis[u]+G[u][i]<dis[i])
				{
					dis[i]=dis[u]+G[u][i];
					theMax[i]=theMax[u]+teamNum[i];
					num[i]=num[u];
				}
				else if((dis[u]+G[u][i])==dis[i])
				{
					if(theMax[u]+teamNum[i]>theMax[i])
					{
						theMax[i]=theMax[u]+teamNum[i];
					}
					num[i]=num[i]+num[u];
				}
			}
		}
	}
}
int main()
{
	int N;
	int M;
	int C1;
	int C2;
	fill(G[0],G[0]+505*505,INT_MAX);
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&teamNum[i]);
	}
	for(int i=0;i<M;i++)
	{
		int c1;
		int c2;
		int l;
		scanf("%d%d%d",&c1,&c2,&l);
		G[c1][c2]=l;
		G[c2][c1]=l;
	}
	Dijkstra(C1,N);
	printf("%d %d",num[C2],theMax[C2]);
	return 0;
}