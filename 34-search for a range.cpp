#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(-1);
	int len=nums.size();
	int s=0;
	int e=len-1;
	int mid;
	if(target<nums[0]||target>nums[e])
		return v;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(nums[mid]==target)
		{
			v[0]=mid;
			v[1]=mid;
			int i=mid;
			while(--i>=0&&nums[i]==nums[i+1])
				v[0]=i;
			while(++mid<=len-1&&nums[mid]==nums[mid-1])
				v[1]=mid;
			return v;
		}
		else if(nums[mid]<target)
			s=mid+1;
		else if(nums[mid]>target)
			e=mid-1;
	}
	return v;
}

int main()
{
	vector<int> v;
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);
	v.push_back(8);
	v.push_back(8);
	v.push_back(8);
	v=searchRange(v,7);
	cout<<v[0]<<" "<<v[1]<<endl;
}