#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
	int one = 0, two = 0;  
 	int n=nums.size();
  	for (int i = 0; i < n; i++)  
   	{
	   two |= nums[i] & one;
	   one ^= nums[i];
	   int three = one & two;
	   one &= ~three;
	   two &= ~three;
   	}  
    return one; 
}