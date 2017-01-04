#include<iostream>
#include<string>
#include<vector>
using namespace std;

int numDecodings(string s)
{
	int len=s.size();
	vector<int> dp(4000,0);
	if(len==0)
		return 0;
	if(s[0]-'0'!=0)
		dp[0]=1;
	if(len==1)
		return dp[0];
	if(s[1]=='0'&&s[0]=='0')
		return 0;
	int	sum=(s[0]-'0')*10+(s[1]-'0');
	if(s[1]=='0'&&sum>27)
		return 0;
	else if(s[1]=='0'&&sum<27)
		dp[1]=1;
	else if(s[1]!='0')
	{
		dp[1]=dp[0];
		if(10<sum&&sum<=26)
			++dp[1];
	}	
	for(int i=2;i<len;++i)
	{
		if(s[i-1]=='0'&&s[i]=='0')
			return 0;
		sum=(s[i-1]-'0')*10+(s[i]-'0');
		if(s[i]=='0'&&sum>27)
			return 0;
		else if(s[i]=='0'&&sum<27)
			dp[i]=dp[i-2];
		else if(s[i]!='0')
		{
			dp[i]=dp[i-1];
			if(10<sum&&sum<=26)
				dp[i]+=dp[i-2];
		}	
	}	
	return dp[len-1];
}
int main()
{
	string s="301";
	cout<<numDecodings(s);
}