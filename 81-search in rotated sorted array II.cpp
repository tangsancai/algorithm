#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>& nums, int target)
{
	int len=nums.size();
	int s=0;
	int e=len-1;
	int mid;
	while(s<=e)
	{
		while(s<nums.size()&&nums[s]>target)
    		++s;
		if(s==nums.size()-1&&nums[s]!=target)
			return false;
		while(e>=0&&nums[e]<target)
    		--e;
		if(e==0&&nums[e]!=target)
			return false;
		if(s>e)
    		return false;
		mid=(s+e)/2;
		if(nums[mid]==target)
    		return true;
		else if(nums[mid]<target)
    		s=mid+1;
		else if(nums[mid]>target)
    		e=mid-1;			
 	}
 	return false;
}