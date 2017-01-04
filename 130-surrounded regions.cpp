#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct POS
{
    int x;
    int y;
    POS(int newx,int newy):x(newx),y(newy){}
};
void solve(vector< vector<char> > &board)
{
	if(board.empty()||board[0].empty())
		return;
	int m=board.size();
	int n=board[0].size();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]=='O')
			{
				if(i==0||i==m-1||j==0||j==n-1)
					bfs(board,i,j,m,n);
            }
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j ++)
		{
			if(board[i][j]=='O')	board[i][j]='X';
   			else if(board[i][j]=='*')	board[i][j]='O';
   		}
}
void bfs(vector< vector<char> > &board,int i,int j,int m,int n)
    {
        queue<POS*> q;
        board[i][j]='*';
        POS* pos=new POS(i,j);
        q.push(pos);
        while(!q.empty())
        {
            POS* front=q.front();
            q.pop();
            if(front->x>0&&board[front->x-1][front->y]=='O')
            {
                POS* up=new POS(front->x-1,front->y);
                q.push(up);
                board[up->x][up->y]='*';
            }
            if(front->x<m-1&&board[front->x+1][front->y]=='O')
            {
                POS* down=new POS(front->x+1,front->y);
                q.push(down);
                board[down->x][down->y]='*';
            }
            if(front->y>0&&board[front->x][front->y-1]=='O')
            {
                POS* left=new POS(front->x,front->y-1);
                q.push(left);
                board[left->x][left->y]='*';
            }
            if(front->y<n-1&&board[front->x][front->y+1]=='O')
            {
                POS* right=new POS(front->x,front->y+1);
                q.push(right);
                board[right->x][right->y]='*';
            }
        }
    }
/*
//递归实现的DFS，leetcode显示Runtime Error 爆栈 
bool mark(vector< vector<char> >& board,int i,int j)
{
	if(i==0||i==board.size()-1||j==0||j==board[0].size()-1)
		return false;
	board[i][j]='3';
	bool tag=true;
	if(i-1>=0&&board[i-1][j]=='O')
		tag|=mark(board,i-1,j);
	if(i+1<board.size()&&board[i+1][j]=='O')
		tag|=mark(board,i+1,j);
	if(j-1>=0&&board[i][j-1]=='O')
		tag|=mark(board,i,j-1);
	if(j+1<board[0].size()&&board[i][j+1]=='O')
		tag|=mark(board,i,j+1);
	return tag;
}
void solve(vector< vector<char> >& board)
{
	int m=board.size();
	if(m==0)
		return;
	int n=board[0].size();
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			if(board[i][j]=='O')
			{
				if(mark(board,i,j))
				{
					for(int i=0;i<board.size();++i)
						for(int j=0;j<board[0].size();++j)
							if(board[i][j]=='3')
								board[i][j]='X';
				}
				else
				{
					for(int i=0;i<board.size();++i)
						for(int j=0;j<board[0].size();++j)
							if(board[i][j]=='3')
								board[i][j]='O';
				}
			}
}
*/
int main()
{
	vector< vector<char> > board(4,vector<char>(4));
	vector<string> tmp;
	tmp.push_back("XXXX");
	tmp.push_back("XOOX");
	tmp.push_back("XXOX");
	tmp.push_back("XOXX");
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			board[i][j]=tmp[i][j];
	solve(board);
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}	
}
