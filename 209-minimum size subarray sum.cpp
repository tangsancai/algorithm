#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
	int len=nums.size();
	int start=0;
	int end=0;
	int minn=INT_MAX;
	int sum=0;
	while(end<len&&start<len)
	{
		sum+=nums[end];
		while(sum>=s)
		{
			if((end-start+1)<minn)
				minn=(end-start+1);
			sum-=nums[start++];
		}
		++end;
	}
	return minn==INT_MAX?0:minn;
} 
int main()
{
	vector<int> v;
	int tmp;
	while(cin>>tmp)
		v.push_back(tmp);
	cout<<minSubArrayLen(7,v);
}