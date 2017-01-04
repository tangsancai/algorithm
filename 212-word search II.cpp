#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;
/*
//³¬Ê± 
bool isin(vector< vector<char> >& board,string &word,int l,pair<int,int> pos)
{
	if(l>=word.size())
		return true;
	bool tag=false;
	if(pos.first-1>=0&&board[pos.first-1][pos.second]==word[l])
	{
		board[pos.first-1][pos.second]='.';
		pair<int,int> p(pos.first-1,pos.second);
		tag|=isin(board,word,l+1,p);
		board[pos.first-1][pos.second]=word[l];
	}
	if(pos.first+1<board.size()&&board[pos.first+1][pos.second]==word[l])
	{
		board[pos.first+1][pos.second]='.';
		pair<int,int> p(pos.first+1,pos.second);
		tag|=isin(board,word,l+1,p);
		board[pos.first+1][pos.second]=word[l];
	}
	if(pos.second-1>=0&&board[pos.first][pos.second-1]==word[l])
	{
		board[pos.first][pos.second-1]='.';
		pair<int,int> p(pos.first,pos.second-1);
		tag|=isin(board,word,l+1,p);
		board[pos.first][pos.second-1]=word[l];
	}
	if(pos.second+1<board[0].size()&&board[pos.first][pos.second+1]==word[l])
	{
		board[pos.first][pos.second+1]='.';
		pair<int,int> p(pos.first,pos.second+1);
		tag|=isin(board,word,l+1,p);
		board[pos.first][pos.second+1]=word[l];
	}
	return tag;
}
vector<string> findWords(vector< vector<char> >& board, vector<string>& words)
{
	vector<string> v;
	if(board.size()==0||words.size()==0)
		return v;
	sort(words.begin(),words.end());
	vector<string> tmpt;
	tmpt.push_back(words[0]);
	for(int i=1;i<words.size();++i)
		if(words[i]!=words[i-1])
			tmpt.push_back(words[i]);
	words=tmpt;
	for(int i=0;i<words.size();++i)
	{
		bool tag=false;
		for(int i1=0;i1<board.size();++i1)
		{
			if(tag) break;
			for(int j1=0;j1<board[0].size();++j1)
			{
				if(tag) break;
				if(board[i1][j1]==words[i][0])
				{
					pair<int,int> p(i1,j1);
					board[i1][j1]='.';
					if(isin(board,words[i],1,p))
					{
						v.push_back(words[i]);
						tag=true;
					}
					board[i1][j1]=words[i][0];
				}
			}
		}
	}
	return v;
}*/
//×ÖµäÊ÷
class TrieNode {  
public:  
    vector<TrieNode*> child;  
    bool isIn;  
    TrieNode() : child(vector<TrieNode*>(26, NULL)), isIn(false) {}  
};  
class Trie {  
public:  
    Trie() : root(new TrieNode()) {}  
    ~Trie() {  
        delNode(root);  
    }  
    void delNode(TrieNode* n) {  
        for(int i=0; i<26; ++i) {  
            if(n->child[i]) delNode(n->child[i]);  
        }  
        delete n;  
    }  
    TrieNode* getRoot() {  
        return root;  
    }  
    void insert(string word) {  
        TrieNode* n = root;  
        for(auto ch:word) {  
            if(n->child[ch-'a'] == NULL)   
                n->child[ch-'a'] = new TrieNode();  
            n = n->child[ch-'a'];  
        }  
        n->isIn = true;  
    }  
private:  
    TrieNode* root;  
};  
  
class Solution {  
    void chkExist(vector<vector<char>>& board, TrieNode* n, vector<string>& ret, string curStr, int r, int c) {  
        n = n->child[board[r][c]-'a'];  
        if(n) {  
            curStr += board[r][c];  
            if(n->isIn) {  
                ret.push_back(curStr);  
                n->isIn = false;  
            }  
            char ch = board[r][c];  
            board[r][c] = 0;  
            if(r > 0 && board[r-1][c])   
                chkExist(board, n, ret, curStr, r-1, c);  
            if(r < board.size()-1 && board[r+1][c])   
                chkExist(board, n, ret, curStr, r+1, c);  
            if(c > 0 && board[r][c-1])   
                chkExist(board, n, ret, curStr, r, c-1);  
            if(c < board[0].size()-1 && board[r][c+1])   
                chkExist(board, n, ret, curStr, r, c+1);  
            board[r][c] = ch;  
        }  
    }  
public:  
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {  
        vector<string> ret;  
        int row = board.size();  
        if(!row) return ret;  
        int col = board[0].size();  
        if(!col) return ret;  
          
        Trie t;  
        for(auto s:words) t.insert(s);  
          
        for(int i=0; i<row; ++i) {  
            for(int j=0; j<col; ++j) {  
                chkExist(board, t.getRoot(), ret, "", i, j);  
            }  
        }  
          
        return ret;  
    }  
};  
int main()
{
	vector< vector<char> > board(1,vector<char>(2));
	board[0][0]='a';
	board[0][1]='b';
	vector<string> v;
	v.push_back("ba");
/*	board[0][0]='o';
	board[0][1]='a';
	board[0][2]='a';
	board[0][3]='n';
	board[1][0]='e';
	board[1][1]='t';
	board[1][2]='a';
	board[1][3]='e';
	board[2][0]='i';
	board[2][1]='h';
	board[2][2]='k';
	board[2][3]='r';
	board[3][0]='i';
	board[3][1]='f';
	board[3][2]='l';
	board[3][3]='v';
	vector<string> v;
	v.push_back("oath");
	v.push_back("pea");
	v.push_back("eat");
	v.push_back("rain");*/
	
	vector<string> tmp=findWords(board,v);
	for(int i=0;i<tmp.size();++i)
		cout<<tmp[i]<<endl; 
}