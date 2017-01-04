#include<iostream> 
#include<vector>
using namespace std;

vector< vector<int> > generateMatrix(int n)
{
	vector<int> tmp(n,-1);
	vector< vector<int> > v(n,tmp);
	if(n==0)
		return v;
	int times=0;
	int i=0,j=0;
	int k=0;
	while(1)
	{
		bool flag=false;
		switch(times%4)
		{
			case 0:
					for(;j<n-times/4-1;++j)
					{
						flag=true;
						if(v[i][j]==-1)
							v[i][j]=++k;
					}
					++times;
					break;
			case 1:
					for(;i<n-times/4-1;++i)
					{
						flag=true;
						if(v[i][j]==-1)
							v[i][j]=++k;
					}
					++times;
					break;
			case 2:
					for(;j>times/4;--j)
					{
						flag=true;
						if(v[i][j]==-1)
							v[i][j]=++k;
					}
					++times;
					break;
			case 3:
					for(;i>times/4;--i)
					{
						flag=true;
						if(v[i][j]==-1)
							v[i][j]=++k;
					}
					++times;
					i=times/4;
					j=times/4;
					break;
		}	
		if(!flag)
			break;
	}
	if(n*n!=k)
		for(int i1=0;i1<n;++i1)
			for(int j1=0;j1<n;++j1)
				if(v[i1][j1]==-1)
					v[i1][j1]=++k;
	return v;
}

int main()
{
	
	vector< vector<int> >tmp=generateMatrix(3);
	for(int i=0;i<tmp.size();++i)
	{
		for(int j=0;j<tmp[i].size();++j)
			cout<<tmp[i][j]<<"\t";
		cout<<endl;
	}
}