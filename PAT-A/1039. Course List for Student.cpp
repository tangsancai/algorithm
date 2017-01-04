#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int>stucourse[26*26*26*10+1];
int getId(char name[])
{
	int id=0;
	for(int i=0;i<3;i++)
	{
		id=id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
}
int main()
{
	int N;
	int K;
	int courseNo;
	int registerNo;
	char name[5];
	int id;
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d%d",&courseNo,&registerNo);
		for(int j=0;j<registerNo;j++)
		{
			scanf("%s",name);
			id=getId(name);
			stucourse[id].push_back(courseNo);
		}
	}
	for(int i=0;i<N;i++)
	{
		scanf("%s",name);
		id=getId(name);
		sort(stucourse[id].begin(),stucourse[id].end());
		printf("%s %d",name,stucourse[id].size());
		for(int j=0;j<stucourse[id].size();j++)
		{
			printf(" %d",stucourse[id][j]);
		}
		printf("\n");
	}
}