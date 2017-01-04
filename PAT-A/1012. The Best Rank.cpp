#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct stuInfo
{
	int id;
	int rank[4];
	int grade[4];
};
typedef struct Node
{
	int rank;
	char course;
};
Node node[4];
stuInfo stu[2005];
stuInfo stuReal[1000000];
int Id[2005];
int Num=0;
bool cmp(stuInfo a, stuInfo b)
{
	return a.grade[Num]>b.grade[Num];
}
void Rank(int N)
{
	stu[0].rank[Num]=1;
	for(int i=1;i<N;i++)
	{
		if(stu[i].grade[Num]==stu[i-1].grade[Num])
		{
			stu[i].rank[Num]=stu[i-1].rank[Num];
		}
		else
		{
			stu[i].rank[Num]=i+1;
		}
	}
}
bool cmp2(Node a,Node b)
{
	if(a.rank!=b.rank)
	{
		return a.rank<b.rank;
	}
	return a.course<b.course;
}
void CmpRank(stuInfo a)
{
	for(int i=0;i<4;i++)
	{
		node[i].rank=a.rank[i];
		node[i].course='A'+i;
	}
	sort(node,node+4,cmp2);
	printf("%d ",node[0].rank);
	switch(node[0].course)
	{
		case 'A':
			printf("A\n");
			break;
		case 'B':
			printf("C\n");
			break;
		case 'C':
			printf("M\n");
			break;
		case 'D':
			printf("E\n");
			break;
	}
}
int main()
{
	int N;
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<1000000;i++)
	{
		stuReal[i].id=-1;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d%d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0]=(stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3;		
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d",&Id[i]);
	}
	for(int i=0;i<4;i++)
	{
		sort(stu,stu+N,cmp);
		Rank(N);
		Num++;
	}
	for(int i=0;i<N;i++)
	{
		stuReal[stu[i].id]=stu[i];
	}
	for(int i=0;i<M;i++)
	{
		if(stuReal[Id[i]].id!=-1)
		{
			CmpRank(stuReal[Id[i]]);
		}
		else
		{
			printf("N/A\n");
		}
	}
}