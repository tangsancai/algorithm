#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s)
{
	int len=s.size();
	if(len==0)
		return true;
	stack<char> st;
	for(int i=0;i<len;++i)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{'||st.empty())
			st.push(s[i]);
		else if((s[i]==')'&&st.top()=='(')||(s[i]==']'&&st.top()=='[')||(s[i]=='}'&&st.top()=='{'))
			st.pop();
		else 
			st.push(s[i]);
	}
	return st.empty();
}

int main()
{
	cout<<isValid("[])");
}