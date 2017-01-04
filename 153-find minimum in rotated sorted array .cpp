#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums)
{
	int s=0;
	int e=nums.size()-1;
	int minn=nums[s]<nums[e]?nums[s]:nums[e];
	while(s<=e)
	{
		int mid=(s+e)/2;//cout<<nums[mid]<<endl;
		if(nums[s]<=nums[e])
		{
			minn=minn<nums[s]?minn:nums[s];
			break;
		}
		else
		{	
			if(e-s+1<=2)
			{
				minn=minn<nums[s]?minn:nums[e];
				minn=minn<nums[e]?minn:nums[e];
				break;
			}
			else if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1])
			{
				minn=minn<nums[mid]?minn:nums[mid];
				break;
			}
			else if(nums[mid]>nums[s]&&nums[mid]>nums[e])
				s=mid+1;
			else if(nums[mid]<nums[s]&&nums[mid]<nums[e])
				e=mid-1;
		}
	}
	return minn;
} 
int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(-1);
	cout<<findMin(v);
} 