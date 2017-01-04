#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct stuInfo
{
	int id;
	int Kscore[6];
	int totlesocre;
	int num;
	int rank;
	int flag;
};
stuInfo stu[10005];
stuInfo stuReal[10005];
int KscoreM[6]={0};
bool cmp(stuInfo a,stuInfo b)
{
	return a.totlesocre>b.totlesocre;
}
bool cmp2(stuInfo a,stuInfo b)
{
	if(a.rank!=b.rank)
	{
		return a.rank<b.rank;
	}
	else
	{
		if(a.num!=b.num)
		{
			return a.num>b.num;
		}
		else
		{
			return a.id<b.id;
		}
	}
}
int main()
{
	int N;
	int K;
	int M;
	int id;
	int Kscore;
	int proid;
	scanf("%d%d%d",&N,&K,&M);
	for(int i=0;i<10005;i++)
	{
		stu[i].rank=0;
		stu[i].totlesocre=0;
		stu[i].num=0;
		stu[i].flag=0;
		for(int j=0;j<6;j++)
		{
			stu[i].Kscore[j]=-2;
		}
	}
	for(int i=1;i<=K;i++)
	{
		scanf("%d",&KscoreM[i]);	
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&id,&proid,&Kscore);
		stu[id].id=id;
		if(stu[id].Kscore[proid]<Kscore)
		{
			stu[id].Kscore[proid]=Kscore;
			if(Kscore==KscoreM[proid])
			{
				stu[id].num++;
			}
		}
	}
	int num=0;
	for(int i=0;i<10005;i++)
	{
		for(int j=1;j<=K;j++)
		{
			if(stu[i].Kscore[j]>=0)
			{
				stu[i].flag=1;
				stu[i].totlesocre=stu[i].totlesocre+stu[i].Kscore[j];
			}
		}
		if(stu[i].flag==1)
		{
			stuReal[num++]=stu[i];
		}
	}
	sort(stuReal,stuReal+num,cmp);
	stuReal[0].rank=1;
	for(int i=1;i<num;i++)
	{
		if(stuReal[i].totlesocre==stuReal[i-1].totlesocre)
		{
			stuReal[i].rank=stuReal[i-1].rank;
		}
		else
		{
			stuReal[i].rank=i+1;
		}
	}
	sort(stuReal,stuReal+num,cmp2);
	for(int i=0;i<num;i++)
	{
		printf("%d %05d %d",stuReal[i].rank,stuReal[i].id,stuReal[i].totlesocre);
		for(int j=1;j<=K;j++)
		{
			switch(stuReal[i].Kscore[j])
			{
				case -1:
					printf(" 0");
					break;
				case -2:
					printf(" -");
					break;
				default:
					printf(" %d",stuReal[i].Kscore[j]);
					break;
			}
		}
		printf("\n");
	}
}