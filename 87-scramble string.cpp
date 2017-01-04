#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isScramble(string s1, string s2)//ÈË¼ÒµÄDP 
{
	int len_s1=s1.length();
	int len_s2=s2.length();    
	if(len_s1!=len_s2)
		return false;
	vector< vector< vector<bool> > > dp(len_s1,vector< vector<bool> >(len_s1,vector<bool>(len_s1+1,false)));
	for(int i=0;i<len_s1;i++)
		for(int j=0;j<len_s2;j++)
			dp[i][j][1]=(s1[i]==s2[j]);
	for(int len=2;len<=len_s1;len++)
	 	for(int i=0;i<len_s1-len+1;i++)
		   	for(int j=0;j<len_s2-len+1;j++)
				for(int k=1;k<len;k++)
					if(dp[i][j][k]&&dp[i+k][j+k][len-k])
					{
						dp[i][j][len]=true;
						break;
					}
					else if(dp[i][j+len-k][k]&&dp[i+k][j][len-k])
     				{
					 	dp[i][j][len]=true;
       					break;
            		}
	return dp[0][0][len_s1];
}

bool isScramble(string s1,string s2)
{
	if(s1 == s2)
		return true;
  	if(s1.size() != s2.size())
        return false;  
    vector<int> count(26, 0);
    for(int i = 0; i < s1.size(); i ++)
    {
    	count[s1[i]-'a'] ++;
     	count[s2[i]-'a'] --;
    }
    for(int i = 0; i < 26; i ++)
		if(count[i] != 0)
			return false;
   	for(int i = 1; i < s1.size(); i ++)
    	if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
      ||(isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i))))
        	return true;
    return false;
}