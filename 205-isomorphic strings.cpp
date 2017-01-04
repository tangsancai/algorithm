#include<string>
#include<iostream>
#include<map>
using namespace std;

bool isIsomorphic(string s, string t)
{
	int m = s.size();
	int n = t.size();
	if(m != n)
		return false;
	map<char, char> m1;   //s --> t
	map<char, char> m2;   //t --> s
	for(int i = 0; i < m; i ++)
	{
		char schar = s[i];
		char tchar = t[i];
		// the same char in s map to different chars in t
		if(m1.find(schar) != m1.end() && m1[schar] != tchar)
			return false;
		// two different chars in s map tp the same char in t
        if(m2.find(tchar) != m2.end() && m2[tchar] != schar)
        	return false;
        m1[schar] = tchar;
		m2[tchar] = schar;
	}
	return true;
}
