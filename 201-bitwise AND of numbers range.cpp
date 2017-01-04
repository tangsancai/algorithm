#include<iostream>
#include<math.h>
using namespace std;

int weishu(int n)
{
	int num=0;
	while(n!=0)
	{
		n/=2;
		++num;
	}
	return num;		
}
int rangeBitwiseAnd(int m, int n)
{
	int numm=weishu(m);
	int numn=weishu(n);
	if(numm!=numn||numm==0)
		return 0;
	int tmp=(int)pow(2,numm-1);
	return tmp+rangeBitwiseAnd(m-tmp,n-tmp);	
}
int main()
{
	cout<<rangeBitwiseAnd(3,3);
}