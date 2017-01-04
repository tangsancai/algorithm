#include<iostream>
#include<stack>
#include<utility>
using namespace std;
//回溯，一个用例超时 
bool isInterleave(string s1, string s2, string s3)
{
	stack< pair<int,int> > st;
	pair<int,int> tmp;
	tmp.first=-1,tmp.second=-1;
	st.push(tmp);
	int lens1=s1.size(),lens2=s2.size(),lens3=s3.size();
	if(lens1+lens2!=lens3)
		return false;
	int k=0;
	int i,j;
	while(k<lens3&&!st.empty())
	{
		tmp=st.top();
		st.pop();
		i=tmp.first;
		j=tmp.second;
		k=i+j+2;
		if(i+1<lens1&&s1[i+1]==s3[k])
		{
			tmp.first=i+1;
			tmp.second=j;
			st.push(tmp);
		}
		if(j+1<lens2&&s2[j+1]==s3[k])
		{
			tmp.first=i;
			tmp.second=j+1;
			st.push(tmp);
		}
	}
	if(k<lens3)
		return false;
	return true;
}
//DP
bool isInterleave1(string s1, string s2, string s3)
{
	int lens1=s1.size(),lens2=s2.size(),lens3=s3.size();
	if(lens1+lens2!=lens3)
		return false;
    else if(lens1==0&&lens2==0&&lens3==0) 
		return true;
    else if(s1[0]!=s3[0]&&s2[0]!=s3[0]) 
		return false;
    int dp[lens1+1][lens2+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=lens1;++i)
        if(s1[i-1]==s3[i-1])
			dp[i][0]=1;
        else
			break;
    for(int j=1;j<=lens2;++j)
        if(s2[j-1]==s3[j-1])
			dp[0][j]=1;
        else
			break;   
    int k=0;
    for(int i=1;i<=lens1;++i)
        for(int j=1;j<=lens2;++j)
		{
            k=i+j;
            if(s3[k-1]==s1[i-1])
				dp[i][j]=dp[i-1][j]||dp[i][j];
            if(s3[k-1]==s2[j-1])
				dp[i][j]=dp[i][j-1]||dp[i][j];
        }
    return dp[lens1][lens2];
}
int main()
{
	string s1="aabcc";
	string s2="dbbca";
	string s3="aadbbcbcac";
	
	string s11="bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	string s22="babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	string s33="babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	
	cout<<isInterleave1(s1,s2,s3);
}