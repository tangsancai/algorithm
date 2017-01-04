#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	int len=nums.size();
	int i=0;
	while(i<len)
		if(nums[i]>0&&nums[i]<=len&&nums[i]!=i+1&&nums[nums[i]-1]!=nums[i])
			swap(nums[i],nums[nums[i]-1]); 
 		else
   			++i;
    	for(i=0;i<len;++i)
    		if(nums[i]!=i+1)
    			return i+1;
    	return len+1;
} 

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	cout<<firstMissingPositive(nums);
} 