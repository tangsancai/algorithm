#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n)//��ʱ 
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
			else if(v[j]>sqrt(i))//������sqrt(i)��ʱ���û��Ҫ����ȥ�� 
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