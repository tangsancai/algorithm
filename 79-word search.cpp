#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool flag=false;
void isexist(vector< vector<char> >& board, string &word,int posi,int posj,int l,vector< vector<bool> > &ist)
{
	if(flag)
		return;
	if(l>=word.size())
	{
		flag=true;
		return;
	}
	if(posj-1>=0&&ist[posi][posj-1]&&board[posi][posj-1]==word[l])
	{
		if(l==word.size()-1)
		{
			flag=true;
			return;
		}
		ist[posi][posj-1]=false;
		isexist(board,word,posi,posj-1,l+1,ist);
		ist[posi][posj-1]=true;
		
	}	
	if(posj+1<board[0].size()&&ist[posi][posj+1]&&board[posi][posj+1]==word[l])
	{
		if(l==word.size()-1)
		{
			flag=true;
			return;
		}
		ist[posi][posj+1]=false;
		isexist(board,word,posi,posj+1,l+1,ist);
		ist[posi][posj+1]=true;
	}	
	if(posi-1>=0&&ist[posi-1][posj]&&board[posi-1][posj]==word[l])
	{
		if(l==word.size()-1)
		{
			flag=true;
			return;
		}
		ist[posi-1][posj]=false;
		isexist(board,word,posi-1,posj,l+1,ist);
		ist[posi-1][posj]=true;
	}	
	if(posi+1<board.size()&&ist[posi+1][posj]&&board[posi+1][posj]==word[l])
	{
		cout<<"right"<<endl;
		if(l==word.size()-1)
		{
			flag=true;
			return;
		}
		ist[posi+1][posj]=false;
		isexist(board,word,posi+1,posj,l+1,ist);
		ist[posi+1][posj]=true;
	}	
}

bool exist(vector< vector<char> >& board, string word)
{
	int num=board.size();
	if(num==0)
		return false;
	num*=board[0].size();
	if(word.size()>num)
		return false;
	if(word.size()==0)
		return true;
		
	for(int i=0;i<board.size();++i)
		for(int j=0;j<board[i].size();++j)
		{
			if(word[0]==board[i][j])
			{	
				vector<bool> tmp(board[0].size(),true);
				vector< vector<bool> > ist(board.size(),tmp);
				ist[i][j]=false;
				isexist(board,word,i,j,1,ist);
				if(flag)
					return flag;
			}	
		}
	return flag;
}

int main()
{
	vector< vector<char> > b;
	string w="aa";
	vector<char> c;
	c.push_back('a');
	c.push_back('a');
	b.push_back(c);
/*	c.push_back('A');
	c.push_back('B');
	c.push_back('C');
	c.push_back('E');
	b.push_back(c);
	c[0]='S'; 
	c[1]='F'; 
	c[2]='C'; 
	c[3]='S'; 
	b.push_back(c);
	c[0]='A'; 
	c[1]='D'; 
	c[2]='E'; 
	c[3]='E'; 
	b.push_back(c);*/
	cout<<exist(b,w);
}