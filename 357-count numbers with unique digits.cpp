#include<iostream>
#include<vector>
using namespace std;
//不采用int n=xxx遍历是怕int数据溢出 
int sum=0;
void backtracking(int n,vector<int> &nums)
{
	int len=nums.size();
	if(len>=10||len>=n)
	{
		return;
	}
	for(int i=0;i<10;i++)
	{
		int flag=0;
		for(int j=0;j<len;j++)
		{
			if(nums[j]==i)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			nums.push_back(i);
			sum++;
			backtracking(n,nums);
			nums.pop_back();
		}
	}
}

int countNumbersWithUniqueDigits(int n)
{
	if(n==0)
 	{
	 	return 1;        
  	}
	vector<int> nums;
	sum=10;
	for(int i=1;i<10;i++)
	{
		nums.push_back(i);
		backtracking(n,nums);
		nums.pop_back();
	}
	return sum;
} 

int main()
{
	cout<<countNumbersWithUniqueDigits(3);
}