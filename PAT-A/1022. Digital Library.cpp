#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef struct bookInfo
{
	string Id;
	string bookName;
	string author;
	vector<string> keyWord;
	string publish;
	string year;	
};
bookInfo node[10005];
set<string> recorder;
int main()
{
	int N;
	int M;
	cin>>N;
	getchar();
	for(int i=0;i<N;i++)
	{
		string keywords;
		string temp="";
		getline(cin,node[i].Id);
		getline(cin,node[i].bookName);
		getline(cin,node[i].author);
		getline(cin,keywords);
		getline(cin,node[i].publish);
		getline(cin,node[i].year);
		for(int j=0;j<keywords.size();j++)
		{
			if(keywords[j]!=' ')
			{
				temp=temp+keywords[j];
			}
			else
			{
				node[i].keyWord.push_back(temp);
				temp="";
			}
		}
		node[i].keyWord.push_back(temp);
	}
	cin>>M;
	getchar();
	for(int i=0;i<M;i++)
	{
		string temp1;
		string temp;
		getline(cin,temp);
		temp1=temp;
		int number=temp[0]-'0';
		temp.erase(temp.begin());
		temp.erase(temp.begin());
		temp.erase(temp.begin());
		recorder.clear();
		switch(number)
		{
			case 1:
				for(int j=0;j<N;j++)
				{
					if(node[j].bookName==temp)
					{
						recorder.insert(node[j].Id);
					}
				}
				break;
			case 2:
				for(int j=0;j<N;j++)
				{
					if(node[j].author==temp)
					{
						recorder.insert(node[j].Id);
					}
				}
				break;
			case 3:
				for(int j=0;j<N;j++)
				{
					for(int k=0;k<node[j].keyWord.size();k++)
					{
						if(node[j].keyWord[k]==temp)
						{
							recorder.insert(node[j].Id);
						}
					}
				}
				break;
			case 4:
				for(int j=0;j<N;j++)
				{
					if(node[j].publish==temp)
					{
						recorder.insert(node[j].Id);
					}
				}
				break;
			case 5:
				for(int j=0;j<N;j++)
				{
					if(node[j].year==temp)
					{
						recorder.insert(node[j].Id);
					}
				}
				break;
		}
		cout<<temp1<<"\n";
		for(set<string>::iterator it=recorder.begin();it!=recorder.end();it++)
		{
			cout<<*it<<"\n";
		}
		if(recorder.size()==0)
		{
			cout<<"Not Found\n";
		}
	}
}