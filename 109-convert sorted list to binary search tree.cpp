#include<iostream>
using namespace std;
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
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

TreeNode* sortedListToBST(ListNode* head)
{
	vector<int> nums;
	while(head!=NULL)
	{
		nums.push_back(head->val);
		head=head->next;	
	}
	return Travel(nums,0,nums.size()-1);
}