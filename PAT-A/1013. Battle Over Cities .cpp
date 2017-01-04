#include<stdio.h>
#include<vector>
using namespace std;
vector<int> eage[1005];
bool vis[1005];
int check[1005];
void DFS(int u,int n)
{
	vis[u]=true;	
	for(int i=0;i<eage[u].size();i++)
	{
		int v=eage[u][i];
		if(vis[v]==false&&v!=n)
		{
			DFS(v,n);
		}	
	}
}
int main()
{
	int N;
	int M;
	int K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int a;
		int b;
		scanf("%d%d",&a,&b);
		eage[a].push_back(b);
		eage[b].push_back(a);
	}
	for(int i=0;i<K;i++)
	{
		scanf("%d",&check[i]);
	}
	for(int i=0;i<K;i++)
	{
		int num=0;
		for(int j=0;j<1005;j++)
		{
			vis[j]=false;
		}
		for(int j=1;j<=N;j++)
		{
			if(vis[j]==false&&j!=check[i])
			{
				num++;
				DFS(j,check[i]);
			}
		}
		printf("%d\n",num-1);
	}
}