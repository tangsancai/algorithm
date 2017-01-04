#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector< vector<string> > v;
bool isP(int st,int ed,string &s)
{
	int i,j;
	for(i=st,j=ed;i<=ed;++i,--j)
	{
		if(s[i]!=s[j])
		{
			return false;
		}
	}
	return true;
}
void getParray(vector<string> &a,int n,int &len,string &s)
{
	if(n>=len)	
	{
		v.push_back(a);
		return;
	}	
	for(int i=n;i<len;++i)
	{
		if(isP(n,i,s))
		{
			string stmp;
			stmp.assign(s.begin()+n,s.begin()+i+1);
			a.push_back(stmp);
			getParray(a,i+1,len,s);
			a.pop_back(); 
		} 
	} 
}
vector< vector<string> > partition(string s)
{
	vector<string> a;
	int len=s.size();
	getParray(a,0,len,s);
	return v;
}
int main()
{
	string s="aabad";
	partition(s);
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<v[i].size();++j)
		{
			cout<<v[i][j]<<"\t";
		}
		cout<<endl;
	}
}