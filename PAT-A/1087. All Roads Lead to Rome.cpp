#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<limits.h>
#include<map>
#include<string>
#define Maxv 205
using namespace std;
int happness[Maxv]={0};
bool vis[Maxv]={false};
int G[Maxv][Maxv];
map<string,int> city;
map<int,string> cityRe;//±„”⁄≤È’“
int pre[Maxv];
int dis[Maxv];
int happnesstemp[Maxv]={0};
int cityNum[Maxv]={0}; 
int Num[Maxv]={0};
void Dijsktra(int N)
{
	fill(dis,dis+Maxv,INT_MAX);
	dis[0]=0;
	Num[0]=1;
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
			if(vis[v]==false&&G[u][v]!=INT_MAX)
			{
				if(dis[v]>dis[u]+G[u][v])
				{
					dis[v]=dis[u]+G[u][v];
					happnesstemp[v]=happnesstemp[u]+happness[v];
					cityNum[v]=cityNum[u]+1;
					Num[v]=Num[u];
					pre[v]=u;
				}
				else if(dis[v]==dis[u]+G[u][v])
				{
					Num[v]=Num[u]+Num[v];
					if(happnesstemp[v]<happnesstemp[u]+happness[v])
					{
						happnesstemp[v]=happnesstemp[u]+happness[v];
						cityNum[v]=cityNum[u]+1;
						pre[v]=u;
					}
					else if(happnesstemp[v]==happnesstemp[u]+happness[v])
					{
						if(cityNum[v]>cityNum[u]+1)
						{
							cityNum[v]=cityNum[u]+1;
							pre[v]=u;
						}
					}
				}
			}
		}
	}
}
void DFS(int n)
{
	if(pre[n]==n)
	{
		cout<<cityRe[n];
		printf("->");
		return;
	}
	DFS(pre[n]);
	cout<<cityRe[n];
	if(n!=city["ROM"])
	{
		printf("->");
	}
}
int main()
{
	int N;
	int K;
	string start;
	cin>>N>>K>>start;
	city[start]=0;
	cityRe[0]=start;
	for(int i=1;i<N;i++)
	{
		string name;
		int happnessV;
		cin>>name>>happnessV;
		city[name]=i;
		cityRe[i]=name;
		happness[i]=happnessV;	
	}
	fill(G[0],G[0]+Maxv*Maxv,INT_MAX);
	for(int i=0;i<K;i++)
	{
		string c1;
		string c2;
		int dist;
		cin>>c1>>c2>>dist;
		G[city[c1]][city[c2]]=dist;
		G[city[c2]][city[c1]]=dist;
	}
	for(int i=0;i<Maxv;i++)
	{
		pre[i]=i;
	}
	Dijsktra(N);
	printf("%d %d %d %d\n",Num[city["ROM"]],dis[city["ROM"]],happnesstemp[city["ROM"]],happnesstemp[city["ROM"]]/cityNum[city["ROM"]]);
	DFS(city["ROM"]);
}