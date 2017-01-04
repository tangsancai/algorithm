#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
{
	dict.emplace(start);
	dict.emplace(end);
	unordered_map<string, vector<string>> from;
	queue<string> que;
	que.push(start);
	dict.erase(start);
	int endLevel = -1;
	int level = 0;	
	while(!que.empty())
	{
		if(endLevel != -1) break;
		int size = que.size();
		unordered_set<string> toPush;//this is acctually what the next level is
		for(int ttt = 0; ttt < size; ttt++)
		{
			string front = que.front();
			if(front == end)
			{
				endLevel = level;
					break;
				}

				for(unsigned int i = 0; i < front.size(); i++){
					string neighbor = front;
					for(int j = 0; j < 26; j++){
						neighbor[i] = (char)((int)'a' + j);
						if(neighbor == front) continue;
						
						if((dict.count(neighbor) != 0)){
							from[neighbor].push_back(front);
							toPush.emplace(neighbor);
						}
					}
				}
				que.pop();
			}
			level++;
			for(unordered_set<string>::iterator itr = toPush.begin(); itr != toPush.end(); itr++){
				string temp = *itr;
				que.push(temp);
				dict.erase(temp);
			}
		}

		vector<vector<string>> result;
		if(from[end].size() == 0) return result;
		vector<string> tempRes;

		tempRes.push_back(end);
		help(result, tempRes, endLevel, start, end, from);
		return result;
    }
	
	void help(vector<vector<string>>& result, vector<string>&tempRes, int level, string& start, string& end, unordered_map<string, vector<string>>& from){
		if(level == 0){
			vector<string> toPush;
			for(int i = (int)tempRes.size() - 1; i >= 0; i--){
				toPush.push_back(tempRes[i]);
			}
			result.push_back(toPush);

			return;
		}

		for(unsigned int i = 0; i < from[end].size(); i++){
			string neighbor = from[end][i];
			tempRes.push_back(neighbor);
			help(result, tempRes, level - 1, start, neighbor, from);
			tempRes.pop_back();
		}
	}

	bool help2(string& s1, string& s2){
		if(s1.size() != s2.size()) return false;
		int count = 0;
		for(unsigned int i = 0; i < s1.size(); i++){
			if(s1[i] != s2[i]) count++;
			if(count > 1) return false;
		}
		if(count == 0) return false;
		return true;
	}