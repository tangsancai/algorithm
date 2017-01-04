#include<string>
#include<iostream>
using namespace std;

void reverseWords(string &s)
{
	s+=" ";
	int len=s.size();
	int num=0;
	int insertpos=len;
	while(num<len)
	{
		string tmp="";
		int i=0;
		while(s[i]!=' ')
		{
			tmp+=s[i];
			++i;
			++num;	
		}
		tmp+=s[i];
		++i;
		++num;
		s.insert(s.begin()+insertpos,tmp.begin(),tmp.end());
		s.erase(s.begin(),s.begin()+i);
		insertpos=len-num;
	}
	len=s.size();
	int j=0;
	while(j<len)
		if(s[len-1-j]!=' ')
			break;
		else 
			++j;
	s.erase(s.end()-j,s.end());
	j=0;
	len=s.size();
	while(j<len)
		if(s[j]!=' ')
			break;
		else 
			++j;
	s.erase(s.begin(),s.begin()+j);
}

int main()
{
	string s=" th   e";
	reverseWords(s);
}