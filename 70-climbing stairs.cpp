#include<vector>
#include<iostream>
using namespace std;

int climbStairs(int n)
{
	vector<int> dp(n+1,0);
	dp[0]=1;
	dp[1]=1;
	dp[2]=dp[0]+dp[1];
	if(n<=2)
		return dp[n];
	for(int i=3;i<=n;++i)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}

int main()
{
	cout<<climbStairs(6)<<endl;
}