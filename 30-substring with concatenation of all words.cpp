#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> v;
	map<string,int> m;
	int wlen=words.size();
	if(wlen==0)	
		return v;
	int slen=words[0].size();
	for(int i=0;i<wlen;++i)
	{
		int tmp=1;
		if(m.count(words[i])>0)
			tmp+=m[words[i]];
		m[words[i]]=tmp; 
	}
	int len=s.size();
	for(int i=0;i<=len-wlen*slen;++i)
	{
		map<string,int> mtmp=m;
		int pos=i;
		int num=0;
		while(num<wlen)
		{
			map<string,int>::iterator it=m.find(s.substr(pos,slen));
			if(it!=m.end()&&it->second>0)
			{
				it->second--;
				pos+=slen;
				++num;
			}
			else
				break;
		}
		if(num==wlen)
			v.push_back(i);
		m=mtmp;
	}
	return v;
}

int main()
{
	string s="wordgoodgoodgoodbestword";
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("good");
	words.push_back("best");
	vector<int> v=findSubstring(s,words);
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"\t";
}