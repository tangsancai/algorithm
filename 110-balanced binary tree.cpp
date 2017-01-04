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
bool isBalanced(TreeNode *root) 
{
	if(root == NULL)
	{
		return true; 
	}
	else
	{
		int l = height(root->left);
		int r = height(root->right);
		if(l-r >= -1 && l-r <= 1)
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
		else 
		{
			return false;  
        }  
    }  
}
int height(TreeNode *root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		if(root->left == NULL)
		{
			return height(root->right) + 1;
		}
		else if(root->right == NULL)
		{
			return height(root->left) + 1;
		}
		else
		{
			int l = height(root->left);
			int r = height(root->right);
			return l<r?(r+1):(l+1);
		}  
  	}  
}