#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct stuInfo
{
	int id;
	char name[15];
	int grade;	
};
stuInfo stu[100005];
bool cmp1(stuInfo a,stuInfo b)
{
	return a.id<b.id;
}
bool cmp2(stuInfo a,stuInfo b)
{
	if(strcmp(a.name,b.name)!=0)
	{
		return strcmp(a.name,b.name)<0;
	}
	return a.id<b.id;
}
bool cmp3(stuInfo a, stuInfo b)
{
	if(a.grade!=b.grade)
	{
		return a.grade<b.grade;
	}
	return a.id<b.id;
}
int main()
{
	int N;
	int col;
	scanf("%d%d",&N,&col);
	for(int i=0;i<N;i++)
	{
		scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	switch(col)
	{
		case 1:
			sort(stu,stu+N,cmp1);
			break;
		case 2:
			sort(stu,stu+N,cmp2);
			break;
		case 3:
			sort(stu,stu+N,cmp3);
			break;
	}
	for(int i=0;i<N;i++)
	{
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
}