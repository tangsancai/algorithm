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

TreeNode* Travel(vector<int> &nums,int s,int e)
{
	if(e-s<0)
	{
		return NULL;
	}	
	int pos=(s+e)/2;
	TreeNode *node;
	node=new TreeNode(nums[pos]);
	node->left=Travel(nums,s,pos-1);
	node->right=Travel(nums,pos+1,e);
	return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	return Travel(nums,0,nums.size()-1);
}