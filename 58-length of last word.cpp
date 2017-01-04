#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s)
{
	int lenx=0;
	int i=s.size()-1;
	while(s[i]==' ')
		--i;
	for(;i>=0;--i)
	{
		if(s[i]==' ')
    		return lenx;
    	else 
   			++lenx;
   	}
   	return lenx;
}