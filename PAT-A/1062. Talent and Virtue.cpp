#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct Node
{
	char no[10];
	int D;
	int C;
};
Node DHCH[100005];
Node DHCL[100005];
Node DLCL[100005];
Node DC[100005];
bool cmp(Node a,Node b)
{
	int suma=a.D+a.C;
	int sumb=b.D+b.C;
	if(suma!=sumb)
	{
		return suma>sumb;
	}
	else if(a.D!=b.D&&suma==sumb)
	{
		return a.D>b.D;
	}
	else if(a.D==b.D&&suma==sumb)
	{
		return strcmp(a.no,b.no)<0;//字符串比较大小一定要用这个函数，直接比是错误的 
	}
}
int main()
{
	int N;
	int L;
	int H;
	int i1=0;
	int i2=0;
	int i3=0;
	int i4=0;
	char no[10];
	int D;
	int C;
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++)
	{
		scanf("%s%d%d",no,&D,&C);
		if(D>=L&&C>=L)
		{
			if(D>=H&&C>=H)
			{
				strcpy(DHCH[i1].no,no);
				DHCH[i1].D=D;
				DHCH[i1].C=C;
				i1++;
			}
			else if(D>=H&&C<H)
			{
				strcpy(DHCL[i2].no,no);
				DHCL[i2].D=D;
				DHCL[i2].C=C;
				i2++;
			}
			else if(D<H&&C<H&&D>=C)
			{
				strcpy(DLCL[i3].no,no);
				DLCL[i3].D=D;
				DLCL[i3].C=C;
				i3++;
			}
			else
			{
				strcpy(DC[i4].no,no);
				DC[i4].D=D;
				DC[i4].C=C;
				i4++;
			}
		}
	}
	sort(DHCH,DHCH+i1,cmp);
	sort(DHCL,DHCL+i2,cmp);
	sort(DLCL,DLCL+i3,cmp);
	sort(DC,DC+i4,cmp);
	printf("%d\n",i1+i2+i3+i4);
	for(int i=0;i<i1;i++)
	{
		printf("%s %d %d\n",DHCH[i].no,DHCH[i].D,DHCH[i].C);
	}
	for(int i=0;i<i2;i++)
	{
		printf("%s %d %d\n",DHCL[i].no,DHCL[i].D,DHCL[i].C);
	}
	for(int i=0;i<i3;i++)
	{
		printf("%s %d %d\n",DLCL[i].no,DLCL[i].D,DLCL[i].C);
	}
	for(int i=0;i<i4;i++)
	{
		printf("%s %d %d\n",DC[i].no,DC[i].D,DC[i].C);
	}
} 