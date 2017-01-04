#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums)
{
	int sum=0;
	int len=nums.size();
	if(len<=1)
		return sum;
	int reach=nums[0];
	int i=1;
	while(i<len&&reach<len-1)
	{
		++sum;
		int maxtmp=reach;
		for(int j=i;j<=reach;++j)
			if(maxtmp<nums[j]+j)
			{
				maxtmp=nums[j]+j;
				if(maxtmp>=len-1)
					return sum+1;
			}
		
		i=reach+1;
		reach=maxtmp;
	}
	return sum+1;
}