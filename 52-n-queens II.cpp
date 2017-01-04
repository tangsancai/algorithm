#include<iostream>
#include<vector> 
#include<string>
using namespace std;
int num=0;
void gg(int n,int l,vector< vector<bool> > &q)
{
	int i,j,k;
	if(l>=n)
	{
		++num;
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

int totalNQueens(int n)
{
	vector<bool> q(n,false);
	vector< vector<bool> > tmp(n,q);
	gg(n,0,tmp);
	return num;
}
int main()
{
	int n=4;
	cout<<totalNQueens(n);	
}