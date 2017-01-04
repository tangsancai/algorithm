#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
	vector<int> v;
	int len1=nums1.size();
	int len2=nums2.size();
	int i1=0;
	int i2=0;
	while(i1<len1&&i2<len2)
	{
		if(nums1[i1]==nums2[i2])
		{
			if(v.size()==0)
			{
				v.push_back(nums1[i1]);
			}
			if(v.back()!=nums1[i1])
			{
				v.push_back(nums1[i1]);
			}
			i1++;
			i2++;
		}
		else if(nums1[i1]<nums2[i2])
		{
			i1++;
		}
		else
		{
			i2++;
		}
	}
	return v;
} 