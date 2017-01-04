#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
set< vector<int> > m;
void countN(vector<int>& candidates,vector<int> &v,int target,int &sum,int len)
{
	if(sum==target)
	{
		vector<int> vtmp=v;
		sort(vtmp.begin(),vtmp.end());
		m.insert(vtmp);
		return;
	}	
	if(sum>target)	
		return;
	set<int> s;
	for(int i=0;i<len;++i)
	{
		if(candidates[i]!=-1&&s.count(candidates[i])==0)
		{
			int tmp=candidates[i];
			s.insert(candidates[i]);
			v.push_back(candidates[i]);
			sum+=candidates[i];
			candidates[i]=-1;
			countN(candidates,v,target,sum,len);
			candidates[i]=tmp;
			sum-=candidates[i];
			v.pop_back();
		}
	}
}
vector< vector<int> > combinationSum2(vector<int>& candidates, int target)
{
	int len=candidates.size();
	vector<int> v;
	int sum=0;
	sort(candidates.begin(),candidates.end());
	countN(candidates,v,target,sum,len);
	vector< vector<int> > re;
	for(set< vector<int> >::iterator it=m.begin();it!=m.end();++it)
		re.push_back(*it);
	return re;
} 

int main()
{
	vector<int> c;
	c.push_back(10);
	c.push_back(1);
	c.push_back(2);
	c.push_back(7);
	c.push_back(6);
	c.push_back(1);
	c.push_back(5);
	vector< vector<int> > re=combinationSum2(c,8);
	for(int i=0;i<re.size();++i)
	{
		for(int j=0;j<re[i].size();++j)
			cout<<re[i][j]<<" ";
		cout<<endl;
	}
} 