#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum=0; 
void getsum(TreeNode* root,int s)
{
	if(root->left==NULL&&root->right==NULL)
	{
		sum+=s*10+root->val;
		return;
	}
 	if(root->left!=NULL)
  		getsum(root->left,s*10+root->val);
    if(root->right!=NULL)
    	getsum(root->right,s*10+root->val);
} 


int sumNumbers(TreeNode* root) 
{
	if(root==NULL)
	{
		return 0;
	}
	getsum(root,0);
	return sum;
}

int main()
{
	TreeNode t1(1);
	TreeNode t3(3);
	TreeNode t0(0);
	t0.left=&t1;
	t0.right=&t3; 
	cout<<sumNumbers(&t0);
}