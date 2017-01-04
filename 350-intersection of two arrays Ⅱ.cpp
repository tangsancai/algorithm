#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> a;
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
	int len1=nums1.size();
	int len2=nums2.size();
	int i1=0;
	int i2=0;
	while(i1<len1&&i2<len2)
	{
		if(nums1[i1]==nums2[i2])
		{
			a.push_back(nums1[i1]);
			i1++;
			i2++;
		}
		else if (nums1[i1]<nums2[i2])
		{
			i1++;
		}
		else
		{
			i2++;
		}
	}	
	return a;
}