#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int i=digits.size()-1;
	int sum=digits[i]+1;
	int up=sum/10;
	digits[i]=sum%10;
	--i;
	while(i>=0)
	{
		sum=digits[i]+up;
		up=sum/10;
		digits[i]=sum%10;
		--i;
	}
	if(up>0)
		digits.insert(digits.begin(),up);
	return digits;
}