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

TreeNode* Travel(vector<int> &inorder,vector<int> &postorder,int root,int s,int e)
{
	if(e-s<0)
	{
		return NULL;
	}
	int ls,le,rs,re;
	int i;
	ls=s;
	for(i=s;i<=e;i++)
	{
		if(postorder[root]==inorder[i])
		{
			break;
		}
	}
	le=i-1;
	TreeNode *node;
	node=new TreeNode(inorder[i]);
	i++;
	rs=i;
	re=e;
	node->left=Travel(inorder,postorder,root-(re-rs+1)-1,ls,le);
	node->right=Travel(inorder,postorder,root-1,rs,re);
	return node;
} 

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if(inorder.size()==0)
	{
		return NULL;
	}
	TreeNode *a=Travel(inorder,postorder,inorder.size()-1,0,inorder.size()-1);
	return a;
}
int main()
{
	vector<int> post;
	vector<int> in;
	post.push_back(2);
	post.push_back(1);
	in.push_back(2);
	in.push_back(1);
	TreeNode *p=buildTree(in,post);
} 