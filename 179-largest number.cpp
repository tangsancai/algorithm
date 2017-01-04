#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

static bool cmp(int a,int b)
{
	if(a==0||b==0)
		return a>b;
	vector<int> av;
	while(a!=0)
	{
		av.push_back(a%10);
		a/=10;
	}
	vector<int> bv;
	while(b!=0)
	{
		bv.push_back(b%10);
		b/=10;
	}
	int posa=av.size()-1;
	int posb=bv.size()-1;
	while(posa>=0&&posb>=0)
	{
		if(av[posa]!=bv[posb])
			return av[posa]>bv[posb];
		--posa;
		--posb;
	}
	return a+b>b+a;
}
string largestNumber(vector<int>& nums)
{
	sort(nums.begin(),nums.end(),cmp);
	string str="";
	for(int i=0;i<nums.size();++i)
	{
		string tmp="";
		if(nums[i]==0)
			tmp+='0';
		while(nums[i]!=0)
		{
			tmp+=('0'+nums[i]%10);
			nums[i]/=10;
		}
		for(int j=tmp.size()-1;j>=0;--j)
			str+=tmp[j];
	}
	if(str[0]=='0'&&str[str.size()-1]=='0')
	{
		str="0";
		return str;
	}
	return str;
}
int main()
{
	vector<int> num;
	num.push_back(1); 
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(8);
	num.push_back(9);
	cout<<largestNumber(num);
}