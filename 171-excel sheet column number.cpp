#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s)
{
	int num=0;
	int len=s.size();
	for(int i=0;i<len;++i)
		num=(s[i]-'A'+1)+num*26; 
	return num;
}
