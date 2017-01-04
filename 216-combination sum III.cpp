#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > v;
void backtrack(int l,int k,int i,int n,vector<int> tmp)
{
	if(l>=k)
	{
		if(n==0)
			v.push_back(tmp);
		return;
	}	
	for(int j=i;j<=9;++j)
	{
		tmp.push_back(j);
		backtrack(l+1,k,j+1,n-j,tmp);
		tmp.pop_back();
	}
}
vector< vector<int> > combinationSum3(int k, int n)
{
	if(n<((1+k)*k/2)||n>(9-k+1+9)*k/2)
		return v;
	vector<int> tmp;
	backtrack(0,k,1,n,tmp);
	return v;		
}

int main()
{
	combinationSum3(3,9);
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<v[i].size();++j)
			cout<<v[i][j]<<"\t";
		cout<<endl;
	} 
}