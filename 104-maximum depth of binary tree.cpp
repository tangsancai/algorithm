#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int layer=0;
void  Travel(TreeNode* root,int level)
{
	if(root==NULL)
	{
		if(level>layer)
		{
			layer=level;
		}
		return; 
	}
	Travel(root->left,level+1);
	Travel(root->right,level+1);
}
int maxDepth(TreeNode* root)
{
	Travel(root,0);
	return layer;
}