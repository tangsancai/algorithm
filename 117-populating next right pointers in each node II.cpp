#include<iostream>
#include<vector>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
vector<TreeLinkNode*> v;

void Travel(TreeLinkNode* root,int level)
{
	if(root==NULL)
	{
		return;
	}
	if(v.size()<=level)
	{
		v.push_back(root);
	}
	else
	{
		TreeLinkNode *a=v[level];
		a->next=root;
		v[level]=root; 
	}
	Travel(root->left,level+1);
	Travel(root->right,level+1);
	return;
}
void connect(TreeLinkNode *root)
{
	Travel(root,0);
	int len=v.size();
	for(int i=0;i<len;i++)
	{
		v[i]->next=NULL;
	}
}

int main()
{
	TreeLinkNode root(0);
	connect(&root);
}