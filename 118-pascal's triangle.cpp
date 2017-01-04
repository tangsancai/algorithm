#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > generate(int numRows)
{
	vector< vector<int> > v;
	if(numRows==0)
	{
		return v;
	}
	vector<int> tmp;
	tmp.push_back(1);
	v.push_back(tmp);
	if(numRows==1)
	{
		return v;
	}
	tmp.push_back(1);
	v.push_back(tmp);
	if(numRows==2)
	{
		return v;
	}
	for(int i=3;i<=numRows;i++)
	{
		vector<int> temp;
		temp.push_back(1);
		for(int j=0;j<i-2;j++)
		{
			temp.push_back(v[i-2][j]+v[i-2][j+1]);
		}
		temp.push_back(1);
		v.push_back(temp);
	}
	return v; 
}

int main()
{
	vector< vector<int> > v=generate(5);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<"\t";
		}
		cout<<endl;
	}
}