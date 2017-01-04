#include<iostream>
#include<vector>
using namespace std;
int partitionm(vector<int> &nums,int s,int e)
{
	int tag=nums[s];
	while(s<e)
	{
		while(tag<=nums[e]&&s<e)
			--e;
		nums[s]=nums[e];
		while(nums[s]<=tag&&s<e)
			++s;
		nums[e]=nums[s];
	}
	nums[s]=tag;
	return s;
}
int findKthLargest(vector<int>& nums, int k)
{
	int s=0;
	int e=nums.size()-1;
	int index;
	while(1)
	{
		index=partitionm(nums,s,e);
		if(e-index+1==k)
			return nums[index];
		else if(e-index+1>k)
			s=index+1;
		else
		{
			k-=(e-index+1);
			e=index-1;
		}
	}	
	return -1;
}
int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	cout<<findKthLargest(v,2);
}