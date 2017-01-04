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

typedef struct Node
{
	int curAdress, key, nextAdress;
	bool exist;
	Node(){exist = false;}
	bool operator < (const Node& orh) const
	{
		return key < orh.key;
	}
}Node;
#define MAX 1000000
int main()
{
	int n, root;
	scanf("%d%d",&n,&root);
	vector<Node> nodeMap(MAX);
	for (int i = 0; i < n; ++i)
	{
		Node tmp;
		scanf("%d%d%d",&tmp.curAdress, &tmp.key, &tmp.nextAdress);
		tmp.exist = true;
		if(tmp.curAdress >= 0 && tmp.curAdress < MAX)
			nodeMap[tmp.curAdress] = tmp;
	}
	//process
	vector<Node> nodeList;
	int curID = root;
	while(curID >= 0 && curID < MAX && nodeMap[curID].exist)
	{
		nodeList.push_back(nodeMap[curID]);
		curID = nodeMap[curID].nextAdress;
	}
	//output
	if (nodeList.empty())
	{
		if (root == -1)
			printf("0 -1\n");
		else printf("0 %05d\n",root);
	}
	else
	{
		sort(nodeList.begin(), nodeList.end());
		printf("%d %05d\n", nodeList.size(), nodeList[0].curAdress);
		for (int i = 0; i < nodeList.size(); ++i)
		{
			if(i != nodeList.size()-1)
				printf("%05d %d %05d\n", nodeList[i].curAdress, nodeList[i].key, nodeList[i+1].curAdress);
			else printf("%05d %d -1\n", nodeList[i].curAdress, nodeList[i].key);
		}
	}
	return 0;
}