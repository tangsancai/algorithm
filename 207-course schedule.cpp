#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/* 
//³¬Ê± 
bool dfs(int i,vector<int> v,set<int> s,vector< vector<int> > vc)
{
	if(s.count(i)>0)
		return false;
	bool tag=true;
	for(int k=0;k<v.size();++k)
	{
		if(i==v[k])
			tag&=true;
		else
		{
			s.insert(i);
			tag&=dfs(v[k],vc[v[k]],s,vc);
		}
	}
	return tag;
}
bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites)
{
	vector< vector<int> > v;
	for(int i=0;i<numCourses;++i)
	{
		vector<int> tmp;
		tmp.push_back(i);
		v.push_back(tmp);
	}
	for(int i=0;i<prerequisites.size();++i)
	{
		vector<int> tmp=v[prerequisites[i].first];
		if(tmp[0]==prerequisites[i].first)
			tmp[0]=prerequisites[i].second;
		else
			tmp.push_back(prerequisites[i].second);
		v[prerequisites[i].first]=tmp;
	}
	for(int i=0;i<numCourses;++i)
	{
		set<int> s;
		if(!dfs(i,v[i],s,v))
			return false;
	}
	return true;
}*/
void makegmap(vector< vector<bool> > &gmap,vector< pair<int,int> > &p)
{
	for(int i=0;i<p.size();++i)
		gmap[p[i].second][p[i].first]=true;	
} 
void countindegree(vector<int> &indegree,vector< vector<bool> > &gmap)
{
	int numCourses=gmap.size();
	for(int i=0;i<numCourses;++i)
		for(int j=0;j<numCourses;++j)
			if(gmap[i][j])
				++indegree[j];
}
bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites)
{
	vector< vector<bool> > gmap(numCourses,vector<bool>(numCourses,false));
	makegmap(gmap,prerequisites);
	vector<int> indegree(numCourses,0);
	countindegree(indegree,gmap);
	queue<int> q;
	vector<bool> isvisit(numCourses,false);
	for(int i=0;i<numCourses;++i)
		if(indegree[i]==0)
			q.push(i);
	for(int times=0;times<numCourses;++times)
	{
		if(q.empty())
			return false;
		int tmp=q.front();
		isvisit[tmp]=true;
		q.pop();
		for(int i=0;i<numCourses;++i)
			if(gmap[tmp][i]&&!isvisit[i])
			{
				--indegree[i];
				if(indegree[i]==0)
					q.push(i);
			}
	}
	return true;
} 
int main()
{
	vector<pair<int,int> > v;
	v.push_back(pair<int,int>(0,1));
	v.push_back(pair<int,int>(3,1));
	v.push_back(pair<int,int>(1,3));
	v.push_back(pair<int,int>(3,2));
	cout<<canFinish(4,v);
}