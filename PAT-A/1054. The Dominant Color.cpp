#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int M;
	int N;
	int flag=0;
	char str2[30];
	string str1;
	map<string,int> mp;
	scanf("%d%d",&M,&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%s",str2);//用cin超时 
			string str(&str2[0],&str2[strlen(str2)]);//字符数组转化为字符串 
			if(flag==0)
			{
				if(mp.find(str)!=mp.end())
				{
					mp[str]++;
				}
				else
				{
					mp[str]=1;
				}
				if(mp[str]>M*N/2)
				{
					str1=str;
					flag=1;
				}
			}	
		}
	}
	cout<<str1;
}