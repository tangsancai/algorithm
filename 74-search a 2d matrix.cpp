#include<iostream>
#include<vector>
using namespace std;
//第一行，第一列作为辅助数组，无需担心第一行原来是1，后改为0，因为只要改为0，最后还是会变成0 
bool searchMatrix(vector< vector<int> >& matrix, int target)
{
	int lenv=matrix.size();
	if(lenv==0)
		return false;
	int lenh=matrix[0].size();
	int s=0,e=lenv-1;
	int mid,i;
	if(matrix[e][0]<target)
		i=e;
	else if(matrix[s][0]>target)
		return false;
	else if(lenv==1)
		i=0;
	else 
	{
		while(s<=e)
		{
			mid=(s+e)/2;
			if(matrix[mid][0]==target)
				return true;
			else if(matrix[mid][0]>target)
				e=mid-1;
			else if(matrix[mid][0]<target)
			{
				if(mid+1<lenv&&matrix[mid+1][0]>target)
				{
					i=mid;
					break;
				}
				else
					s=mid+1;
			}
		}
	}
	s=0;
	e=lenh-1;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(matrix[i][mid]==target)
			return true;
		else if(matrix[i][mid]>target)
			e=mid-1;
		else
			s=mid+1;	
	}
	return false;
}

int main()
{
	vector< vector<int> > v;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(3);
	tmp.push_back(5);
	tmp.push_back(7);
	v.push_back(tmp);
	tmp[0]=10;
	tmp[1]=11;
	tmp[2]=16;
	tmp[3]=20;
	v.push_back(tmp);
	tmp[0]=23;
	tmp[1]=30;
	tmp[2]=34;
	tmp[3]=50;
	v.push_back(tmp);
	cout<<searchMatrix(v,50);
}