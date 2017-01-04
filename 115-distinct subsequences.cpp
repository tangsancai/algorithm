#include<iostream>
#include<string>
using namespace std;
//t="rabbit" s="rabbbit"  dp[3][4]=2表示子串的前3位"rab"在母串的前4位"rabb"中有2中取法 
//假设s的第j个字符和t的第i个字符不相同，那么就意味着dp[i][j]的值跟dp[i][j-1]是一样的，
//前面该是多少还是多少，而第j个字符的加入也不会多出来任何可行结果。
//如果s的第j个字符和t的第i个字符相同，那么所有dp[i-1][j-1]中满足的结果都会成为新的满足的序列，
//当然dp[i][j-1]的也仍是可行结果，所以dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
int numDistinct(string s, string t)
{
	int len0=t.size();
	int len1=s.size();
	if(len0==0||len1==0)
	{
		return 0;
	}
	if(len1<len0)
	{
		return 0;
	}
	vector< vector<int> > dp;
	vector<int> tmp;
	for(int i=0;i<=len1;i++)
	{
		tmp.push_back(0);
	}
	for(int i=0;i<=len0;i++)
	{
		dp.push_back(tmp);
	}
	for(int i=0;i<=len1;i++)
	{
		dp[0][i]=1;
	}
	for(int i=1;i<=len0;i++)
	{
		for(int j=1;j<=len1;j++)
		{
			if(s[j-1]==t[i-1])
			{
				dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
				//dp[i-1][j-1]：在母串S的前j-1的串中，子串T的前i-1的串有dp[i-1][j-1]种变法，而t[i]==s[j]所以...（最后一个字符用的是s[j]） 
				//还要加上dp[i][j-1]最后一个字符用的不是s[j] 
			}
			else
			{
				dp[i][j]=dp[i][j-1];
			}
		} 
	}
	return dp[len0][len1];
}