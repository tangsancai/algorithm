#include<iostream>
#include<set>
using namespace std;

bool isFit(string beginWord,string tmp)
{
	int len=beginWord.size();
	int countnum=0;
	for(int i=0;i<len;i++)
	{
		if(beginWord[i]!=tmp[i])
		{
			++countnum; 
			if(countnum>1)
			{
				return false;
			} 
		}
	}
	return true;
}
int minlevel=INT_MAX;
void findMe(string beginWord, string endWord, unordered_set<string>& wordList,set<string> m,int level)
{
	m.insert(beginWord);
	if(beginWord==endWord)
	{
		if(minlevel>level)
	 	{
   			minlevel=level;
   		}	
		return;
	}
	for(unordered_set<string>::iterator pos=wordList.begin();pos!=wordList.end();++pos)//比对set中的每个字串，这边炸了 
	{
		if(m.find(*pos)==m.end()&&isFit(beginWord,*pos))
		{
			findMe(*pos,endWord,wordList,m,level+1);
		}
	}	
	return;
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	set<string> m;
	findMe(beginWord,endWord,wordList,m,0);
	if(minlevel==INT_MAX)
	{
		return 0;
	}
	return minlevel+1;
}