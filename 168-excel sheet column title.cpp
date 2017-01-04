#include<string>
#include<iostream>
using namespace std;

string convertToTitle(int n)
{
	string str="";
	while(n!=0)
	{
		--n;
		string tmp(1,'A'+n%26);
		str=tmp+str;
		n/=26;
	}
	return str;
}

int main()
{
	cout<<convertToTitle(28);
}