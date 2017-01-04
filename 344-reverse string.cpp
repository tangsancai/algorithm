#include<iostream>
#include<string>
using namespace std;
string reverseString(string s) 
{
	string str="";
	int len=s.size();
	if(len==0)
	{
		return str;
	}
	for(int i=len-1;i>=0;i--)
	{
		str+=s[i];
	}        
	return str;
}
int main()
{
	cout<<reverseString("hello");
}