#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct stuInfo
{
	char Id[20];
	int score;
	int totlerank;
	int localrank;
	int local;
};
stuInfo stu[30005];
bool cmp(stuInfo a,stuInfo b)
{
	if(a.score!=b.score)
	{
		return a.score>b.score>0;
	}
	return strcmp(a.Id,b.Id)<0;
}
int main()
{
	int N;
	int K;
	int num1=0;
	int num2=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		num1=num2;
		scanf("%d",&K);
		while(K--)
		{
			scanf("%s%d",stu[num2].Id,&stu[num2].score);
			stu[num2].local=i;
			num2++;
		}
		sort(stu+num1,stu+num2,cmp);
		stu[num1].localrank=1;
		for(int j=num1+1;j<num2;j++)
		{
			if(stu[j].score==stu[j-1].score)
			{
				stu[j].localrank=stu[j-1].localrank;
			}
			else
			{
				stu[j].localrank=j-num1+stu[num1].localrank;
			}
		}
	}
	sort(stu,stu+num2,cmp);
	stu[0].totlerank=1;
	for(int i=1;i<num2;i++)
	{
		if(stu[i].score==stu[i-1].score)
		{
			stu[i].totlerank=stu[i-1].totlerank;
		}
		else
		{
			stu[i].totlerank=i+1;	
		}
	}
	printf("%d\n",num2);
	for(int i=0;i<num2;i++)
	{
		printf("%s %d %d %d\n",stu[i].Id,stu[i].totlerank,stu[i].local,stu[i].localrank);
	}
}