#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<queue> 
using namespace std;
/*	//暴力递归求解，搜索整棵树，n!，其中很多不必要的节点都被搜索到了，深度优先 
bool wordBreak(string s, set<string>& wordDict)
{
	if(wordDict.find(s)!=wordDict.end())
		return true;
	int len=s.size();
	if(len==1)
		return false;
	for(int i=1;i<len;++i)
	{
		string stmp1="";
		string stmp2="";
		stmp1.assign(s.begin(),s.begin()+i);
		stmp2.assign(s.begin()+i,s.end());
		bool a=wordBreak(stmp1,wordDict);
		bool b=wordBreak(stmp2,wordDict);
		if(a&b)
		{
			return true;
		}
	}
	return false;
} 
*/
/*	//超时 ，广度优先 
bool wordBreak(string s, set<string>& wordDict)
{
	queue<int> q;
	int len=s.size();
	q.push(0);
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int j=i+1;j<=len;++j)
		{	
			string stmp="";
			stmp.assign(s.begin()+i,s.begin()+j);
			if(wordDict.find(stmp)!=wordDict.end())
			{
				q.push(j);
				if(j==len)
					return true;
			}	
		}
	}
	return false;
} */

bool wordBreak(string s, set<string>& wordDict)
{
	int n=s.size();
	vector<bool> dp(n+1,false); 
	dp[0]=true;
	for(int i=0;i<n;++i)
		if(dp[i])
			for(int j=1;i+j-1<n;++j)
				if(wordDict.count(s.substr(i,j))>0)
					dp[i+j]=true;
	return dp[n];
}
int main()
{
	string l="leetcode";
	set<string> w;
	w.insert("leet");
	w.insert("code");
	cout<<wordBreak(l,w);
}

