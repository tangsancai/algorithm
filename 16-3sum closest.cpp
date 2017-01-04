#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	if(!nums.size())
		return 0;
  	if(nums.size()<=3) 
	  	return accumulate(nums.begin(),nums.end(),0);
    sort(nums.begin(),nums.end()); 
    int ret=nums[0]+nums[1]+nums[2];
	int sum=ret; 
 	if(sum>=target) 
	 	return sum;
   	if((sum=nums[nums.size()-3]+nums[nums.size()-2]+nums[nums.size()-1])<=target)
	   	return sum; 
    for(int i=0,j,k;i<nums.size()-2;)
	{
		if((sum=nums[i]+nums[i+1]+nums[i+2])>target)
		{
			if(abs(sum-target)<abs(ret-target)) 
				ret=sum;
    	}
		else if((sum=nums[i]+nums[nums.size()-1]+nums[nums.size()-2])<target)
		{
			if(abs(sum-target)<abs(ret-target)) 
				ret=sum;
    	}
		else
		{
			j=i+1;
			k=nums.size()-1;
			while(j<k)
			{
				if((sum=nums[i]+nums[j]+nums[k])==target) 
					return target;
     			else if(sum>target)
			 	{
				 	if(abs(sum-target)<abs(ret-target))
					 	ret=sum;
       				do
					{
						k--;
					}while(k>j&&nums[k]==nums[k+1]);
     			}
				else
				{
    				if(abs(sum-target)<abs(ret-target))
						ret = sum;
      				do
					{
						j++;
					}while (k>j&&nums[j]==nums[j-1]);
     			}
        	}
       	}
        do
		{
			i++;
		}while(i<nums.size()&&nums[i]==nums[i-1]);
	}
	return ret;
}