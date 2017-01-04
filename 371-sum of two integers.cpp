#include<iostream>
using namespace std;

int getSum(int a,int b)
{
	if(b==0)
	{
		return a;
	} 
	int sum1=a^b;
	int sum2=(a&b)<<1;
	return getSum(sum1,sum2);
}

int main()
{
	cout<<getSum(1,3)<<endl;
}