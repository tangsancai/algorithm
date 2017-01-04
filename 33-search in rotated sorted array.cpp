#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target)
{
	int len=nums.size();
	int s=0;
	int e=len-1;
	int mid;
	while(s<=e)
	{
		while(nums[s]>target)
			++s;
		while(nums[e]<target)
			--e;
		if(s>e)
			return -1;
		mid=(s+e)/2;
		if(nums[mid]==target)
			return mid;
		else if(nums[mid]<target)
			s=mid+1;
		else if(nums[mid]>target)
			e=mid-1;			
	}
	return -1;
}
int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	cout<<search(nums,7)<<endl;
}