#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct money
{
	int no;//该节点不偷时的收益 
	int yes;//该节点处【最大】收益（偷与不偷【相比较后】做出决定） 
	money():no(0),yes(0){}
};

int rob(TreeNode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	money sum=dfs(root);
	return sum.yes;
}

money dfs(TreeNode* root)//获取收益情况 
{
	if(root==NULL)
	{
		return money();
	}
	money leftmoney=dfs(root->left);//左子节点的收益情况 
	money rightmoney=dfs(root->right);//右子节点的收益情况 
	money summoney;
	summoney.no=leftmoney.yes+rightmoney.yes;//当前结点不偷时，收益为两个子节点的【最大】收益之和 
	summoney.yes=max(summoney.no,root->val+leftmoney.no+rightmoney.no);//最终收益是【当前节点不偷时的收益】与【当前节点偷时的收益】比较的结果 
	return summoney; 
}



int main()
{
	TreeNode n3(3);
	n3.left=NULL;
	n3.right=NULL;
	
	TreeNode n2(2);
	n2.left=NULL;
	n2.right=&n3;
	
	TreeNode n1(1);
	n1.left=NULL;
	n1.right=NULL;
	
	TreeNode n32(3);
	n32.left=NULL;
	n32.right=&n1;
	
	TreeNode root(3);
	root.left=&n2;
	root.right=&n32;
	rob(&root);
	cout<<maxnum;
	return 0;
}