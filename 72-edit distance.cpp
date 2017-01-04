#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*//»ØËÝ³¬Ê± 
int minn=INT_MAX;
void gg(int v,int i,int j,string &word1,string &word2)
{
	if(i>=word1.size()&&j<word2.size())
	{
		minn=minn<word2.size()-j+v?minn:(word2.size()-j+v);
		return;	
	}
	if(i<word1.size()&&j>=word2.size())
	{
		minn=minn<word1.size()-i+v?minn:(word1.size()-i+v);
		return;	
	}
	if(i>=word1.size()&&j>=word2.size())
	{
		minn=minn<v?minn:v;
		return;	
	}
	if(word1[i]==word2[j])
		gg(v,i+1,j+1,word1,word2);
	else
	{
		++v;
		//R
		gg(v,i+1,j+1,word1,word2);
		//Dw1,Iw2
		gg(v,i+1,j,word1,word2);
		//Dw2,Iw1
		gg(v,i,j+1,word1,word2);
		
	} 
} 
int minDistance(string word1, string word2)
{
	int len1=word1.size();
 	int len2=word2.size();
 	gg(0,0,0,word1,word2);
 	return minn;
}*/
int minDistance(string word1, string word2)
{
	int len1=word1.size();
	int len2=word2.size();
	vector<int> tmp(len2+1,0);
	vector< vector<int> > dp(len1+1,tmp);
	for(int i=0;i<=len1;++i)
		dp[i][0]=i;
	for(int j=0;j<=len2;++j)
		dp[0][j]=j;
 	for(int i=1;i<=len1;++i)
		for(int j=1;j<=len2;++j)
			if(word1[i-1]==word2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				++dp[i][j];
			}
	return dp[len1][len2];
}
int main()
{
	string word1="dinitrophenylhydrazine";
	string word2="acetylphenylhydrazine";
	cout<<minDistance(word1,word2);
}