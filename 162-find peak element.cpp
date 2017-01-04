#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums)
{
	if(nums.size()==1)
		return 0;
	int pre=INT_MIN;
	int post;
	for(int i=0;i<nums.size()-1;++i)
	{
		if(pre<nums[i]&&nums[i+1]<nums[i])
			return i;
		pre=nums[i];
	}
	if(pre<nums[nums.size()-1])
		return nums.size()-1;
	return -1;
}