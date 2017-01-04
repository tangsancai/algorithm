#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums)
{
	int len=nums.size();
	int pre=0;
	while(nums[pre]==0)
		++pre;
	int post=nums.size()-1;
	while(nums[post]==2)
		--post;
	int i=pre;
	while(pre<post&&i<=post)
	{	
		if(nums[i]==2)
		{	
			swap(nums[i],nums[post]);
			--post;
		} 
		if(nums[i]==0&&i==pre)
		{
			++pre;
			++i;
		}
		else if(nums[i]==0&&i!=pre)
		{
			swap(nums[i],nums[pre]);
			++pre;
		}
		if(nums[i]==1)
			++i;
	}
} 

int main()
{
	vector<int> nums;
	nums.push_back(2);
	sortColors(nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i];
}
/*
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(0);*/