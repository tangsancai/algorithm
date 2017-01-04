#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int noaddmax;
	int addmax;
	Node(int a,int b):noaddmax(a),addmax(b){} 
};
int rob(vector<int>& nums)
{
	//node1不加
	if(nums.size()==0)
		return 0;
	if(nums.size()==1)
		return nums[0];
	vector<Node> maxx;
	Node tmp(0,0);
	maxx.push_back(tmp);
	for(int i=1;i<nums.size();++i)
	{
		tmp.noaddmax=maxx[i-1].noaddmax>maxx[i-1].addmax?maxx[i-1].noaddmax:maxx[i-1].addmax;
		tmp.addmax=nums[i]+maxx[i-1].noaddmax;
		maxx.push_back(tmp);
	}
	int m=maxx[nums.size()-1].addmax>maxx[nums.size()-1].noaddmax?maxx[nums.size()-1].addmax:maxx[nums.size()-1].noaddmax;
	//node1加了 
	maxx.clear();
	tmp.noaddmax=0;
	tmp.addmax=nums[0];
	maxx.push_back(tmp);
	for(int i=1;i<nums.size()-1;++i)
	{
		tmp.noaddmax=maxx[i-1].noaddmax>maxx[i-1].addmax?maxx[i-1].noaddmax:maxx[i-1].addmax;
		tmp.addmax=nums[i]+maxx[i-1].noaddmax;
		maxx.push_back(tmp);
	}
	int n=maxx[nums.size()-2].addmax>maxx[nums.size()-2].noaddmax?maxx[nums.size()-2].addmax:maxx[nums.size()-2].noaddmax;
	return m>n?m:n;
}