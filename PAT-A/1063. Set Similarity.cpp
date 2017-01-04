#include<stdio.h>
#include<set>
using namespace std;
set<int>num[55];
int main()
{
	int setSize1;
	int setSize2;
	int setSize3;
	int N;
	int M;
	int K;
	int n;
	int n1;
	int n2;
	char a='%';
	int totlenum;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&M);
		for(int j=0;j<M;j++)
		{
			scanf("%d",&n);
			num[i].insert(n);
		}
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		totlenum=0;
		scanf("%d %d",&n1,&n2);
		totlenum=num[n1].size();
		for(set<int>::iterator it=num[n2].begin();it!=num[n2].end();it++)
		{
			if(num[n1].find(*it)==num[n1].end())
			{
				totlenum++;
			}
		}
		double sim=(num[n1].size()+num[n2].size()-totlenum+0.0)/totlenum;
		printf("%.1f%c\n",sim*100,a);
		num[0].clear();
	}	
}