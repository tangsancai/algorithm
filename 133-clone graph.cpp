#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if(node==NULL)
		return NULL;
	map<UndirectedGraphNode *,UndirectedGraphNode *> m;
	queue<UndirectedGraphNode*> q;
	set<UndirectedGraphNode *> isvis;
	q.push(node);
	UndirectedGraphNode *root;
	while(!q.empty())
	{
		UndirectedGraphNode *tmp=q.front();
		q.pop();
		if(isvis.count(tmp)>0)
			continue;
		else
			isvis.insert(tmp);
		UndirectedGraphNode *noderoot;
		if(m[tmp]>0)
			noderoot=m[tmp];
		else
		{
			noderoot=new UndirectedGraphNode(tmp->label);
			m[tmp]=noderoot;
		}
		for(int i=0;i<tmp->neighbors.size();++i)
		{
			UndirectedGraphNode *ctmp;
			if(m[tmp->neighbors[i]]>0)
				ctmp=m[tmp->neighbors[i]];
			else
			{
				ctmp=new UndirectedGraphNode(tmp->neighbors[i]->label);
				m[tmp->neighbors[i]]=ctmp;
			}	
			noderoot->neighbors.push_back(ctmp);
			q.push(m[tmp->neighbors[i]]);
		}
	}
	return m[node];
}

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        map<UndirectedGraphNode *, bool> visited;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty())
        {
            UndirectedGraphNode* front = q.front();
            q.pop();
            
            if(visited[front] == false)
            {
                visited[front] = true;
                
                UndirectedGraphNode* cur;
                if(m.find(front) == m.end())
                {
                    cur = new UndirectedGraphNode(front->label);
                    m[front] = cur;
                }
                else
                {
                    cur = m[front];
                }
                for(int i = 0; i < front->neighbors.size(); i ++)
                {
                    if(m.find(front->neighbors[i]) == m.end())
                    {
                        UndirectedGraphNode* nei = new UndirectedGraphNode(front->neighbors[i]->label);
                        m[front->neighbors[i]] = nei;
                        cur->neighbors.push_back(nei);
                            
                        q.push(front->neighbors[i]);
                    }
                    else
                    {
                        cur->neighbors.push_back(m[front->neighbors[i]]);
                    }
                }
            }
        }
        return m[node];
    }
};