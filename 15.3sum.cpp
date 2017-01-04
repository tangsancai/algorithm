#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > threeSum(vector<int>& nums)
{
	vector< vector<int> > v;
	sort(nums.begin(),nums.end());
	int i=0;
	while(i<nums.size())
	{
		int s=i+1;
		int e=nums.size()-1;
		while(s<e)
		{
			if(nums[i]+nums[s]+nums[e]==0)
			{
				vector<int> tmp;
				tmp.push_back(nums[i]);
				tmp.push_back(nums[s]);
				tmp.push_back(nums[e]);
				v.push_back(tmp);
				while(s<e&&nums[s+1]==nums[s])
					++s;
				++s;
			}
			while(nums[i]+nums[s]+nums[e]>0)
			{
				--e;
				if(s>=e)
					break;
			}	
			while(nums[i]+nums[s]+nums[e]<0)
			{
				++s;
				if(s>=e)
					break;
			}
		}
		while(i+1<nums.size()&&nums[i+1]==nums[i])
			++i;
		++i;
	}
	return v;
}
int main()
{
	vector<int> nums;
	int tmp;
	while(cin>>tmp)
	{
		nums.push_back(tmp);
	}
	threeSum(nums);
}