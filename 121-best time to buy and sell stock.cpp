#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
	int resu=0;
	int len=prices.size();
	if(len==0)
	{
		return 0;
	}
	vector<int> maxnum;
	vector<int> minnum;
	maxnum.push_back(prices[len-1]);
	minnum.push_back(prices[0]);
	for(int i=len-2;i>=0;i--)
	{
		int tmp1=prices[i]>maxnum[len-1-i-1]?prices[i]:maxnum[len-1-i-1];
		maxnum.push_back(tmp1);
		int tmp2=prices[len-1-i]<minnum[len-1-i-1]?prices[len-1-i]:minnum[len-1-i-1];
		minnum.push_back(tmp2);
	}
	for(int i=0;i<len;i++)
	{
		int tmp=maxnum[len-1-i]-minnum[i];
		resu=resu>tmp?resu:tmp;	
	}
	return resu;
} 
int main()
{
	vector<int> prices;
	prices.push_back(7);
	prices.push_back(1);
	prices.push_back(5);
	prices.push_back(3);
	prices.push_back(6);
	prices.push_back(4);
	maxProfit(prices);
}