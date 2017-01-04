#include<iostream>
#include<string>
#include<stack>
using namespace std;

string simplifyPath(string path)
{
	int i=0,j=0;
    int n=path.size();
    stack<string> s;    
    while(i<n)
	{
		j=i+1;
		while(j<n&&path[j]!='/')
			j++;
        string temp=path.substr(i+1,j-i-1);
        if(temp=="..")
		{
			if(!s.empty())
				s.pop();
		}
  		else if(temp!=""&&temp!=".") 
  			s.push(temp);
        i=j;
    }
	string result="";
	if(s.empty())
		return "/";
    stack<string> t;
    while(!s.empty())
	{
		t.push(s.top());
		s.pop();
  	}
  	while(!t.empty())
  	{
	  	result=result+"/"+t.top();
     	t.pop();
    }
	return result;
}

int main()
{
	string s="/home/";
	cout<<simplifyPath(s)<<endl;
}