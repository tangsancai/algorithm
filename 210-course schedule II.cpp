#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void makegraph(vector< vector<bool> > &graph,vector< pair<int,int> > &p)
{
	for(int i=0;i<p.size();++i)
		graph[p[i].second][p[i].first]=true;	
}
void countd(vector<int> &indegree,vector< vector<bool> > &graph)
{
	int numCourses=graph.size();
	for(int i=0;i<numCourses;++i)
		for(int j=0;j<numCourses;++j)
			if(graph[i][j])
				++indegree[j];
} 
vector<int> findOrder(int numCourses, vector< pair<int, int> >& prerequisites)
{
	vector< vector<bool> > graph(numCourses,vector<bool>(numCourses,false));
	makegraph(graph,prerequisites);
	vector<int> indegree(numCourses,0);
	countd(indegree,graph);
	vector<int> v;
	vector<int> isvis(numCourses,0);
	for(int times=0;times<numCourses;++times)
	{
		for(int i=0;i<numCourses;++i)
			if(indegree[i]==0&&isvis[i]==0)
			{
				v.push_back(i);
				isvis[i]=1;
			}
		if(times>=v.size())
			break;
		for(int j=0;j<numCourses;++j)
			if(graph[v[times]][j])
				--indegree[j];
	}
	vector<int> tmp;
	return v.size()==numCourses?v:tmp;
}

int main()
{
	vector< pair<int,int> > v(1,pair<int,int>(1,0));
	vector<int> tmp=findOrder(2,v);
	for(int i=0;i<tmp.size();++i)
		cout<<tmp[i]<<endl; 
}