#include<iostream>
#include<limits.h>
using namespace std;
bool isPowerOfFour(int num)
{
	return num>0&&(num&(num-1))==0&&(num&0x55555555)!=0;//num&(num-1)==0��֤��ֻ��һλ1 
} 

int main()
{
	cout<<isPowerOfFour(16);
}
