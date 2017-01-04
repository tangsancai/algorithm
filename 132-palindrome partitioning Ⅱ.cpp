#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isP(string &s,int start,int end)
{
	while(start<end)
	{
		if(s[start++]!=s[end--])
		{
			return false;
		}
	}
	return true;
}

int minCut(string s)
{
	int len=s.size();
	int num=0;
	int i=0;
	int j=len-1;
	while(j>=i)
	{
		if(isP(s,i,j))
		{
			++num;
			i=j+1;	
			j=len-1;
		}
		else
		{
			--j;
		}
	}
	int num2=0;
	i=len-1;
	j=0;
	while(j<=i)
	{
		if(isP(s,j,i))
		{
			++num2;
			i=j-1;
			j=0;	
		}
		else
		{
			++j;
		}
	}
	return num<num2?num-1:num2-1;
}

int main()
{
	cout<<minCut("adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece");
}