#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node
{
	int times;
	int num;
};
static bool cmp(node a,node b)
{
	return a.times>b.times;
}
vector<int> topKFrequent(vector<int>& nums, int k)
{
	sort(nums.begin(),nums.end());
	int len=nums.size();
	node n;
	n.times=1;
	n.num=nums[0];
	vector<node> v;
	v.push_back(n);
	for(int i=1;i<len;i++)
	{
		if(v.back().num==nums[i])
		{
			v.back().times++;
		}	
		else
		{
			n.times=1;
			n.num=nums[i];
			v.push_back(n);
		}
	}
	vector<int> a;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<k;i++)
	{
		a.push_back(v[i].num);
	}
	return a;
}

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	vector<int> b=topKFrequent(a,2);
	for(int i=0;i<b.size();i++)
	{
		cout<<b[i]<<"\t";
	}
}