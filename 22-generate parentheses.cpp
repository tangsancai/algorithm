#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<stack>
using namespace std;
set<string> se;
bool isok(string str)
{
	stack<char> s;
	int len=str.size();
	for(int i=0;i<len;++i)
	{
		if(s.empty())
			s.push(str[i]);
		else if(s.top()=='('&&str[i]==')')
			s.pop();
		else
			s.push(str[i]);
	}	
	return s.empty();
}
bool judge(string str,int n)
{
	int i1=0,i2=0;
	int len=str.size();
	for(int i=0;i<len;++i)
		if(str[i]=='(')
			++i1;
		else
			++i2;
	if(i1>n||i2>n)	return false;
	return i1>=i2;
}
void generate(int level,int &n,string str)
{
	if(level>=n&&isok(str))
	{
		se.insert(str);
		return;
	}
	for(int i=0;i<=1;++i)
	{
		string stmp=str+(i==0?"(":")");
		if(judge(stmp,n/2))
			generate(level+1,n,stmp);
	}
}
vector<string> generateParenthesis(int n)
{
	vector<string> v;
	string str="";
	int len=2*n;
	generate(0,len,str);
	for(set<string>::iterator it=se.begin();it!=se.end();++it)
		v.push_back(*it);
	return v; 
}
int main()
{
	vector<string> v=generateParenthesis(5);
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl;
}