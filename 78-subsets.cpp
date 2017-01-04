#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
set< vector<int> > s;
void isok(vector<int>& nums,int l,vector<int> &tmp)
{
	if(l>=nums.size())
	{
		s.insert(tmp);
		return;
	}
	isok(nums,l+1,tmp);
	tmp.push_back(nums[l]);
	isok(nums,l+1,tmp);
} 
vector< vector<int> > subsets(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	vector<int> tmp;
	vector< vector<int> > v;
	isok(nums,0,tmp);
	for(set< vector<int> >::iterator it=s.begin();it!=s.end();++it)
		v.push_back(*it);
	return v;
}