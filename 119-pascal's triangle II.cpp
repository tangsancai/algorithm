#include<iostream>
#include<vector>
using namespace std;

vector<int> generate(int rowIndex)
{
	int numRows=rowIndex+1;
	vector< vector<int> > v;
	vector<int> tmp;
	if(numRows==0)
	{
		return tmp;
	}
	tmp.push_back(1);
	v.push_back(tmp);
	if(numRows==1)
	{
		return tmp;
	}
	tmp.push_back(1);
	v.push_back(tmp);
	if(numRows==2)
	{
		return tmp;
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
	return v[rowIndex]; 
}