#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
typedef struct Node
{
	int level;
	vector<int> child;
};
Node node[105];
int num[105]={0};
int maxlevel=-1;
void BFS()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int temp=q.front();
		if(node[temp].child.size()==0)
		{
			num[node[temp].level]++;
		}	
		if(node[temp].level>maxlevel)
		{
			maxlevel=node[temp].level;
		}
		q.pop();
		for(int i=0;i<node[temp].child.size();i++)
		{
			node[node[temp].child[i]].level=node[temp].level+1;
			q.push(node[temp].child[i]);
		}
	}
}
int main()
{
	int N;
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int root;
		int childrenNum;
		int children;
		scanf("%d%d",&root,&childrenNum);
		for(int j=0;j<childrenNum;j++)
		{
			scanf("%d",&children);
			node[root].child.push_back(children);
		}
	}
	node[1].level=0;
	BFS();
	printf("%d",num[0]);
	for(int i=1;i<=maxlevel;i++)
	{
		printf(" %d",num[i]);
	}
}