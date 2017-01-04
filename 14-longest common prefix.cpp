#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	int len=strs.size();
	if(len==0) return "";
	else if(len==1) return strs[0];
	string prefix=strs[0];
	for(int i=1;i<len;++i)
	{
		int len2=prefix.size();int j;
		for(j=0;j<len2;++j)
			if(prefix[j]!=strs[i][j])
				break;
		prefix=prefix.substr(0,j);
	}
	return prefix;
} 