#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i=m-1;
	int j=n-1;
	int cur=m+n;
	while(--cur>=0) 
		nums1[cur]=(i<0||j>=0&&nums2[j]>nums1[i])?nums2[j--]:nums1[i--];
}