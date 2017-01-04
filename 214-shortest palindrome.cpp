#include<iostream>
#include<string>
using namespace std;
/*
//超时 
string shortestPalindrome(string s)
{
	string res="";
	for(int i=s.size()-1;i>=0;--i)
		res+=s[i];
	int i=0;
	int maxlen=0;
	while(i<s.size())
	{
		if(s[i]==res[res.size()-1])
		{
			int i1=i,j1=res.size()-1;
			int tmplen=0;
			while(j1>=0&&i1>=0)
			{
				if(s[i1--]!=res[j1--])
					break;
				++tmplen;
			}
			if(i1<0)
				maxlen=maxlen>tmplen?maxlen:tmplen;
		}
		++i;
	}
	for(int i=maxlen;i<s.size();++i)
		res+=s[i];
	return res;
}*/
string shortestPalindrome(string s)
{
	string res="";
	for(int i=s.size()-1;i>=0;--i)
		res+=s[i];
	int n=s.size();
	int i=0;
	for(i=n;i>=0;--i)
		if(s.substr(0,i)==res.substr(n-i))//res.substr(n-i)表示从位置n-i开始截取，没有第二参数，表示截到末尾 
			break;
	return res.substr(0,n-i)+s;
}
int main()
{
	cout<<shortestPalindrome("aacecaaa");
}