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
 
void Travel(TreeNode* root,int sum,vector<int> vtmp)
{
	if(root->val==sum&&root->left==NULL&&root->right==NULL)
	{
		vtmp.push_back(root->val);
		v.push_back(vtmp);
		return;
	}
	vtmp.push_back(root->val);
	if(root->left!=NULL)
	{
		Travel(root->left,sum-root->val,vtmp);
	}
	if(root->right!=NULL)
	{
		Travel(root->right,sum-root->val,vtmp);
	}
	return; 
}
bool hasPathSum(TreeNode* root, int sum) 
{
	if(root==NULL)
	{
		return false;	
	}
	return Travel(root,sum);
}