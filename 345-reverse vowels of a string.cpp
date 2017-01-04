#include<iostream>
#include<vector>
#include<string>
using namespace std;
string reverseVowels(string s)
{
	if(s=="")
	{
		return s;
	}
	int i=-1;
	int k=-1;
	int len=s.size();
	string tmp="";
	string r="";
	while(k!=len-1)
	{
		++k;
		if(s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u')
		{
			i=k;
			break;
		}
		r+=s[k];
	}
	while(k!=len-1)
	{
		++k;
		if(s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u')
		{
			r+=s[k];
			r+=tmp;
			tmp="";
			continue;
		}
		tmp+=s[k];
	}
	if(i!=-1)
	{
		r+=s[i];
		r+=tmp;
	}
	return r; 
}
int main()
{
	cout<<reverseVowels("  ");
}