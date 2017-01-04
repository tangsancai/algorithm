#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

static bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first!=b.first)
	{
		return a.first<b.first;
	}
	return a.second<b.second;
}

int maxEnvelopes(vector< pair<int, int> >& envelopes)
{
	sort(envelopes.begin(),envelopes.end(),cmp);
	vector<int> v;
	int len=envelopes.size();
	int maxnum=0;
	for(int i=0;i<len;i++)
	{
		v.push_back(1);
	} 
	for(int i=0;i<len;i++)
	{
		int tmpmax=v[i];
		for(int j=i-1;j>=0;j--)
		{
			if(envelopes[i].first>envelopes[j].first&&envelopes[i].second>envelopes[j].second&&v[j]+1>tmpmax)
			{
				tmpmax=v[j]+1;	
			}
		}
		v[i]=tmpmax;
		if(v[i]>maxnum)
		{
			maxnum=v[i];
		}
	}
	return maxnum;
} 

int main()
{
	vector< pair<int,int> > v;
	pair<int,int> a;
	a.first=5;
	a.second=4;
	v.push_back(a);
	a.first=6;
	v.push_back(a);
	a.second=7;
	v.push_back(a);
	a.first=2;
	a.second=3;
	v.push_back(a);
	maxEnvelopes(v);
	return 0;
}