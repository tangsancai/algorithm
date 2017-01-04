#include<vector>
#include<iostream>
using namespace std;
/*
int maxx=-1;
void PPP(int sum,int level,vector<int> &nums,bool tag)//³¬Ê± 
{
	if(level>=nums.size())
	{
		maxx=maxx>sum?maxx:sum;
		return;		
	}
	if(tag)
		PPP(sum+nums[level],level+1,nums,false);
	PPP(sum,level+1,nums,true); 
}
int rob(vector<int>& nums)
{
	PPP(0,0,nums,true);
	return maxx;
}
*/
struct Node
{
	int addmax;
	int noaddmax;
	Node(int a,int b):addmax(a),noaddmax(b){}
};
int rob(vector<int>& nums)
{
	int len=nums.size();
	if(len==0)
		return 0;
	vector<Node> maxx;
	Node tmp(nums[0],0);
	maxx.push_back(tmp);
	for(int i=1;i<len;++i)
	{
		tmp.addmax=nums[i]+maxx[i-1].noaddmax;
		tmp.noaddmax=maxx[i-1].addmax>maxx[i-1].noaddmax?maxx[i-1].addmax:maxx[i-1].noaddmax;
		maxx.push_back(tmp);	
	}
	return maxx[len-1].addmax>maxx[len-1].noaddmax?maxx[len-1].addmax:maxx[len-1].noaddmax;
}
int main()
{
	vector<int> nums;
	for(int i=0;i<=36;++i)
	{
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}
	cout<<rob(nums);
}
//183 219 57 193 94 233 202 154 65 240 97 234 100 249 186 66 90 238 168 128 177 235 50 81 185 165 217 207 88 80 112 78 135 62 228 247 211
//3365