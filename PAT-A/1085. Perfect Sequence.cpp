#include<stdio.h>
#include<algorithm>
using namespace std;
int Num[100005];
int main()
{
	int N;
	long long p;
	scanf("%d%lld",&N,&p);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&Num[i]);
	}	
	sort(Num,Num+N);
	long long mmin=(long long)Num[0];
	long long mmax=(long long)Num[0];
	int i=0;
	int j=0;
	int num=0;
	int nummax=0;
	while(i<N&&j<N)
	{
		if(mmax<=(mmin*p))
		{
			j++;
			mmax=(long long)Num[j];
			num++;
			if(num>nummax)
			{
				nummax=num;
			}
		}
		else
		{
			i++;
			mmin=(long long)Num[i];
			num--;
		}
	}
	printf("%d",nummax);
}