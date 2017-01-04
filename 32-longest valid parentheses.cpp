#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool isok(string str)
{
	int len=str.size();
	stack<char> st;
	for(int i=0;i<len;++i)
		if(st.empty())
			st.push(str[i]);
		else if(st.top()=='('&&str[i]==')')
			st.pop();
		else	
			st.push(str[i]);
	return st.empty();
}
int longestValidParentheses(string s)
{
	int res=0,l=0;
	stack<int> si;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]=='(')
			si.push(i);
		else
		{
			if(si.empty())
				l=i+1;
			else
			{
				si.pop();
				if(si.empty())
					res=max(res,i-l+1);
				else
					res=max(res,i-si.top());
			}
		}
	}
	return res;
}

int main()
{
	cout<<longestValidParentheses(")))()(()))())(())()())(()((())))())))))(())))(()()))(())())())))(()))()))((((()())))))()()))(()((())((())())()()()()((()((((())))(()))(()()()))))(()((((()))(((((()))())()))(((");
}