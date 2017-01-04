#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
typedef struct Node
{
	char a;
	double b;
};
bool cmp(Node a,Node b)
{
	return a.b>b.b>0;
}
int main()
{
	double W;
	double T;
	double L;
	double sum=1.0;	
	Node data[3];
	char a[3];
	for(int i=0;i<3;i++)
	{
		scanf("%lf%lf%lf",&W,&T,&L);
		data[0].a='W';
		data[0].b=W;
		data[1].a='T';
		data[1].b=T;
		data[2].a='L';
		data[2].b=L;
		sort(data,data+3,cmp);
		sum=sum*data[0].b;
		a[i]=data[0].a;
	}
	for(int i=0;i<3;i++)
	{
		printf("%c ",a[i]);
	}
	printf("%.2f",round((sum*0.65-1)*2*100)/100);
}