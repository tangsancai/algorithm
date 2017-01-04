#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
/*
struct Nodei
{
	int i;
	int val;
	Nodei(int a,int b):i(a),val(b){}
	friend bool operator < (Nodei a,Nodei b)
	{
		return a.val<b.val;
	}	
};
int maxArea(vector<int>& height)
{
	if(height.size()<=1)
		return 0;
	priority_queue<Nodei> pi;
	for(int i=0;i<height.size();++i)
	{
		Nodei tmp(i,height[i]);
		pi.push(tmp);
	}
	int i=pi.top().i;
	pi.pop();
	int j=pi.top().i;
	pi.pop();
	if(i>j)
	{
		i=i+j;
		j=i-j;
		i=i-j;
	}
	int maxx=min(height[i],height[j])*(j-i);
	while(!pi.empty())
	{
		int k=pi.top().i;
		cout<<k<<endl;
		pi.pop();
		if(i<k&&k<j)
			continue;
		else if(i<k&&j<k)
			j=k;
		else if(k<i&&k<j)
			i=k;
		int tmp=min(height[i],height[j])*(j-i);
		maxx=maxx>tmp?maxx:tmp;
	}
	return maxx;
}*/

int maxArea(vector<int>& height)
{
	if(height.size()<=1)
		return 0;
	int s=0;
	int e=height.size()-1;
	int minn=min(height[s],height[e]);
	int maxx=(e-s)*minn;
	while(s<e)
	{
		if(minn==height[s])
			++s;
		else 
			--e;
		minn=min(height[s],height[e]);
		maxx=maxx>(e-s)*minn?maxx:(e-s)*minn;
	}
	return maxx;
}
int main()
{
	vector<int> v;
	int tmp;
	while(cin>>tmp)
		v.push_back(tmp);
	cout<<
	maxArea(v);
}
