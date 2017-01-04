#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> v;
	map<string,int> m;
	int len=s.size();
	if(len<=10)
		return v;
	for(int i=0;i<=len-10;++i)
	{
		string str=s.substr(i,10);
		if(m.count(str)>0)
		{
			if(m[str]==1)
				v.push_back(str);
			++m[str];
			continue;
		}
		m[str]=1;
	}
	return v;
} 

int main()
{
	string str="AAAAAAAAAAA";
	vector<string> v=findRepeatedDnaSequences(str);
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl; 
}