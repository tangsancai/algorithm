#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<set>
using namespace std;
bool check(vector<vector<char> > &board,int position)
{
	int row=position/9;
	int col=position%9;
	int gid;
	if(row>=0&&row<=2)
	{
		if(col>=0&&col<=2)
			gid=0;
		else if(col>=3&&col<=5)
			gid=1;
		else
			gid=2;
	}
	else if(row>=3&&row<=5)
	{
		if(col>=0&&col<=2)
			gid=3;
		else if(col>=3&&col<=5)
			gid=4;
		else
			gid=5;
	}
	else
	{
		if(col>=0&&col<=2)
			gid=6;
		else if(col>=3&&col<=5)
			gid=7;
		else
			gid=8;
	}
    for(int i = 0; i < 9; i ++)
	{
		if(i!=col&&board[row][i]==board[row][col])
			return false;
		if(i!=row&&board[i][col]==board[row][col])
        	return false;
 		int r=gid/3*3+i/3;
       	int c=gid%3*3+i%3;
    	if((r!=row||c!=col)&&board[r][c]==board[row][col])
        	return false;
  	}
  	return true;
}
bool solve(vector<vector<char> > &board,int position)
{
	if(position==81)
		return true;
	int row=position/9;
	int col=position%9;
	if(board[row][col]=='.')
	{
		for(int i=1;i<=9;i++)
		{
			board[row][col]=i+'0';
			if(check(board,position))
				if(solve(board,position+1))
					return true;
                board[row][col]='.';
     	}
    }
	else
	{
		if(solve(board,position+1))
  			return true;
  	}
  	return false;
}
void solveSudoku(vector< vector<char> > &board)
{
	solve(board,0);
}
int main()
{
	vector< vector<char> > board(9,vector<char>(9));
	vector<string> v;
	v.push_back("..9748...");
	v.push_back("7........");
	v.push_back(".2.1.9...");
	v.push_back("..7...24.");
	v.push_back(".64.1.59.");
	v.push_back(".98...3..");
	v.push_back("...8.3.2.");
	v.push_back("........6");
	v.push_back("...2759..");
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			board[i][j]=v[i][j];
		}
	}
	solveSudoku(board);
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}
}