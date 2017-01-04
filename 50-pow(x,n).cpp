#include<iostream>
#include<cmath>
#include<map>
using namespace std;
/*
//?????????? 
double myPow(double x, int n)
{
	if(n==0||x==1)
		return 1;
	if(x==-1)
		return n%2==0?1:-1;
	double s=1;
	if(n>0) 
		for(int i=0;i<n;++i)
		{
			double tmp=abs(s);
			if(tmp<0.000001)
				return 0;
			s*=x;
		}
	else
	{
		bool flag=false;
		if(n==INT_MIN)
		{
			n=INT_MAX;
			flag=true;
		}
		else
		 	n=-n;
		for(int i=0;i<n;++i)
		{
			double tmp=abs(1/s);
			if(tmp<0.000001)
				return 0;
			s*=x; 
		}
		if(flag)
			s*=x;
		s=1/s;
	}
	return s;
} */
//?????飬????Щ 
/*
map< pair<double,int>,double> m;
double myPow(double x, int n)
{
	if(n==0||x==1)
		return 1;
	if(x==-1)
		return n%2==0?1:-1;
	if(n==1)
		return x;
	if(n==-1)
		return 1/x;
	pair<double,int> tmp(x,n);
	if(m.count(tmp)>0)
		return m[tmp];
	double s1=myPow(x,n/2);
	tmp.first=x;
	tmp.second=n/2; 
	if(m.count(tmp)<=0)
		m[tmp]=s1;
	double s2=myPow(x,n-n/2);
	tmp.first=x;
	tmp.second=n-n/2; 
	if(m.count(tmp)<=0)
		m[tmp]=s2;
	return s1*s2;
}*/
map< pair<double,int>,double> m;
double myPow(double x, int n)
{
	if(n==0||x==1)
		return 1;
	if(x==-1)
		return n%2==0?1:-1;
	if(n==1)
		return x;
	if(n==-1)
		return 1/x;
	pair<double,int> tmp(x,n);
	if(m.count(tmp)>0)
		return m[tmp];
	double s1=myPow(x,n>>1);
	tmp.first=x;
	tmp.second=n>>1; 
	if(m.count(tmp)<=0)
		m[tmp]=s1;
	if(n%2==0)
		return s1*s1;
	tmp.first=x;
	tmp.second=n-n>>1; 
	if(m.count(tmp)<=0)
		m[tmp]=s1*x;
	return s1*s1*x;
}


int main()
{
	cout<<pow(1.72777,7)<<endl;
	cout<<myPow(1.72777,7)<<endl;
} 

