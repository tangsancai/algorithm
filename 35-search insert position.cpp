#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	int len=nums.size();
	if(nums[0]>target)
		return 0;
	if(nums[len-1]<target)
		return len;
	int s=0;
	int e=len-1;
	int mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(nums[mid]==target)
			return mid;
		else if(nums[mid]>target)
		{
			if(s==e)
				break;
			e=mid-1;
		}
		else if(nums[mid]<target)
		{
			if(s==e)
				break;
			s=mid+1;
		} 
	}
	s=(s-1)>0?(s-1):0;
	e=(e+1)<(len-1)?(e+1):(len-1);
	for(int i=s;i<=e;++i)
		if(nums[i]>target)
			return i;
}

int main()
{
	vector<int>nums;
	nums.push_back(1);
	nums.push_back(3);
	cout<<searchInsert(nums,2)<<endl;
}