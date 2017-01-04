#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getNext(vector<int> &next,string &needle)
{
	next[0]=-1;
	int nlen=needle.size();
	int hou=0;
	int qian=-1;
	while(hou<nlen)
		if(qian==-1||needle[hou]==needle[qian])
		{
			++hou;
			++qian;
			next[hou]=qian;
		}
		else
			qian=next[qian];
}

int strStr(string haystack, string needle)
{
	int nlen=needle.size();
	int hlen=haystack.size();
	vector<int> next(nlen,0);
	getNext(next,needle);
	int i=0;
	int j=0;
	while(i<hlen&&j<nlen)
	{
		if(j==-1||haystack[i]==needle[j])
		{
			++i;
			++j;
		}
		else
		{
			j=next[j];
		}
	}
	if(j==nlen)
		return i-j;
	else
		return -1;
	return -1;
}