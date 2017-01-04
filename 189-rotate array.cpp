#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k)
{
	while(k>0)
	{
		nums.insert(nums.begin(),nums.back());
		nums.pop_back();
		--k;
	}
}
int main()
{
	vector<int> v;
	for(int i=0;i<7;++i)
		v.push_back(i);
	rotate(v,3);
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"\t";
	
}