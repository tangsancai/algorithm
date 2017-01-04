#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	int len=nums.size();
	int i=1;
	while(i<len)
	{
		if(nums[i-1]==nums[i])
		{
			--len;
			nums.erase(i);
		}
		else
			++i;
	}
	return len;
}