#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
//uint32_t
unsigned int reverseBits(unsigned int n)
{
	stack<unsigned int> stk;
	int num=0;
	while(n!=0)
	{
		stk.push(n%2);
		n/=2;
		++num;
	}
	for(int i=num;i<32;++i)
		stk.push(0);
	unsigned int rn=0;
	for(int i=0;i<32;++i)
	{
		rn+=pow(2,i)*stk.top();
		stk.pop();
	}	
	return rn;
}
int main()
{
	cout<<reverseBits(43261596);
}