#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	int s=0;
	int e=numbers.size()-1;
	vector<int> v;
	while(s<=e)
	{
		if(numbers[s]+numbers[e]==target)
		{
			v.push_back(s+1);
			v.push_back(e+1);
			return v;
		}
		else if(numbers[s]+numbers[e]<target)
			++s;
		else
			--e;
	}
	return v;
}

int main()
{
	return 0;
}