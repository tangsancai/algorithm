#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s)
{
	vector<int> v;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if('A'<=s[i]&&s[i]<='Z')
		{
			v.push_back(s[i]);
		}	
		else if('a'<=s[i]&&s[i]<='z')
		{
			v.push_back(s[i]+('A'-'a'));
		}
		else if('0'<=s[i]&&s[i]<='9')
		{
			v.push_back(s[i]);
		}
	}
	if(v.size()==0)
 	{
  		return true;
 	}
 	len=v.size();
	for(int i=0;i<len/2;i++)
	{
		if(v[i]!=v[len-1-i])
		{
			return false;	
		}
	}
	return true;
} 

int main()
{
	cout<<isPalindrome("a.")<<endl; 
}