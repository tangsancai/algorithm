#include<stdio.h>
#include<algorithm>
using namespace std;
long long coupon[100005];
long long product[100005];
bool cmp(long long a,long long b)
{
	return a>b;
}
bool cmp1(long long a,long long b)
{
	return a<b;
}
int main()
{
	int NC;
	int NP;
	long long sum;
	scanf("%d",&NC);
	for(int i=0;i<NC;i++)
	{
		scanf("%lld",&coupon[i]);
	}
	sort(coupon,coupon+NC,cmp);
	scanf("%d",&NP);
	for(int i=0;i<NP;i++)
	{
		scanf("%lld",&product[i]);
	}
	sort(product,product+NP,cmp);
	sum=0;
	for(int i=0;i<NC;i++)
	{
		if(coupon[i]>0&&product[i]>0)
		{
			sum=coupon[i]*product[i]+sum;
		}
		else
		{
			break;
		}
	}
	sort(coupon,coupon+NC,cmp1);
	sort(product,product+NP,cmp1);
	for(int i=0;i<NC;i++)
	{
		if(coupon[i]<0&&product[i]<0)
		{
			sum=coupon[i]*product[i]+sum;
		}
		else
		{
			break;
		}
	}
	printf("%d",sum);
}