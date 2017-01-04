#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool flag=true; 
void Travel(TreeNode* p,TreeNode* q)
{
	if(p==NULL&&q==NULL)
	{
		return;
	}
	if(p==NULL||q==NULL)
	{
		flag=false;
		return;
	}
	if(p->val!=q->val)
	{
		flag=false;
		return;
	}
	Travel(p->left,q->left);
	Travel(p->right,q->right); 
}
bool isSameTree(TreeNode* p, TreeNode* q)
{
	Travel(p,q);
	return flag;
}

int main()
{
} 