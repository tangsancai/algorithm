#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
using namespace std;

struct Point
{
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int a,int b):x(a),y(b){}
};
static bool cmp1(Point a,Point b)
{
	return a.x<b.x;
}
static bool cmp2(Point a,Point b)
{
	return a.y<b.y;
}
int maxPoints(vector<Point>& points)
{
	int len=points.size();
	if(len==0)
		return 0;
	sort(points.begin(),points.end(),cmp1);
	int maxnum=1;
	int tmp=1;
	for(int i=1;i<len;++i)
	{
		if(points[i].x==points[i-1].x)
			++tmp;
		else
		{
			if(tmp>maxnum)
				maxnum=tmp;
			tmp=1;
		}
	}
	if(tmp>maxnum)
		maxnum=tmp;
	sort(points.begin(),points.end(),cmp2);
	tmp=1;
	for(int i=1;i<len;++i)
	{
		if(points[i].y==points[i-1].y)
			++tmp;
		else
		{
			if(tmp>maxnum)
				maxnum=tmp;
			tmp=1;
		}
	}
	if(tmp>maxnum)
		maxnum=tmp;
	map<pair<double,double>, set<vector<int> > > m;
	for(int i=0;i<len;++i)
		for(int j=i+1;j<len;++j)
			if((points[j].x-points[i].x)!=0&&(points[j].y-points[i].y)!=0)
			{
				double k=(points[j].y-points[i].y+0.0)/(points[j].x-points[i].x+0.0);
				double b=points[i].y-k*points[i].x;
				pair<double,double> pa(k,b);
				set<vector<int> > st;
				if(m.count(pa)>0)
					st=m[pa];
				vector<int> p;
				p.push_back(points[i].x);
				p.push_back(points[i].y); 
				p.push_back(i);
				st.insert(p);
				p[0]=points[j].x;
				p[1]=points[j].y;
				p[2]=j;
				st.insert(p);
				m[pa]=st; 
			}
	for(map<pair<double,double>, set<vector<int> > >::iterator it=m.begin();it!=m.end();++it)
		if(it->second.size()>maxnum)
			maxnum=it->second.size();
	return maxnum;
}

int main()
{
	Point p1(0,-12);
	Point p2(5,2);
	Point p3(2,5);
	Point p4(0,-5);
	Point p5(1,5);
	Point p6(2,-2);
	Point p7(5,-4);
	Point p8(3,4);
	Point p9(-2,4);
	Point p10(-1,4);
	Point p11(0,-5);
	Point p12(0,-8);
	Point p13(-2,-1);
	Point p14(0,-11);
	Point p15(0,-9);
	vector<Point> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	v.push_back(p8);
	v.push_back(p9);
	v.push_back(p10);
	v.push_back(p11);
	v.push_back(p12);
	v.push_back(p13);
	v.push_back(p14);
	v.push_back(p15);
	cout<<maxPoints(v)<<endl;
} 
