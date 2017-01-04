#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
	int sum=0;
	int len=prices.size();
	for(int i=0;i<len-1;i++)
	{
		int tmp=(prices[i+1]-prices[i])>0?prices[i+1]-prices[i]:0;
		sum+=tmp;
	}
	return sum;
}

int main()
{
	vector<int> prices;
	prices.push_back(2);
	prices.push_back(1);
	cout<<maxProfit(prices);
}