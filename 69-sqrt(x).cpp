#include<iostream>
#include<math.h>
using namespace std;

int mySqrt(int x)
{
	if(x<0)
		return INT_MIN;
	if(x==0||x==1)
		return x;
	int s=1;
	int e=x<46341?x:46341;
	int mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(mid*mid==x)
			return mid;
		else if(mid*mid>x)
			e=mid-1;
		else
		{
			if(mid*mid<x&&(mid+1>=46341||(mid+1)*(mid+1)>x))
				return mid;
			else
				s=mid+1;
		}
	}
	return mid;
} 

int main()
{
	cout<<mySqrt(INT_MAX-2)<<"\t"<<(int)sqrt(INT_MAX);
	return 0;
}