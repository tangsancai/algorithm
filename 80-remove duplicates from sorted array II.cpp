#include<iostream>
#include<vector>
#include<map>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	map<int,int> m;
	int i=0;
	while(i<nums.size())
	{
		int tmp=0;
		if(m.count(nums[i])>0)
			tmp=m[nums[i]];
		if(tmp==2)
			nums.erase(nums.begin()+i);
		else
		{
			m[nums[i]]=++tmp;
			++i;
		}
	}
	return nums.size();	
}