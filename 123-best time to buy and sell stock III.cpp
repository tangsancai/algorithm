#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[30005];
int dp2[30005];
void initnums(vector<int>& prices)
{
 	int len=prices.size();
	if(len==0)
	{
	   	return;	    
 	}
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	int m1=prices[0];
	for(int i=1;i<len;++i)
	{
		if(prices[i]>m1)
		{
			dp[i]=(prices[i]-m1)>dp[i-1]?(prices[i]-m1):dp[i-1];
		}
		else
		{
			dp[i]=dp[i-1];
			m1=prices[i];	
		}
	}
	int m2=prices[len-1];
	for(int i=len-2;i>=0;--i)
	{
		if(prices[i]<m2)
		{
			dp2[i]=(m2-prices[i])>dp2[i+1]?(m2-prices[i]):dp2[i+1];
		}
		else
		{
			dp2[i]=dp2[i+1];
			m2=prices[i];
		}
	}
}
int maxProfit(vector<int>& prices) 
{
	int len=prices.size();
 	if(len<2)
	{
		return 0;
	}
	if(len==2)
	{
		return prices[1]-prices[0]>0?prices[1]-prices[0]:0;
	}
	initnums(prices);
	int maxsum=0;
	for(int i=0;i<len;++i)
	{
		int tmpp=dp[i]+dp2[i];
		if(tmpp>maxsum)
		{
			maxsum=tmpp;
		}	
  	}
  	return maxsum;
}