#include<iostream>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool Travel(TreeNode* root,int sum)
{
	if(root->val==sum&&root->left==NULL&&root->right==NULL)
	{
		return true;
	}
	bool l=false;
	bool r=false;
	if(root->left!=NULL)
	{
		l=Travel(root->left,sum-root->val);
	}
	if(root->right!=NULL)
	{
		r=Travel(root->right,sum-root->val);
	}
	return (l|r); 
}
bool hasPathSum(TreeNode* root, int sum) 
{
	if(root==NULL)
	{
		return false;	
	}
	return Travel(root,sum);
}
int main()
{
	TreeNode node(-3);
	node.left=NULL;
	node.right=NULL;
	
	TreeNode node2(-2);
	node.left=NULL;
	node.right=&node;
	
	hasPathSum(&node2,-5);
}