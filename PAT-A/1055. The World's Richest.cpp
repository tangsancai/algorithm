#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct richerInfo
{
	char name[10];
	int age;
	int worth;
};
richerInfo richer[100005];
int Age[210]={0};
bool cmp(richerInfo a,richerInfo b)
{
	if(a.worth!=b.worth)
	{
		return a.worth>b.worth;
	}
	if(a.age!=b.age)
	{
		return a.age<b.age;
	}
	return strcmp(a.name,b.name)<0;
}
int main()
{
	int N;
	int K;
	int num;
	int limitP;
	int Amin;
	int Amax;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%s%d%d",richer[i].name,&richer[i].age,&richer[i].worth);
	}
	sort(richer,richer+N,cmp);
	for(int i=0;i<K;i++)
	{
		scanf("%d%d%d",&limitP,&Amin,&Amax);
		printf("Case #%d:\n",i+1);
		num=0;
		for(int j=0;j<N;j++)
		{
			if(richer[j].age>=Amin&&richer[j].age<=Amax&&num<limitP)
			{
				num++;
				printf("%s %d %d\n",richer[j].name,richer[j].age,richer[j].worth);	
				if(num==limitP)
				{
					break;
				}
			}
		}
		if(!num)
		{
			printf("None\n");
		}
	}
} 