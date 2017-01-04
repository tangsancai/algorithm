#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> A,pair<int,int> B)
{
	int sumA=A.first+A.second;
	int sumB=B.first+B.second;
	return sumA<sumB;
}
vector< pair<int,int> > kSmallestPair(vector<int>&nums1,vector<int>&nums2,int k)
{
	vector< pair<int,int> > v;
	vector< pair<int,int> > v2;
	int len1=nums1.size();
	int len2=nums2.size();
	int numk;
	pair<int,int> tmp;
	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		{
			tmp.first=nums1[i];
			tmp.second=nums2[j];
			v.push_back(tmp);
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(len1*len2<k)
	{
		numk=len1*len2;
	}
	else
	{
		numk=k;
	}
	v2.assign(v.begin(),v.begin()+numk);
	return v2;
}
int main()
{
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(1);
	nums1.push_back(2);
	vector<int> nums2;
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(3);
	int k=2;
	vector< pair<int,int> > v=kSmallestPair(nums1,nums2,k);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<"   "<<v[i].second<<endl;
	}
	return 0;
} 