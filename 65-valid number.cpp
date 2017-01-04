#include<iostream>
#include<string>
using namespace std;
bool isNumber(string s)
{
	if (s.empty()) 
		return false; 
  	s.erase(0,s.find_first_not_of(" "));
  	s.erase(s.find_last_not_of(" ")+1); 
   	int p=s.find('e');
    if(string::npos!=p)
	{
		string s1=s.substr(0,p);
		string s2=s.substr(p+1);
		bool b1=pureNumber(s1);
		bool b2=pureNumber(s2,true);
		return b1&&b2;
	}
 	return pureNumber(s);
}
bool pureNumber(string s,bool integerOnly=false)
{
	bool num=false;
	int i=0;
 	if('-'==s[i]||'+'==s[i])
	 	i++;
   	for(;i<s.size();i++)
   	{
	   	if('.'==s[i])
	   	{
		   	if(integerOnly)
			   	return false;
       		else 
			   	integerOnly=true;
       	}
	   	else if(s[i]>='0'&&s[i]<='9')
		   	num=true;
	  	else
		  	return false;
     }
     return num;
}
int main()
{
	string str="0.2e.e0.4";
	cout<<isNumber(str);
}