#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums)
{
	int len=nums.size();  
	int maxx=len-1;
	for(int i=len-2;i>=0;--i)
		if(i+nums[i]>=maxx)  
  			maxx=i;  
  	return (maxx<=0); 	
}
int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	cout<<canJump(nums);
}