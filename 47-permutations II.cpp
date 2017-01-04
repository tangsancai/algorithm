#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
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
   	int p=INT_MIN;
   	for(int i=0;i<len;++i)
   	{
  		if(nums[i]!=INT_MIN&&nums[i]!=p)
  		{
    		p=nums[i];
    		tmp.push_back(nums[i]);
    		nums[i]=INT_MIN;
    		per(nums,l+1,tmp);
    		nums[i]=p;
    		tmp.pop_back();
    	}
   	}
}
    
vector< vector<int> > permuteUnique(vector<int>& nums)
{
	vector< vector<int> > v;
	vector<int> tmp;
	sort(nums.begin(),nums.end());
	per(nums,0,tmp);
	for(set< vector<int> >::iterator it=s.begin();it!=s.end();++it)
		v.push_back(*it);
	return v;
}
    
int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(2);
	vector< vector<int> > v=permuteUnique(nums);
	for(int i=0;i<v.size();++i)	
	{
		for(int j=0;j<v[i].size();++j)
			cout<<v[i][j];
		cout<<endl;
	}
}