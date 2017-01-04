#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool cmp(int a,int b)
{
	return a>b;
}
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	vector<int> nums2=nums;
	vector<int> res2;
	int maxlen2=0;
	sort(nums2.begin(),nums2.end());
	
	int len=nums.size();
	vector<int> res;
	int maxlen=0;
	sort(nums.begin(),nums.end(),cmp);
	
	for(int i=0;i<len;i++)
	{
		vector<int> tmp;
		vector<int> tmp2;
		
		int n=nums[i];
		int n2=nums2[i];
		
		tmp.push_back(nums[i]);
		tmp2.push_back(nums2[i]);
		
		for(int j=i+1;j<len;j++)
		{
			if(n%nums[j]==0)
			{
				tmp.push_back(nums[j]);
				n=nums[j];
			}
			if(nums2[j]%n2==0)
			{
				tmp2.push_back(nums2[j]);
				n2=nums2[j];
			}
		}
		
		int tmplen=tmp.size();
		int tmp2len=tmp2.size();
		if(tmplen>maxlen)
		{
			maxlen=tmplen;
			res=tmp;
		}
		if(tmp2len>maxlen2)
		{
			maxlen2=tmp2len;
			res2=tmp2;
		}
	}
	sort(res.begin(),res.end());
	sort(res2.begin(),res2.end());
	if(res.size()>res2.size())
	{
		return res;
	}
	return res2;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(72);
	vector<int>tmp=largestDivisibleSubset(nums);
	for(int i=0;i<tmp.size();i++)
	{
		cout<<tmp[i]<<"\t";
	}
	return 0;
}