#include<iostream>
#include<vector>
using namespace std;
//nλ�ĸ������n-1λ������Ĺ�ϵ����������⣺��n�����n-1��֮��Ĺ�ϵ 
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