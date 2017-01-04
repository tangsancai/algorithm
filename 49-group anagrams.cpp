#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

vector< vector<string> > groupAnagrams(vector<string>& strs)
{
	vector<string> s=strs;
	map<string, vector<string> > m;
	vector< vector<string> > v; 
	int len=s.size();
	for(int i=0;i<len;++i)
		sort(s[i].begin(),s[i].end());
	for(int i=0;i<len;++i)
	{
		vector<string> tmp;
		if(m.count(s[i])>0)
			tmp=m[s[i]];
		tmp.push_back(strs[i]);
		m[s[i]]=tmp;
	}
	for(map<string, vector<string> >::iterator it=m.begin();it!=m.end();++it)
		v.push_back(it->second);
	return v;
}

int main()
{
	vector<string> v;
	v.push_back("eat");
	v.push_back("tea");
	v.push_back("tan");
	v.push_back("ate");
	v.push_back("nat");
	v.push_back("bat");
	vector< vector<string> > g=groupAnagrams(v);
	for(int i=0;i<g.size();++i)
	{
		for(int j=0;j<g[i].size();++j)
			cout<<g[i][j]<<"\t";
		cout<<endl;	
	}
}