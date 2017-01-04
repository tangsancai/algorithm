#include<iostream>
#include<vector>
#include<map>
using namespace std;


int longestConsecutive(vector<int>& nums)
{
	int len=nums.size();
	map<int,int> m;
	for(int i=0;i<len;++i)
	{
		m[nums[i]]=nums[i];
	}
	int countnum=1;
	int maxnum=-1;
	map<int,int>::iterator it=m.begin();
	++it;
	for(map<int,int>::iterator it2=m.begin();it!=m.end();++it,++it2)
	{
	    int i=it->first;
	    int j=it2->first;
		if(i-j==1)
		{
			++countnum;
		}
		else
		{
			if(countnum>maxnum)
			{
				maxnum=countnum;
			}
			countnum=1;
		}
	}
	if(countnum>maxnum)
	{
		maxnum=countnum;
	}
	return maxnum;
}

int main()
{
	vector<int> v;
	v.push_back(0);
	cout<<longestConsecutive(v);
}