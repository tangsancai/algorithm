#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void flatten(TreeNode* root)
{
	if(root->left!=NULL&&root->right!=NULL)
	{
		flatten(root->left);
		flatten(root->right);
		TreeNode *p=root->left;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=root->right;
		root->right=root->left;
		root->left=NULL;
	}
	if(root->left!=NULL&&root->right==NULL)
	{
		flatten(root->left);
		root->right=root->left;
		root->left=NULL;
	}
	if(root->left==NULL&&root->right!=NULL)
	{
		flatten(root->right);
	}
	if(root->left==NULL&&root->right==NULL)
	{
		return;
	}
}