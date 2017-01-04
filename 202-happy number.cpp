#include<iostream>
#include<math.h>
#include<set>
using namespace std;

int countN(int n)
{
	int sum=0;
	while(n!=0)
	{
		sum+=(n%10)*(n%10);
		n/=10;
	}	
	return sum;
}
bool isHappy(int n)
{
	set<int> s;
	while(n!=1)
	{
		int sum=countN(n);
		if(s.count(sum)>0)
			return false;
		s.insert(sum);
		n=sum;	
	}
	return true;
}
int main()
{
	cout<<isHappy(18);
}