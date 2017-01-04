#include<iostream>
#include<vector>
using namespace std;
//n位的格雷码和n-1位格雷码的关系。回溯新理解：第n层与第n-1层之间的关系 
vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);
	for(int i=0;i<n;i++)
	{
		for(int j=result.size()-1;j>=0;j--)
		{
			int cur=result[j]+(1<<i);
			result.push_back(cur);
		}
	}
	return result;
} 