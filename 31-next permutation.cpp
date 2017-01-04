#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool turnnumber(vector<int> &nums,vector<int> &minnv)
{
	int len=nums.size();
	for(int i=0;i<len;++i)
		if(nums[i]<minnv[i])
			return true;
		else if(nums[i]>minnv[i])
			return false; 
	return false;
}
void nextPermutation(vector<int>& nums)
{
	int len=nums.size();
	vector<int> minnv;
	bool flag=false;
	for(int i=len-1;i>=0;--i)
	{
		for(int j=i-1;j>=0;--j)
			if(nums[i]>nums[j])
			{
				vector<int> tmp=nums;
				swap(nums[i],nums[j]);
				sort(nums.begin()+j+1,nums.end());
				if(minnv.size()==0||turnnumber(nums,minnv))
				{
					flag=true;
					minnv=nums;	
				}
				nums=tmp;
				break;
			}
	}	
	if(flag)
	{
		nums=minnv;
		return;
	}
	sort(nums.begin(),nums.end());
}
int main()
{
	int n;
	cin>>n;
	vector<int> t;
	for(int i=0;i<n;++i)
	{
		int tmp;
		cin>>tmp;
		t.push_back(tmp);
	}
	nextPermutation(t);
	for(int i=0;i<n;++i)
	{
		cout<<t[i]<<" ";
	}
} 