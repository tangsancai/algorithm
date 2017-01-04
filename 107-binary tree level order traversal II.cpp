#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector< vector<int> > v;
void Travel(int level,TreeNode *root)
{
	if(root==NULL)
	{
		return;
	}
	if(v.size()<=level)
	{
		vector<int> tmp;
		v.push_back(tmp);
	}
	v[level].push_back(root->val);
	if(root->left!=NULL)
	{
		Travel(level+1,root->left);
	}
	if(root->right!=NULL)
	{
		Travel(level+1,root->right);
	} 
	return;
}
 
vector< vector<int> > levelOrderBottom(TreeNode* root)
{
	Travel(0,root);
	vector< vector<int> > v1;
	int len=v.size();
	for(int i=len-1;i>=0;i--)
	{
		v1.push_back(v[i]);
	}
	return v1;
}