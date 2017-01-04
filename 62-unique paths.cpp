#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int dp[105][105];
int uniquePaths(int m,int n)
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;++i)
		dp[i][1]=1;
	for(int j=1;j<=n;++j)
		dp[1][j]=1;
	for(int i=2;i<=m;++i)
		for(int j=2;j<=n;++j)
			dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
	return dp[m][n];
}

int main()
{
	cout<<uniquePaths(3,7);
}