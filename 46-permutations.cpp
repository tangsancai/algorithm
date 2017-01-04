#include<iostream>
#include<set>
#include<vector>
using namespace std;

set< vector<int> > s;
void per(vector<int>&nums,int l,vector<int> &tmp)
{
	int len=nums.size(); 
	if(l>=len)	
	{
		s.insert(tmp);
		return;		
	}
	for(int i=0;i<len;++i)
	{
		if(nums[i]!=INT_MIN)
		{
			int ttmp=nums[i];
			tmp.push_back(nums[i]);
			nums[i]=INT_MIN;
			per(nums,l+1,tmp);
			nums[i]=ttmp;
			tmp.pop_back();
		}
	}
}

vector< vector<int> > permute(vector<int>& nums)
{
	vector< vector<int> > v;
	vector<int> tmp;
	per(nums,0,tmp);
	for(set< vector<int> >::iterator it=s.begin();it!=s.end();++it)
		v.push_back(*it);
	return v;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector< vector<int> >  v=permute(nums);
//	for(int i=0;i<v.size();++i)
//	{
//		for(int j=0;j<v[i].size();++j)
//			cout<<v[i][j]<<"\t";
//		cout<<endl;
//	}
}