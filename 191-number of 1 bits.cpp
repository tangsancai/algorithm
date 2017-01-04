#include<iostream>
using namespace std;
//uint32_t
int hammingWeight(unsigned int n)
{
	int num=0;
	while(n!=0)
	{
		if(n%2!=0)
			++num;
		n/=2;
	}
	return num;
}
