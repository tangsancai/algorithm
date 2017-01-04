#include<iostream>
#include<string>
#include<vector>
using namespace std;

void tryIP(string tmp,string s,int n,vector<string> &v)
{
	if(n>=4&&s.size()==0)
	{
		v.push_back(tmp);
		return;
	}	
	int len=s.size();
	if(len>4*(4-n))
		return;
	for(int i=0;i<3&&i<len;++i)
	{
		int sum=0;
		int ss=0;
		switch(i)
		{
			case 0:
				ss=0;
				break;
			case 1:
				ss=10;
				break;
			case 2:
				ss=100;
				break;
		}
		for(int j=0;j<=i;++j)
		{
			sum*=10;
			sum+=(s[j]-'0');
		}
		if(sum<=255&&sum>=ss)
		{
			string f;
			if(n!=0)
				f=".";
			tryIP(tmp+f+s.substr(0,i+1),s.substr(i+1,len-i-1),n+1,v);
		}
	}
}
vector<string> restoreIpAddresses(string s)
{
	vector<string> v;
	string tmp="";
	tryIP(tmp,s,0,v);
	return v;
}

int main()
{
	string str="010010";
	vector<string> v=restoreIpAddresses(str);
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl;
}