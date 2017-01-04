#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

//Ì«ÂýÁË 
string lengthOfLongestSubstring1(string s)
{
	string lstr="";
	int st=0;
	int ed=0;
	map<char,int> m;
	while(st<s.size()&&ed<s.size())
	{
		if(m.count(s[ed])<=0)
			m[s[ed]]=ed;
		else
		{
			int tmp=st;
			st=m[s[ed]]+1;
			for(int i=tmp;i<st;++i)
				m.erase(s[i]);
			m[s[ed]]=ed;
		}	
		if(ed-st+1>lstr.size())
			lstr=s.substr(st,ed-st+1);
		++ed;
	}
	return lstr;	
}
int lengthOfLongestSubstring(string s)
{
	if(s.size()==0)
		return 0;
	int lenmax=1;
	map<char,int> m;
	vector<int> len(s.size());
	m[s[0]]=0;
	len[0]=1;
	for(int i=1;i<s.size();++i)
	{
		if(m.count(s[i])<=0)
			len[i]=len[i-1]+1;
		else
			len[i]=len[i-1]+1<i-m[s[i]]?len[i-1]+1:i-m[s[i]];
		m[s[i]]=i;
		if(len[i]>lenmax)
			lenmax=len[i];
	}
	return lenmax;
}
int main()
{
	cout<<lengthOfLongestSubstring1("abba")<<endl;
	cout<<lengthOfLongestSubstring("abba")<<endl;
	//string str="";
	//cout<<str.size()<<endl;
}