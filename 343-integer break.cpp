#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int integerBreak(int n)
{
	int maxsum=-1;
	for(int i=2;i<=58;i++)
	{
		int sum=1;
		int num=i;
		int menber=n/i;
		int remainers=n%i;
		for(int j=0;j<remainers;j++)
		{
			sum*=(menber+1); 
		} 
		for(int j=remainers;j<num;j++)
		{
			sum*=menber;
		}
		if(sum>maxsum)
		{
			maxsum=sum;
		}
	}
	return maxsum;
}

int main()
{
	cout<<integerBreak(11);
}