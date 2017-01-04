#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int dp[1005][1005];
int b[1005][1005];
string st="";
void shows(string &s,int i,int j)
{
	if(i==0||j==0)
	{
		return;
	}
	if(b[i][j]==1)
	{
		st+=s[i-1];//！！！注意此处的下标要与传进来的s对应起来。 
		shows(s,i-1,j-1);
	}
	else if(b[i][j]==2)
	{
		shows(s,i-1,j);
	}
	else if(b[i][j]==3)
	{
		shows(s,i,j-1);
	}
}
string longestPalindrome(string s)
{
	string s1="";
	int len=s.size();
	for(int i=len-1;i>=0;--i)
	{
		s1+=s[i];
	}	
	memset(dp,0,sizeof(dp));
	memset(b,0,sizeof(b));
	for(int i=0;i<len;++i)
	{
		for(int j=0;j<len;++j)
		{
			if(s[i]==s1[j])
			{
				dp[i+1][j+1]=dp[i][j]+1;
				b[i+1][j+1]=1;
			}
			else
			{
				if(dp[i][j+1]>dp[i+1][j])
				{
					dp[i+1][j+1]=dp[i][j+1];
					b[i+1][j+1]=2;
				}
				else
				{
					dp[i+1][j+1]=dp[i+1][j];
					b[i+1][j+1]=3;
				}
			}
		}
	}
	shows(s,len,len);
	return st;
}

int main()
{
	string str="aaabaaaa";
	cout<<longestPalindrome(str);
}