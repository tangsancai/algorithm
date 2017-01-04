#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void findm(TreeNode *root,TreeNode *maxx,TreeNode *minn,bool &flag)
{
	if(root==NULL)
		return;
	if((maxx!=NULL&&root->val>=maxx->val)||(minn!=NULL&&root->val<=minn->val))
	{
		flag=false;
		return;
	}
	if(root->left!=NULL)
		findm(root->left,root,minn,flag);	
	if(root->right!=NULL)
		findm(root->right,maxx,root,flag);
}

bool isValidBST(TreeNode* root)
{
	bool flag=true;
	findm(root,NULL,NULL,flag);
	return flag;
}