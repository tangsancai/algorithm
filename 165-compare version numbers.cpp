#include<iostream>
#include<string>
#include<queue>
using namespace std;

int compareVersion1(string version1, string version2)
{
	queue<int> q1,q2;
	int tmp=0;
	for(int i=0;i<version1.size();++i)
		if(version1[i]!='.')
			tmp=tmp*10+(version1[i]-'0');
		else
		{
			q1.push(tmp);
			tmp=0;
		}
	q1.push(tmp);
	tmp=0;
	for(int i=0;i<version2.size();++i)
		if(version2[i]!='.')
			tmp=tmp*10+(version2[i]-'0');
		else
		{
			q2.push(tmp);
			tmp=0;
		}
	q2.push(tmp);
	int tag=0;
	while(!q1.empty()&&!q2.empty())
	{
		if(q1.front()<q2.front())
		{
			tag=-1;
			break;
		}
		else if(q1.front()>q2.front())
		{
			tag=1;
			break;
		}
		else
		{
			q1.pop();
			q2.pop();
		}	
	}
	if(q1.empty())
		tag=-1;
	if(q2.empty())
		tag=1;
	return tag;
}

int compareVersion(string s1, string s2){
    int n1=s1.size(),n2=s2.size();
    int p1=0,p2=0;
    while(p1<n1||p2<n2)
	{
        auto v1=p1<n1?sub_version(s1, p1):0;
        auto v2=p2<n2?sub_version(s2, p2):0;
        if(v1>v2) return 1;
        if(v1<v2) return -1;
    }
    return 0;
}
int sub_version(const string &s,int &pos)
{
    auto num=0;
    while(pos<s.size()&&s[pos]!= '.')
        num=num*10+s[pos++]-'0';
    ++pos;
    return num;
}
int main()
{
	string s1="0.1";
	string s2="13.37";
	cout<<compareVersion(s1,s2);
}