#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int num)
{
	vector<int> r;
	for(int i=0;i<=num;i++)
	{
		int n=i;
		int s=0;
		while(n!=0)
		{
			if((n&1)!=0)
			{
				s++;
			}
			n=n>>1;
		}
		r.push_back(s);
	}
	return r;
}

int main()
{
	vector<int> v=countBits(5);
	for(int i=0;i<=5;i++)
	{
		cout<<v[i];
	}
}