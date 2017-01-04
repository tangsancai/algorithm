#include<iostream>
#include<vector>
#include<utility>
using namespace std;
/*
//²¢²é¼¯ 
int numIslands(vector< vector<char> >& grid)
{
	int lenv=grid.size();
	if(grid.size()==0)
		return 0;
	int lenh=grid[0].size();
	vector< vector< pair<int,int> > > v(lenv, vector< pair<int,int> >(lenh,pair<int,int>(-1,-1)));
	v[0][0]=grid[0][0]=='1'?pair<int,int>(0,0):pair<int,int>(-1,-1);
	for(int i=1;i<grid[0].size();++i)
		if(grid[0][i]=='1')
		{
			if(grid[0][i-1]=='1')
				v[0][i]=v[0][i-1];
			else
				v[0][i]=pair<int,int>(0,i);
		}
	for(int i=1;i<grid.size();++i)
		if(grid[i][0]=='1')
		{
			if(grid[i-1][0]=='1')
				v[i][0]=v[i-1][0];
			else
				v[i][0]=pair<int,int>(i,0);
		}
	for(int i=1;i<grid.size();++i)
		for(int j=1;j<grid[0].size();++j)
			if(grid[i][j]=='1')
			{
				if(grid[i-1][j]=='1'&&grid[i][j-1]=='0')
					v[i][j]=v[i-1][j];
				else if(grid[i][j-1]=='1'&&grid[i-1][j]=='0')
					v[i][j]=v[i][j-1];
				else if(grid[i][j-1]=='1'&&grid[i-1][j]=='1'&&v[i-1][j]==v[i][j-1])
					v[i][j]=v[i-1][j];
				else if(grid[i][j-1]=='1'&&grid[i-1][j]=='1'&&v[i-1][j]!=v[i][j-1])
				{
					for(int k1=0;k1<=i-1;++k1)
						for(int k2=0;k2<=j;++k2)
							if(v[k1][k2]==v[i-1][j])
								v[k1][k2]=v[i][j-1];
					v[i][j]=v[i][j-1];
				}
				else
					v[i][j]=pair<int,int>(i,j);
			} 
	int num=0;
	for(int i=0;i<grid.size();++i)
		for(int j=0;j<grid[0].size();++j)
			if(grid[i][j]=='1'&&v[i][j].first==i&&v[i][j].second==j)
				++num;
	return num;
}*//*
bool dfs(int i,int j,vector< vector<char> > &grid)
{
	if(i>=0&&i<grid.size()&&j>=0&&j<grid[i].size()&&grid[i][j]=='1')
 	{
	 	grid[i][j]='3';
	 	dfs(i-1,j,grid);
	 	dfs(i+1,j,grid);
		dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        return true;
	}
	return false;
}
int numIslands(vector< vector<char> > &grid)
{
	int num=0;
	for(int i=0;i<grid.size();i++)
    	for(int j=0;j<grid[i].size();j++)
        	if(dfs(i,j,grid))
                    num++;
	return num;
}
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector< vector<char> > &grid,int i,int j)
{
	grid[i][j]='3';
	if(i+1<grid.size()&&grid[i+1][j]=='1')
		dfs(grid,i+1,j);
	if(i-1>=0&&grid[i-1][j]=='1')
		dfs(grid,i-1,j);
	if(j+1<grid[0].size()&&grid[i][j+1]=='1')
		dfs(grid,i,j+1);
	if(j-1>=0&&grid[i][j-1]=='1')
		dfs(grid,i,j-1);
}

int numIslands(vector< vector<char> > &grid)
{
	int lenv=grid.size();
	if(lenv==0)
		return 0;
	int lenh=grid[0].size();
	int num=0;
	for(int i=0;i<lenv;++i)
		for(int j=0;j<lenh;++j)
			if(grid[i][j]=='1')
			{
				++num;
				dfs(grid,i,j);
			}
	return num; 	
}



int main()
{
	vector< vector<char> > grid(4,vector<char>(5,'0'));
	grid[0][0]='1';
	grid[0][1]='1';
	grid[0][2]='1';
	grid[0][3]='1';
	grid[1][0]='1';
	grid[1][1]='1';
	grid[1][3]='1';
	grid[2][0]='1';
	grid[2][1]='1';
	cout<<numIslands(grid)<<endl;
}
/*
[
"10110010111101011110",
"01001010111111011011",
"10010101011011100110",
"01100110111100100011",
"11010010001010111011",
"00001011001001011110",
"10111101101101110010",
"01100010010111001101",
"00001101001101001010",
"00111010101110111110",
"10101110111010101011",
"00111101110100011101",
"11100000110111011110",
"00111001001111110110",
"00011000011010011111",
"01110100111110111001",
"00001111000010000110",
"11111111110110111111",
"01001001111110101111",
"00111110001111110110"
]*/