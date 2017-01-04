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

void inorder(TreeNode* root,vector<int> &v)
{
	if(root==NULL)
		return;
	inorder(root->left,v);
	v.push_back(root->val);
	inorder(root->right,v);	
}

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> v;
	inorder(root,v);
	return v;	
}