#include<iostream>
#include<vector>
using namespace std;

int maxSubArray1(vector<int>& nums)//TLM
{
	int sum=INT_MIN;
	int len=nums.size();
	vector<int> tmp(len,0);
	vector< vector<int> > dp(len,tmp);
	for(int r=1;r<=len;++r)
		for(int i=0;i<=len-r;++i)
		{
			int j=i+r-1;
			int tmp;
			if(i==j)
			{
				dp[i][j]=nums[i];
				tmp=dp[i][j];
			}	
			else 
			{
				dp[i][j]=dp[i][j-1]+nums[j];
				tmp=dp[i][j]>dp[i][j-1]?dp[i][j]:dp[i][j-1];
			}	
			if(tmp>sum)
				sum=dp[i][j];
		}
	return sum;
}

int maxSubArray(vector<int>& nums)
{
	int len=nums.size();
	int sum=INT_MIN;
	for(int i=0;i<nums.size();++i)
		if(nums[i]>sum)
			sum=nums[i];
	int ssum=0;
	for(int i=0;i<nums.size();++i)
	{
		if(ssum+nums[i]>=0)//ssum>=0时还有增长的可能 
		{
			ssum+=nums[i];
			if(ssum>sum)
				sum=ssum;
		}
		else
			ssum=0;	
	}
	return sum;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	cout<<maxSubArray(nums);
}
