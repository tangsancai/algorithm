#include<iostream>
#include<vector>
using namespace std;
int Num(int n,vector<int> &dp)
{
   	if(dp[n]!=0)
    	return dp[n];
   	for(int i=0;i<n;++i)
    	dp[n]+=Num(i,dp)*Num(n-i-1,dp); 
   	return dp[n];
}
int numTrees(int n)
{
	if(n==0)
    	return 0;
	vector<int> dp(1000,0);
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	return Num(n,dp);
} 
int main()
{
	cout<<numTrees(5);
}