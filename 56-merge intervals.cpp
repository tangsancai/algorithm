#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
static bool cmp(Interval a,Interval b)
{
	if(a.start!=b.start)
		return a.start<b.start;
	return a.end<b.end;
}

vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> v;
	int len=intervals.size();
	if(len==0)
		return v;
	sort(intervals.begin(),intervals.end(),cmp);
	v.push_back(intervals[0]);
	for(int i=1;i<len;++i)
	{
		if(intervals[i].end<=v[v.size()-1].end)
			continue;
		else if(intervals[i].start<=v[v.size()-1].end&&intervals[i].end>v[v.size()-1].end)
			v[v.size()-1].end=intervals[i].end;
		else if(intervals[i].start>v[v.size()-1].end))
			v.push_back(intervals[i]);	
	}
	return v;
}

