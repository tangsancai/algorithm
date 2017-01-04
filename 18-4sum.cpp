#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector< vector<int> > fourSum(vector<int>& nums, int target)
{
	vector< vector<int> >	res;
	set< vector<int> > ress;
	int len=nums.size();
	sort(nums.begin(),nums.end());
	for(int i=0;i<len;++i)
		for(int j=len-1;j>i;--j)
		{
			int left=i+1;
			int right=j-1;
			while(left<right)
			{
				int s=nums[i]+nums[j]+nums[left]+nums[right]-target;
				if(s==0)
				{
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[left]);
					tmp.push_back(nums[right]);
					tmp.push_back(nums[j]);
					ress.insert(tmp);
					do
					{
						++left;
					}while(nums[left-1]==nums[left]&&left<right);
				}
				else if(s<0)
					++left;
				else
					--right;
			}		
		}
	for(set< vector<int> >::iterator it=ress.begin();it!=ress.end();++it)
		res.push_back(*it);
	return res;
}



int main()
{
	vector<int> v;
	for(int i=0;i<200;++i)
	{
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	vector< vector<int> > s=fourSum(v,-236727523);
	for(int i=0;i<s.size();++i)
	{
		for(int j=0;j<s[i].size();++j)
			cout<<s[i][j]<<"\t";
		cout<<endl;
	}
}
//