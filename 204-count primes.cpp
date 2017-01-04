#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n)//超时 
{
	vector<int> v;
	if(n<=1)
		return 0;
	for(int i=2;i<=n;++i)
	{
		bool flag=true;
		for(int j=0;j<v.size();++j)
		{
			if(i%v[j]==0)
			{
				flag=false;
				break;
			}
			else if(v[j]>sqrt(i))//大于了sqrt(i)的时候就没必要算下去了 
				break;
		}	
		if(flag)
			v.push_back(i);		
	}
	return v.size();
}
int main()
{
	cout<<countPrimes(12);
}