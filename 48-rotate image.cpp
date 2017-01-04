#include<iostream>
#include<vector>
using namespace std;

void move(int s,vector< vector<int> >& matrix)
{
    int pr=matrix[s][s];
	int n=matrix.size();
    for(int i=s+1;i<n-s;++i) 
		swap(pr,matrix[s][i]);
    for(int i=s+1;i<n-s;++i) 
		swap(pr,matrix[i][n-1-s]);
    for(int i=n-2-s;i>=0+s;--i) 
		swap(pr,matrix[n-1-s][i]);
    for(int i=n-2-s;i>=0+s;--i) 
		swap(pr,matrix[i][s]);
}
void rotate(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    if (n<2) 
		return;
    for(int s=0;s<n/2;++s)
	{
      	int num_move=n-1-s*2;
      	while(num_move)
		{
        	move(s,matrix);
        	num_move--;
      	}
    }
}

int main()
{
	vector< vector<int> >matrix;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	matrix.push_back(tmp);
	tmp[0]=5;
	tmp[1]=6;
	tmp[2]=7;
	tmp[3]=8;
	matrix.push_back(tmp);
	tmp[0]=9;
	tmp[1]=10;
	tmp[2]=11;
	tmp[3]=12;
	matrix.push_back(tmp);
	tmp[0]=13;
	tmp[1]=14;
	tmp[2]=15;
	tmp[3]=16;
	matrix.push_back(tmp);
	rotate(matrix);
	for(int i=0;i<matrix.size();++i)
	{
		for(int j=0;j<matrix.size();++j)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
}