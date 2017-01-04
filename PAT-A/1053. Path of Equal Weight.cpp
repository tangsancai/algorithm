#include<iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, T;
typedef struct Node
{
	int key;
	vector<Node*> vNext;
}Node;
vector<int> possibleSolution;
bool cmp(Node* a, Node* b)
{
	return a->key > b->key;
}
void DFS(Node* curNode, int cur)
{
	cur += curNode->key;
	if (curNode->vNext.size() == 0)//leaf and find
	{
		if (cur == T)
		{
			for (int i = 0; i < possibleSolution.size(); ++i)
			{
				if(i != possibleSolution.size()-1)
					printf("%d ", possibleSolution[i]);
				else printf("%d\n", possibleSolution[i]);
			}
		}
		return;
	}
	else if (curNode->vNext.size() > 0)
	{
		if (cur > T)
			return;
		else
		{
			sort(curNode->vNext.begin(), curNode->vNext.end(), cmp);
			for (int i = 0; i < curNode->vNext.size(); ++i)
			{
				possibleSolution.push_back(curNode->vNext[i]->key);
				DFS(curNode->vNext[i], cur);
				possibleSolution.pop_back();
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&T);
	vector<int> weight(N);
	for (int i = 0; i < N; ++i)
		scanf("%d",&weight[i]);
	vector<Node*> nodeMap(N);
	//initial
	for (int i = 0; i < N; ++i)
	{
		nodeMap[i] = new Node;
		nodeMap[i]->key = weight[i];
	}
	//add child
	for (int i = 0; i < M; ++i)
	{
		int id; int C;
		scanf("%d%d",&id, &C);
		for (int j = 0; j < C; ++j)
		{
			int child;
			scanf("%d",&child);
			if (id >= 0 && id < N && child >= 0 && child < N)
				nodeMap[id]->vNext.push_back(nodeMap[child]);
		}
	}
	//dfs find all possible path and output
	possibleSolution.push_back(nodeMap[0]->key);
	int cur = 0;
	DFS(nodeMap[0], cur);
	//release memory
	for (int i = 0; i < N; ++i)
		delete nodeMap[i];

	return 0;
}