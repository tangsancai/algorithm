#include<iostream> 
#include<vector>
using namespace std;

vector<int> spiralOrder(vector< vector<int> >& matrix)
{
	vector<int> v;
	int lenv=matrix.size();
	if(lenv==0)
		return v;
	int lenh=matrix[0].size();
	vector<bool> tmp(lenh,false);
	vector< vector<bool> > mark(lenv,tmp);
	int times=0;
	int i=0,j=0;
	while(1)
	{
		bool flag=false;
		switch(times%4)
		{
			case 0:
					for(;j<lenh-times/4-1;++j)
					{
						flag=true;
						if(!mark[i][j])
							v.push_back(matrix[i][j]);
						mark[i][j]=true;
					}
					++times;
					break;
			case 1:
					for(;i<lenv-times/4-1;++i)
					{
						flag=true;
						if(!mark[i][j])
							v.push_back(matrix[i][j]);
						mark[i][j]=true;
					}
					++times;
					break;
			case 2:
					for(;j>times/4;--j)
					{
						flag=true;
						if(!mark[i][j])
							v.push_back(matrix[i][j]);
						mark[i][j]=true;
					}
					++times;
					break;
			case 3:
					for(;i>times/4;--i)
					{
						flag=true;
						if(!mark[i][j])
							v.push_back(matrix[i][j]);
						mark[i][j]=true;
					}
					++times;
					i=times/4;
					j=times/4;
					break;
		}	
		if(!flag)
			break;
	}
	if(lenv*lenh!=v.size())
		for(int i1=0;i1<lenv;++i1)
			for(int j1=0;j1<lenh;++j1)
				if(!mark[i1][j1])
					v.push_back(matrix[i1][j1]);
	return v;
}

int main()
{
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	tmp.push_back(5);
	tmp.push_back(6);
	tmp.push_back(7);
	tmp.push_back(8);
	tmp.push_back(9);
	tmp.push_back(10);
	vector< vector<int> > v;
	v.push_back(tmp);
	tmp[0]=11;
	tmp[1]=12;
	tmp[2]=13;
	tmp[3]=14;
	tmp[4]=15;
	tmp[5]=16;
	tmp[6]=17;
	tmp[7]=18;
	tmp[8]=19;
	tmp[9]=20;
	v.push_back(tmp);
	tmp=spiralOrder(v);
	for(int i=0;i<tmp.size();++i)
		cout<<tmp[i]<<"\t";
}