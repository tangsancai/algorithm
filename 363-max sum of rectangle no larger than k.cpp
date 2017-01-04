#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


int maxSumSubmatrix(vector< vector<int> >& matrix, int k)
{
	int rownum=matrix.size();
	int colnum=matrix[0].size();
	vector< vector< vector<int> > > vvv;
	//横向来一遍 
	vector< vector<int> > v;
	vector<int> tmp;
	for(int i=0;i<colnum;i++)
	{
		tmp.push_back(0);
	}
	for(int i=0;i<colnum;i++)
	{
		v.push_back(tmp);
	}
	int rowmax=INT_MIN;
	for(int i=0;i<rownum;i++)
	{
		for(int tmpi=0;tmpi<colnum;tmpi++)
		{
			v[tmpi][tmpi]=matrix[i][tmpi];
		}
		for(int z=2;z<=colnum;z++)
		{
			for(int ri=0;ri<=colnum-z;ri++)
			{
				int ci=ri+z-1;
				v[ri][ci]=v[ri][ci-1]+matrix[i][ci];
				if(v[ri][ci]==k)
				{
					return v[ri][ci];
				}
				if(v[ri][ci]<k&&v[ri][ci]>rowmax)
				{
					rowmax=v[ri][ci];
				}
			}
		}
		vvv.push_back(v);
	} /* 
	//以横值为基础，竖的再来一遍 
	vector< vector<int> > vv;
	for(int tmpi=0;tmpi<)
	for(int z=2;z<=rownum;z++)
	{
		for(int i=0;i<=rownum-z;i++)
		{
				
		}
	}*/ 
}

int main()
{
	vector< vector<int> > v;
	vector<int> r1;
	r1.push_back(1);
	r1.push_back(0);
	r1.push_back(1);
	v.push_back(r1);
	r1[0]=0;
	r1[1]=-2;
	r1[2]=3;
	v.push_back(r1);
	r1[0]=0;
	r1[1]=-2;
	r1[2]=3;
	v.push_back(r1);
	cout<<maxSumSubmatrix(v,2);	
} 