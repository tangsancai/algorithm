#include<iostream>
#include<vector>
#include<map>
using namespace std;

int singleNumber(vector<int>& nums)
{
	map<int,int> h;
	int len=nums.size();
	for(int i=0;i<len;++i)
	{
		if(h.find(nums[i])!=h.end())
		{
			h[nums[i]]=2;	
		}
		else
		{
			h[nums[i]]=1;
		}
	}
	for(int i=0;i<len;++i)
	{
		if(h[nums[i]]==1)
		{
			return nums[i];
		}
	}
	return 2;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(11);
	v.push_back(12);
	v.push_back(12);
	v.push_back(13);
	cout<<singleNumber(v);
}