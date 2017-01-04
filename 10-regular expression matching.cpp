#include<iostream>
#include<string>
#include<vector>
using namespace std;
//   '' c * a * b
// '' 1 0 1 0 1 0 
// a  0 0 0 1 1 0 
// a  0 0 0 0 1 0 
// b  0 0 0 0 0 1
bool isMatch(string s, string p)
{
	int m=s.size()+1,n=p.size()+1;
	vector< vector<bool> > is_match(m, vector<bool>(n, false));
	is_match[0][0]=true;
	for(int j=1;j<n;j++)
		if(p[j-1]=='*')
			is_match[0][j]=is_match[0][j-2];
	for(int i=1;i<m;i++)
	{
		int s_idx=i-1;
		for(int j=1;j<n;j++)
		{
			int p_idx=j-1;
			if(s[s_idx]==p[p_idx]||p[p_idx]=='.')
				is_match[i][j]=is_match[i-1][j-1];
			else if(p[p_idx]=='*')
			{
				is_match[i][j]=is_match[i][j-2];
				if (!is_match[i][j]&&(s[s_idx]==p[p_idx-1]||p[p_idx-1]=='.'))
					is_match[i][j]=is_match[i-1][j];
     		}
       	}
   }
   return is_match[s.size()][p.size()];
}