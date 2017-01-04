#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int len=gas.size();
	vector<int> v;
	int s=0;
	for(int i=0;i<len;++i)
	{
		v.push_back(gas[i]-cost[i]);
		s+=v[i];
	}
	if(s<0)
	{
		return -1;
	}
	s=0;
	int start=0;
	int i=0;
	while((i+1)%len!=start)
	{
		s+=v[i];
		if(s<0)
		{
			s=0;
			start=i+1;
		}
		i=(++i)%len;
	}
	return start;
}