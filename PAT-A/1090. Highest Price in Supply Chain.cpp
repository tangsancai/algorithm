#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
typedef struct Node
{
	double price;
	int level;
	vector<int> child;
};
Node node[100005];
int maxlevel=-1;
void BFS(double R,int root)
{	
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(node[temp].level>maxlevel)
		{
			maxlevel=node[temp].level;
		}
		for(int i=0;i<node[temp].child.size();i++)
		{
			node[node[temp].child[i]].price=node[temp].price*(1+R/100);
			node[node[temp].child[i]].level=node[temp].level+1;
			q.push(node[temp].child[i]);
		}
	}
}
void BFS2(int root)
{
	int num=0;
	double maxprice;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(node[temp].level==maxlevel)
		{
			num++;
			maxprice=node[temp].price;
		}
		for(int i=0;i<node[temp].child.size();i++)
		{
			q.push(node[temp].child[i]);
		}
	}
	printf("%.2f %d",maxprice,num);
}
int main()
{
	int N;
	double P;
	double R;
	int root;
	scanf("%d%lf%lf",&N,&P,&R);	
	for(int i=0;i<N;i++)
	{
		int Num;
		scanf("%d",&Num);
		if(Num==-1)
		{
			root=i;
		}
		else
		{
			node[Num].child.push_back(i);
		}
	}
	node[root].price=P;
	node[root].level=0;
	BFS(R,root);
	BFS2(root);
}