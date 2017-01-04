#include<iostream>
#include<vector>
using namespace std;

int dp[105][105];
int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
{
	memset(dp,0,sizeof(dp));
	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	if(m==0)
		return 1;
	bool flag=true;
	for(int i=1;i<=m;++i)
	{
		if(obstacleGrid[i-1][0]==1)
			flag=false;
		if(obstacleGrid[i-1][0]==0&&flag)
			dp[i][1]=1;
		else
			dp[i][1]=0;
	}
	flag=true;
	for(int j=1;j<=n;++j)
	{
		if(obstacleGrid[0][j-1]==1)
			flag=false;
		if(obstacleGrid[0][j-1]==0&&flag)
			dp[1][j]=1;
		else
			dp[1][j]=0;
	}
	for(int i=2;i<=m;++i)
		for(int j=2;j<=n;++j)
			dp[i][j]=obstacleGrid[i-1][j-1]==1?0:dp[i-1][j]+dp[i][j-1];
	return dp[m][n];
}
int main()
{
	vector<int> tmp(1,0);
	vector< vector<int> > t(1,tmp);  
	cout<<uniquePathsWithObstacles(t);
}