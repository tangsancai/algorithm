#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Node
{
	TreeNode *root;
	int level;
	Node(TreeNode* a,int b):root(a),level(b){} 
};
vector<int> rightSideView(TreeNode* root)
{
	vector<int> v;
	if(root==NULL)
		return v;
	queue<Node> q;
	Node tmp(root,0);
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		if(v.size()<=tmp.level)
			v.push_back(tmp.root->val);
		else
			v[tmp.level]=tmp.root->val;
		if(tmp.root->left!=NULL)
		{
			Node ltmp(tmp.root->left,tmp.level+1);
			q.push(ltmp);
		}
		if(tmp.root->right!=NULL)
		{
			Node rtmp(tmp.root->right,tmp.level+1);
			q.push(rtmp);
		}
	}
	return v;
}