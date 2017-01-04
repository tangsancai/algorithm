#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
vector<string> strv;
void backtrack(vector< vector<bool> > &dp,string &s,string stmp,int level,int &len)
{
	if(level>=len)
	{
		strv.push_back(stmp);
		return;
	}	
	for(int i=level;i<len;++i)
	{
		string ttmp=stmp;
		if(dp[level][i])
		{
			stmp+=s.substr(level,i-level+1);
			if(i!=len-1)
				stmp+=" ";
			backtrack(dp,s,stmp,i+1,len); 
		} 
		stmp=ttmp;
	}
}
vector<string> wordBreak(string s, set<string>& wordDict)
{
	int len=s.size();
	vector<bool> tmp(len+1,false);
	vector< vector<bool> > dp(len,tmp);
	tmp[0]=true;
	for(int i=0;i<len;++i)
		if(tmp[i])
			for(int j=1;i+j-1<len;++j)
				if(wordDict.count(s.substr(i,j))>0)
				{
					tmp[i+j]=true;
					dp[i][i+j-1]=true;
				}
	if(!tmp[len])
		return strv;
	string stmp="";
	backtrack(dp,s,stmp,0,len);
	return strv;	
} 


int main()
{
	string s="catsanddog";
	set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	wordBreak(s,dict);
	for(int i=0;i<strv.size();++i)
	{
		cout<<strv[i]<<endl;
	}
} 