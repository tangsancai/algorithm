#include<iostream>
#include<string>
#include<vector>
using namespace std;
string str="";
void gg(int k,int l,int s,vector<int> &v)
{
	if(l==0)
		return;
	s/=l;
	str+=('0'+v[k/s]);
	v.erase(v.begin()+k/s);
	gg(k%s,--l,s,v);
}
string getPermutation(int n, int k)
{
	int s=1;
	vector<int> v;
	for(int i=1;i<=n;++i)
	{
		v.push_back(i);
		s*=i;
	}
	gg(k-1,n,s,v);
	return str;
}

int main()
{
	cout<<getPermutation(3,1);
}