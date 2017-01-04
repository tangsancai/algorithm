#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef struct Node
{
	double price;
	vector<int> child;
	int productNum;
};
Node node[100005];
int N;
double P;
double R;
double sum=0.0;
void BFS()
{
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int temp=q.front();
		if(node[temp].child.size()==0)
		{
			sum=sum+node[temp].price*node[temp].productNum;
		}
		q.pop();
		for(int i=0;i<node[temp].child.size();i++)
		{
			node[node[temp].child[i]].price=node[temp].price*(1+R/100);
			q.push(node[temp].child[i]);
		}
	}
}
int main()
{
	scanf("%d%lf%lf",&N,&P,&R);
	for(int i=0;i<N;i++)
	{
		int K;
		scanf("%d",&K);
		if(K==0)
		{
			scanf("%d",&node[i].productNum);
			node[i].child.clear();
		}
		for(int j=0;j<K;j++)
		{
			int Num;
			scanf("%d",&Num);
			node[i].child.push_back(Num);
		}
	}
	node[0].price=P;
	BFS();
	printf("%.1f",sum);
}