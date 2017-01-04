#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums)
{
	int len =nums.size();
	vector<int> a;
	if(len==0)
	{
		return a;	
	} 
	sort(nums.begin(),nums.end());
	vector< vector<int> > v;
	vector<int> tmp;
	tmp.push_back(nums[0]);
	v.push_back(tmp);
	for(int i=1;i<len;i++)
	{
		int maxlen=-1;
		for(int j=0;j<i;j++)
		{
			int lentmp=v[j].size();
			if(nums[i]%v[j][lentmp-1]==0&&(lentmp+1)>maxlen)
			{
				tmp=v[j];
				tmp.push_back(nums[i]);
				maxlen=lentmp+1;
			}
		}
		if(maxlen==-1)
		{
			tmp=a;
			tmp.push_back(nums[i]);
		}	
		v.push_back(tmp);		
	}
	len=v.size();
	int maxlen2=-1;
	vector<int> res;
	for(int i=0;i<len;i++)
	{
		int vlen=v[i].size();
		if(maxlen2<vlen)
		{
			maxlen2=vlen;
			res=v[i];
		}
	}	
	return res;
}
int main()
{
	vector<int> nums;
//	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(9);
	nums.push_back(18);
//	nums.push_back(72);
	vector<int> v=largestDivisibleSubset(nums);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\t";
	}
}