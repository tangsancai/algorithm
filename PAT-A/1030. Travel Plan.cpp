#include<stdio.h>
#include<limits.h>
#define MAXV 505
using namespace std;
typedef struct GMap
{
	int dis;
	int cost;
};
GMap G[MAXV][MAXV];
int pre[MAXV];
bool vis[MAXV]={false};

int cost[MAXV]={0};
int dis[MAXV];
void Dijsktra(int S,int N)
{
	dis[S]=0;
	for(int i=0;i<N;i++)
	{
		int u=-1;
		int Min=INT_MAX;
		for(int j=0;j<N;j++)
		{
			if(vis[j]==false&&dis[j]<Min)
			{
				u=j;
				Min=dis[j];
			}
		}
		if(u==-1)
		{
			return;
		}
		vis[u]=true;
		for(int v=0;v<N;v++)
		{
			if(vis[v]==false&&G[u][v].dis!=INT_MAX)
			{
				if(dis[v]>dis[u]+G[u][v].dis)
				{
					dis[v]=dis[u]+G[u][v].dis;
					cost[v]=cost[u]+G[u][v].cost;
					pre[v]=u;
				}
				else if(dis[v]==dis[u]+G[u][v].dis)
				{
					if(cost[v]>cost[u]+G[u][v].cost)
					{
						cost[v]=cost[u]+G[u][v].cost;
						pre[v]=u;
					}
				}
			}
		}
	}
}
void DFS(int s,int v)
{
	if(v==s)
	{
		printf("%d ",v);
		return;
	}
	DFS(s,pre[v]);
	printf("%d ",v);
}
int main()
{
	int N;
	int M;
	int S;
	int D;
	scanf("%d%d%d%d",&N,&M,&S,&D);
	for(int i=0;i<MAXV;i++)
	{
		dis[i]=INT_MAX;
		for(int j=0;j<MAXV;j++)
		{
			G[i][j].dis=INT_MAX;
		}
	}
	for(int i=0;i<M;i++)
	{
		int c1;
		int c2;
		int dis;
		int cost;
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		G[c1][c2].dis=dis;
		G[c1][c2].cost=cost;
		G[c2][c1].dis=dis;
		G[c2][c1].cost=cost;
	}
	for(int i=0;i<MAXV;i++)
	{
		pre[i]=i;
	}
	Dijsktra(S,N);
	DFS(S,D);
	printf("%d %d",dis[D],cost[D]);
}