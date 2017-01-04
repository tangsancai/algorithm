#include<iostream>
#include<vector>
#include<string>
using namespace std;

string addBinary(string a, string b)
{
	int lena=a.size();
	int lenb=b.size();
	int i=lena-1;
	int j=lenb-1;
	int up=0;
	string str="";
	while(i>=0&&j>=0)
	{
		int sum=(a[i]-'0')+(b[j]-'0')+up;
		char tmp='0'+sum%2;
		up=sum/2;
		str.insert(str.begin(),tmp);
		--i;
		--j;
	}
	while(i>=0)
	{
		int sum=(a[i]-'0')+up;
		char tmp='0'+sum%2;
		up=sum/2;
		str.insert(str.begin(),tmp);
		--i;
	}
	while(j>=0)
	{
		int sum=(b[j]-'0')+up;
		char tmp='0'+sum%2;
		up=sum/2;
		str.insert(str.begin(),tmp);
		--j;
	}
	if(up!=0)
	{
		char tmp='0'+up;
		str.insert(str.begin(),tmp);
	}
	return str;
}
int main()
{
	string a="11";
	string b="1";
	cout<<addBinary(a,b);
}