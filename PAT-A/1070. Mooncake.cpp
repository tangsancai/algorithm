#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct Node
{
	double Have;
	double TotalP;
	double SingleP;
};
Node moomcake[1005];
bool cmp(Node a,Node b)
{
	return a.SingleP>b.SingleP>0;
}
int main()
{
	int type;
	int require;
	int j=-1;
	double sum=0.0;
	double getP=0.0;
	scanf("%d%d",&type,&require);
	for(int i=0;i<type;i++)
	{
		scanf("%lf",&moomcake[i].Have);
		sum=sum+moomcake[i].Have;
	}
	for(int i=0;i<type;i++)
	{
		scanf("%lf",&moomcake[i].TotalP);
		getP=getP+moomcake[i].TotalP;
		moomcake[i].SingleP=moomcake[i].TotalP/moomcake[i].Have;
	}
	sort(moomcake,moomcake+type,cmp);
	if(sum<=require)
	{
		printf("%.2f",getP);
	}
	else
	{
		sum=0.0;
		getP=0.0;
		while(sum<require)
		{
			sum=moomcake[++j].Have+sum;
			getP=moomcake[j].TotalP+getP;
		}
		getP=getP-moomcake[j].TotalP;
		sum=sum-moomcake[j].Have;
		sum=require-sum;
		getP=getP+sum*moomcake[j].SingleP;
		printf("%.2f",getP);
	}
	
	
}