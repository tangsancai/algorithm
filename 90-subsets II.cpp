#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
set< vector<int> > s;
void add(vector<int>&nums,int l,vector<int> tmp)
{
	int len=nums.size();
	if(l>=len)
	{
		s.insert(tmp);
		return;
	}		
	add(nums,l+1,tmp);
	tmp.push_back(nums[l]);
	add(nums,l+1,tmp);
} 
vector< vector<int> > subsetsWithDup(vector<int>& nums)
{
	vector<	vector<int> > v;
	vector<int> tmp;
	sort(nums.begin(),nums.end());
	add(nums,0,tmp);
	for(set< vector<int> >::iterator it=s.begin();it!=s.end();++it)
		v.push_back(*it);
	return v;
} 

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	vector< vector<int> > v=subsetsWithDup(nums);
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<v[i].size();++j)
			cout<<v[i][j]<<"\t";
		cout<<endl;	
	}
	return 0;
} 