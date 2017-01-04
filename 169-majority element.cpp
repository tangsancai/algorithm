#include<iostream>
#include<map>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums)
{
	map<int,int> m;
	int len=nums.size();
	for(int i=0;i<len;++i)
	{
		int tmp=0;
		if(m.count(nums[i])>0)
			tmp=m[nums[i]];
		m[nums[i]]=++tmp;
		if(tmp>len/2)
			return nums[i];
	}
	return -1;
}