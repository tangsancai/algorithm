#include<iostream>
#include<vector> 
#include<string>
using namespace std;
vector< vector<string> > v;
void gg(int n,int l,vector< vector<bool> > &q)
{
	int i,j,k;
	if(l>=n)
	{
		vector<string> stmp;
		for(i=0;i<n;++i)
		{
			string tmp="";
			for(j=0;j<n;++j)
			{
				if(q[i][j])
					tmp+="Q";
				else
					tmp+=".";
			}
			stmp.push_back(tmp);
		}
		v.push_back(stmp);
		return;
	}
	for(j=0;j<n;++j)
	{
		bool flag=false;
		for(i=0;i<=l;++i)
			if(q[i][j])
			{
				flag=true;
				break;
			}
		if(flag)
			continue;
		for(i=l,k=j;i>=0&&k>=0;--i,--k)
			if(q[i][k])
			{
				flag=true;
				break;
			}
		if(flag)
			continue;
		for(i=l,k=j;i>=0&&k<n;--i,++k)
			if(q[i][k])
			{
				flag=true;
				break;
			}
		if(!flag)
		{
			q[l][j]=true;
			gg(n,l+1,q);
			q[l][j]=false;
		}
	}
}

vector< vector<string> > solveNQueens(int n)
{
	vector<bool> q(n,false);
	vector< vector<bool> > tmp(n,q);
	gg(n,0,tmp);
	return v;
}
int main()
{
	int n=4;
	solveNQueens(n);
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<n;++j)
			cout<<v[i][j]<<endl;
		cout<<endl;
	}
		
}