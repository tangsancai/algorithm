#include<vector>
#include<iostream>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* Travel(int root,vector<int> &preorder,vector<int> &inorder,int s,int e)
{
		int len=e-s;
	    if(len<0)
	    {
		    return NULL;
	    }
	    int i;
	    int posl;
	    int posr;
	    int ls,le,rs,re;
	    ls=s;
	    for(i=s;i<=e;++i)
	    {
		    if(inorder[i]==preorder[root])
		    {
			    break;
		    }
	    }
	    le=i-1;
	    TreeNode *node;
	    node=new TreeNode(inorder[i]);
	    ++i;
	    rs=i;
	    re=e;
	    posl=root+1;
	    posr=root+(le-ls+1)+1;
	    node->left=Travel(posl,preorder,inorder,ls,le);
	    node->right=Travel(posr,preorder,inorder,rs,re);
	    return node;
} 


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	if(inorder.size()==0)
	{
		return NULL;
	}
	TreeNode* a= Travel(0,preorder,inorder,0,inorder.size()-1);
	return a;
}


int main()
{
	vector<int> pre;
	vector<int> in;
	pre.push_back(-1);
	in.push_back(-1);
	TreeNode *p=buildTree(pre,in);
	cout<<p->val<<endl;
	cout<<p->left<<endl;
	cout<<p->right<<endl;
}