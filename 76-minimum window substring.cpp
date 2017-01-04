#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	char ab;
	int pos;
	Node(char x,int y):ab(x),pos(y){}
}; 
/*//超时 
string minWindow(string s, string t)
{
	int lent=t.size();
	int lens=s.size();
	map<char,int> m;
	for(int i=0;i<lent;++i)
	{
		int tmp=0;
		if(m.count(t[i])>0)
			tmp=m[t[i]];
		m[t[i]]=++tmp;	
	}	
	vector<Node> pos;
	for(int i=0;i<lens;++i)
		if(m.count(s[i])>0)
		{
			Node tmp(s[i],i);
			pos.push_back(tmp);
		}
	int lenp=pos.size();
	int num=0;
	vector<Node> q;
	string str="";
	for(int i=0;i<lenp;++i)
	{
		if(m[pos[i].ab]>0)//不够数就入队 
		{
			++num;
			--m[pos[i].ab];
			q.push_back(pos[i]);
		}
		else//够数，进一个出一个 
		{
			for(int j=0;j<q.size();++j)
				if(q[j].ab==pos[i].ab)
				{
					q.erase(q.begin()+j);
					break;
				}
			q.push_back(pos[i]);
		}
		if(num==lent)
		{
			string strtmp=s.substr(q.front().pos,q.back().pos-q.front().pos+1);
			if(str=="")
				str=strtmp;
			else
				str=str.size()<strtmp.size()?str:strtmp;
		}
	}
	return str;
}*/
/*
string minWindow(string s, string t)
{
	int M=t.size();
	int src[128]={0},target[128]={0};
	for (auto item : t) 
		target[item]++;
    int cur_len=0,min_len=INT_MAX,valid_count=0;
	string result="";
    char ch;
    int i=0,j=0;
    for (;i<s.size();i++) 
	{
		ch=s[i];
        if(src[ch]<target[ch]&&target[ch]>0)
			valid_count++;
        cur_len++;
        src[ch]++;
        ch=s[j];
        while(target[ch]==0||src[ch]>target[ch])
		{
			src[ch]--;
			j++;
			cur_len--;
			ch=s[j];
		}
        if(cur_len<min_len&&valid_count>=M)
		{
			min_len=cur_len;
   			result=s.substr(i-cur_len+1, cur_len);
      	}
   	}
    return result;
}*/