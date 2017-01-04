#include<iostream>
#include<string>
using namespace std;
//t="rabbit" s="rabbbit"  dp[3][4]=2��ʾ�Ӵ���ǰ3λ"rab"��ĸ����ǰ4λ"rabb"����2��ȡ�� 
//����s�ĵ�j���ַ���t�ĵ�i���ַ�����ͬ����ô����ζ��dp[i][j]��ֵ��dp[i][j-1]��һ���ģ�
//ǰ����Ƕ��ٻ��Ƕ��٣�����j���ַ��ļ���Ҳ���������κο��н����
//���s�ĵ�j���ַ���t�ĵ�i���ַ���ͬ����ô����dp[i-1][j-1]������Ľ�������Ϊ�µ���������У�
//��Ȼdp[i][j-1]��Ҳ���ǿ��н��������dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
int numDistinct(string s, string t)
{
	int len0=t.size();
	int len1=s.size();
	if(len0==0||len1==0)
	{
		return 0;
	}
	if(len1<len0)
	{
		return 0;
	}
	vector< vector<int> > dp;
	vector<int> tmp;
	for(int i=0;i<=len1;i++)
	{
		tmp.push_back(0);
	}
	for(int i=0;i<=len0;i++)
	{
		dp.push_back(tmp);
	}
	for(int i=0;i<=len1;i++)
	{
		dp[0][i]=1;
	}
	for(int i=1;i<=len0;i++)
	{
		for(int j=1;j<=len1;j++)
		{
			if(s[j-1]==t[i-1])
			{
				dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
				//dp[i-1][j-1]����ĸ��S��ǰj-1�Ĵ��У��Ӵ�T��ǰi-1�Ĵ���dp[i-1][j-1]�ֱ䷨����t[i]==s[j]����...�����һ���ַ��õ���s[j]�� 
				//��Ҫ����dp[i][j-1]���һ���ַ��õĲ���s[j] 
			}
			else
			{
				dp[i][j]=dp[i][j-1];
			}
		} 
	}
	return dp[len0][len1];
}