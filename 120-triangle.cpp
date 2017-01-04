#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int minimumTotal(vector< vector<int> >& triangle)
{
	vector<int> dp;
	int len=triangle.size();
	if(len==0)
	{
		return 0;
	}
	if(len==1)
	{
		return triangle[0][0];
	}
	for(int i=0;i<len;i++)
	{
		dp.push_back(INT_MAX);
	}
	dp[0]=triangle[0][0];
	for(int i=1;i<len;i++)
	{
		int len2=triangle[i].size();
		dp[len2-1]=dp[len2-2]+triangle[i][len2-1];
		for(int j=len2-2;j>=1;j--)
		{
			int tmp1=dp[j]+triangle[i][j];
			int tmp2=dp[j-1]+triangle[i][j];
			dp[j]=tmp1<tmp2?tmp1:tmp2;
		}
		dp[0]=dp[0]+triangle[i][0];
	}
	sort(dp.begin(),dp.end());
	return dp[0];
}

int main()
{
	vector<int> a;
	a.push_back(-10);
	vector< vector<int> > p;
	p.push_back(a);
	minimumTotal(p);
}