#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxsum=INT_MIN;
int Travel(TreeNode *root)
{
	if(root==NULL)
 	{
	 	return -100000;
	}
	int left=Travel(root->left);
	int right=Travel(root->right);
	maxsum=maxsum>left?maxsum:left;
	maxsum=maxsum>right?maxsum:right;
	int tmp1=left+root->val;
	int tmp2=right+root->val;
	int tmp3=left+right+root->val;
	maxsum=maxsum>tmp3/maxsum:tmp3; 
	int tmp4=root->val;
	tmp1=tmp1>tmp2?tmp1:tmp2;
	return (tmp4>tmp1?tmp4:tmp1); 
}
int maxPathSum(TreeNode* root) 
{
	if(root==NULL)
	{
		return 0;
	}
	int tmp=Travel(root);
	return (tmp>maxsum?tmp:maxsum); 
}