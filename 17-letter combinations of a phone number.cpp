#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
vector<string> vv;
map<int,vector<char> > m;
void kk(string str,string &digits,int i)
{
	if(i>=digits.size())
	{
		vv.push_back(str);
		return;
	}
	if(digits[i]=='1')
		kk(str,digits,i+1);
	else if(digits[i]=='0')
	{
		str+=' ';
		kk(str,digits,i+1);
	}
	else
	{
		vector<char> tmp=m[digits[i]-'0'];
		for(int i1=0;i1<tmp.size();++i1)
		{
			string tmps=str+tmp[i1];
			kk(tmps,digits,i+1);
		}
	}
}
vector<string> letterCombinations(string digits)
{
	if(digits.size()==0)
		return vv;
	vector<char> v;
	m[1]=v;v.push_back(' ');m[0]=v;v[0]='a';v.push_back('b');v.push_back('c');m[2]=v;
	v[0]='d';v[1]='e';v[2]='f';m[3]=v;v[0]='g';v[1]='h';v[2]='i';m[4]=v;
	v[0]='j';v[1]='k';v[2]='l';m[5]=v;v[0]='m';v[1]='n';v[2]='o';m[6]=v;
	v[0]='t';v[1]='u';v[2]='v';m[8]=v;v[0]='p';v[1]='q';v[2]='r';v.push_back('s');m[7]=v;
	v[0]='w';v[1]='x';v[2]='y';v[3]='z';m[9]=v;
	string str="";
	kk(str,digits,0);
	return vv;
}
int main()
{
	letterCombinations("23");
	for(int i=0;i<vv.size();++i)
		cout<<vv[i]<<endl;
}