#include<vector>
#include<iostream>
#include<set>
using namespace std;
int maxP=-1;
void countMP(int k,int i,int sum,vector< vector<int> > dp)
{
	if(i>=dp.size()||k<=0)
	{
		maxP=maxP>sum?maxP:sum;
		return;
	}	
	for(int j=i+1;j<dp[i].size();++j)
		if(dp[i][j]>0)
			countMP(k-1,j+1,sum+dp[i][j],dp);
	countMP(k,i+1,sum,dp);
}
int maxProfit1(int k, vector<int>& prices)//TIME LIMIT E
{
	int len=prices.size();
	if(len<=1)
		return 0;
	vector< vector<int> > dp(len,vector<int>(len,0));
	for(int i=0;i<len;++i)
		for(int j=i+1;j<len;++j)
			if(prices[j]-prices[i]>0)
				dp[i][j]=prices[j]-prices[i];	
	countMP(k,0,0,dp);
	return maxP;
}


int maxProfit(int k, vector<int> &prices)
{
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveMaxProfit(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(3);
	v.push_back(5);
	v.push_back(0);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	cout<<maxProfit(2,v);
}