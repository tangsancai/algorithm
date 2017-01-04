#include<iostream>
using namespace std;
int sum=0;
int countSum(int t,int n)
{
	if(t>=10||t>=n)
	{
		return sum;
	}
	int tmp=9;
	for(int i=0;i<=t-1;i++)
	{
		tmp*=(9-i);	
	}
	sum+=tmp;
	return countSum(t+1,n);
}
int countNumbersWithUniqueDigits(int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n==1)
	{
		return 10;
	}
	sum=10;
	return countSum(1,n);
}
int main()
{
	cout<<countNumbersWithUniqueDigits(3)<<endl;
}