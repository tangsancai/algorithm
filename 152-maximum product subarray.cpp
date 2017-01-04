#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
	int n=nums.size();
    if (n==0)
        return 0;
    int max_product=nums[0];
    int cur_max=nums[0];
    int cur_min=nums[0];
	int tmp1;
    int tmp2;
    for (int i=1;i<n;i++)
    {
        tmp1=cur_max*nums[i];
        tmp2=cur_min*nums[i];
        cur_max=max(tmp1,nums[i]);
        cur_max=max(tmp2,cur_max);
        cur_min=min(tmp2,nums[i]);
        cur_min=min(tmp1,cur_min);
        max_product=max(max_product,cur_max);
    }
    return max_product;
}

int main()
{
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(-2);
	nums.push_back(4);
//	nums.push_back(0);
	cout<<maxProduct(nums);
}