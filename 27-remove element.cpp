#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int len=nums.size();
	int i=0;
	while(i<len)
	{
		if(nums[i]==val)
		{
			nums.erase(nums.begin()+i);
			--len;
		}
		else
			++i;
	}
	return len;
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	cout<<removeElement(v,3)<<endl;
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"\t";
}