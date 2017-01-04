#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct stuInfo
{
	char name[15];
	char id[15];
	int grade;
};
stuInfo stu[1000000];
bool cmp(stuInfo a,stuInfo b)
{
	return a.grade>b.grade>0;
}
int main()
{
	int grade1;
	int grade2;
	int N;
	int flag=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s%s%d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	scanf("%d%d",&grade1,&grade2);
	sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++)
	{
		if(stu[i].grade>=grade1&&stu[i].grade<=grade2)
		{
			flag=1;
			printf("%s %s\n",stu[i].name,stu[i].id);
		}
	}
	if(flag==0)
	{
		printf("NONE");
	}
}