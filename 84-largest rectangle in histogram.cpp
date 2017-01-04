#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea1(vector<int>& heights)//DP内存超限
{
	int len=heights.size();
	vector<int> tmp(len,0);
	vector< vector<int> >hmin(len,tmp);
	int maxx=0;
	for(int i=0;i<len;++i)
	{
		hmin[i][i]=heights[i];
		if(hmin[i][i]>maxx)
			maxx=hmin[i][i];
	}
	for(int i=0;i<len;++i)
		for(int j=i+1;j<len;++j)
			hmin[i][j]=hmin[j][j]<hmin[i][j-1]?hmin[j][j]:hmin[i][j-1];
		
	for(int r=2;r<=len;++r)
		for(int i=0;i<=len-r;++i)
		{
			int j=i+r-1;
			if(r*hmin[i][j]>maxx)
				maxx=r*hmin[i][j];
		}
	return maxx;
}
int largestRectangleArea(vector<int>& heights)
{
	int len=heights.size();
	stack<int> stk;
	int maxx=0;
	for(int i=0;i<len;++i)
	{
		if(stk.empty()||stk.top()<=heights[i])
			stk.push(heights[i]);
		else
		{
			int num=0;
			while(!stk.empty()&&stk.top()>heights[i])//栈内保证升序 
			{
				++num;
				maxx=maxx>num*stk.top()?maxx:num*stk.top();
				stk.pop();
			}
			while(num>=0)
			{
				stk.push(heights[i]);	
				--num;
			}
		}
	}
	int num=0;
	while(!stk.empty())
	{
		++num;
		maxx=maxx>num*stk.top()?maxx:num*stk.top();
		stk.pop();
	}
	return maxx;
} 
int main()
{
	vector<int> h;
	h.push_back(2);
//	h.push_back(1);
//	h.push_back(5);
//	h.push_back(6);
//	h.push_back(2);
	//h.push_back(3);
	cout<<
	largestRectangleArea(h);
}
