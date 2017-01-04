#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
	int len=nums.size();
	int s=nums[0];
	for(int i=1;i<len;++i)
		s=s^nums[i];
	return s;
}

int main()
{
	vector<int> v;
	v.push_back(11);
	v.push_back(13);
	v.push_back(12);
	v.push_back(15);
	v.push_back(11);
	v.push_back(13);
	v.push_back(12);
	cout<<singleNumber(v);
}