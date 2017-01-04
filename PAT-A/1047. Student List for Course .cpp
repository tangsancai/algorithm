#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct Name
{
	char name[5];
};
vector<Name>course[2505];
bool cmp(Name a,Name b)
{
	return strcmp(a.name,b.name)<0;
}
int main()
{
	int N;
	int K;
	char name[5];
	int C;
	int courseNO;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%s",name);
		Name n;
		strcpy(n.name,name);
		scanf("%d",&C);
		for(int j=0;j<C;j++)
		{
			scanf("%d",&courseNO);
			course[courseNO].push_back(n);
		}
	}
	for(int i=1;i<=K;i++)
	{
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++)
		{
			printf("%s\n",course[i][j].name);
		}
	}
}
