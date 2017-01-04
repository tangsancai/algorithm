#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector< vector<int> > re;
void countN(vector<int>& candidates,vector<int> &v,int target,int &sum,int len)
{
	if(sum==target)
	{
		re.push_back(v);
		return;
	}	
	if(sum>target)	
		return;
	int tt=-1;
	if(v.size()>0)
		tt=v[v.size()-1];
	for(int i=0;i<len;++i)
	{
		if(candidates[i]>=tt)
		{
			v.push_back(candidates[i]);
			sum+=candidates[i];
			countN(candidates,v,target,sum,len);
			sum-=candidates[i];
			v.pop_back();
		}
	}
}
vector< vector<int> > combinationSum(vector<int>& candidates, int target)
{
	int len=candidates.size();
	vector<int> v;
	int sum=0;
	set<int> s;
	for(int i=0;i<len;++i)
		s.insert(candidates[i]);
	vector<int> (candidates).swap(candidates);
	for(set<int>::iterator it=s.begin();it!=s.end();++it)
		candidates.push_back(*it);
	countN(candidates,v,target,sum,len);
	return re;
} 

int main()
{
	vector<int> c;
	for(int i=0;i<25;++i)
	{
		int tmp;
		cin>>tmp;
		c.push_back(tmp);
	}
	vector< vector<int> > re=combinationSum(c,74);
	for(int i=0;i<re.size();++i)
	{
		for(int j=0;j<re[i].size();++j)
			cout<<re[i][j]<<" ";
		cout<<endl;
	}
} 
//28 22 43 41 21 29 27 38 47 23 20 49 24 31 37 26 32 36 25 33 40 46 30 44 35
