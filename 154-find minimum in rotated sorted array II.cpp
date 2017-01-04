#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums)
{
	if(nums.size()==0)
		return 0;
	if(nums.size()==1)
		return nums[0];
	int s=0;
	int e=nums.size()-1;
	while(s<e&&nums[s]>=nums[e])
	{	
		int mid=(s+e)/2;	
	 	if(nums[mid]==nums[s])
			++s;
		else if(nums[mid]<nums[s])
			e=mid;
		else
			s=mid+1;
	}
	return nums[s];
}
int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);	
	cout<<findMin(v);
} 