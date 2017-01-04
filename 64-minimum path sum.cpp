#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector< vector<int> >& grid)
{
	int sum=0;
	int m=grid.size();
	if(m==0)
		return sum;
	int n=grid[0].size();
	for(int i=1;i<m;++i)
		grid[i][0]+=grid[i-1][0];
	for(int j=1;j<n;++j)
		grid[0][j]+=grid[0][j-1];
	for(int i=1;i<m;++i)
		for(int j=1;j<n;++j)
			grid[i][j]=grid[i][j]+(grid[i-1][j]<grid[i][j-1]?grid[i-1][j]:grid[i][j-1]);
	return grid[m-1][n-1];
}
int main()
{
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	vector< vector<int> > g;
	g.push_back(tmp);
	tmp[1]=1;
	g.push_back(tmp);
	cout<<minPathSum(g);
} 