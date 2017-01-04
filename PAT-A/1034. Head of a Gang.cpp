#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
bool vis[20000]={false};
vector<int> eage[20000];
int cost[20000]={0};
typedef struct Group
{
	int totlecost;
	int theHead;
	int theMax;
	int groupNum;
	char headName[5];
};
Group G[20000];

int HashTrun(char name[])
{
	return (name[2]-'A')*26*26+(name[1]-'A')*26+(name[0]-'A');
}

void TrunHash(int num,char temp[5])
{
	memset(temp,'\0',sizeof(temp));
	temp[0]=num%26+'A';
	num=num/26;
	temp[1]=num%26+'A';
	num=num/26;
	temp[2]=num+'A';
}

void DFS(int u,int num)
{
	if(cost[u]>G[num].theMax)
	{
		G[num].theMax=cost[u];
		G[num].theHead=u;
	}
	G[num].groupNum++;
	G[num].totlecost=G[num].totlecost+cost[u];
	vis[u]=true;
	for(int i=0;i<eage[u].size();i++)
	{
		int v=eage[u][i];
		if(vis[v]==false)
		{
			DFS(v,num);
		}
	}
}
bool cmp(Group a,Group b)
{
	return strcmp(a.headName,b.headName)<0;
}
int main()
{
	int N;
	int threshold;
	vector<int> number;
	scanf("%d%d",&N,&threshold);
	for(int i=0;i<N;i++)
	{
		char a[5];
		char b[5];
		int t;
		scanf("%s%s%d",a,b,&t);
		int tempa=HashTrun(a);
		int tempb=HashTrun(b);
		eage[tempa].push_back(tempb);
		eage[tempb].push_back(tempa);
		if(cost[tempa]==0)
		{
			number.push_back(tempa);
		}
		if(cost[tempb]==0)
		{
			number.push_back(tempb);
		}
		cost[tempa]=t+cost[tempa];
		cost[tempb]=t+cost[tempb];
		
	}
	int num=-1;
	for(int i=0;i<number.size();i++)
	{
		if(vis[number[i]]==false)
		{
			num++;
			G[num].totlecost=0;
			G[num].theMax=-1;
			G[num].groupNum=0;
			DFS(number[i],num);
		}
	}
	vector<Group> tem;
	for(int i=0;i<=num;i++)
	{
		if((G[i].totlecost/2)>threshold&&G[i].groupNum>2)
		{
			char ttt[5];
			TrunHash(G[i].theHead,ttt);
			strcpy(G[i].headName,ttt);
			tem.push_back(G[i]);
		}
	}
	printf("%d\n",tem.size());
	sort(tem.begin(),tem.end(),cmp);
	for(int i=0;i<tem.size();i++)
	{
		printf("%s %d\n",tem[i].headName,tem[i].groupNum);
	}
}