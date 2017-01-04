#include<stdio.h>
#include<stack>
using namespace std;
int data[1005];
int main()
{
	int M;
	int N;
	int K;
	stack<int> s;
	bool flag;
	scanf("%d%d%d",&M,&N,&K);
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&data[j]);
		}
		flag=true;
		for(int j=0;j<N-1;j++)
		{
			int x=data[j];
			s.push(x);
			for(int k=j;k<N;k++)
			{
				if(data[k]<x)
				{
					if(data[k]>s.top())
					{
						while(!s.empty())
						{
							s.pop();
						}
						flag=false;
						break;
					}
					s.push(data[k]);
					if(s.size()>M)
					{
						while(!s.empty())
						{
							s.pop();
						}
						flag=false;
						break;
					}
				}
			}
			if(!flag)
			{
				break;
			}
			while(!s.empty())
			{
				s.pop();
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}