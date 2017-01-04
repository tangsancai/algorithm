#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root)
{
	stack<TreeNode*> q;
	vector<int> v;
	if(root==NULL)
		return v;
	while(!q.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
			v.push_back(root->val);
			q.push(root);//只压本身就无需区分左子树还是右子树了 
			root=root->left;
		}	
		root=q.top();
		q.pop();
		root=root->right;
	} 
	return v;
}

int main()
{
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	TreeNode a6(6);
	TreeNode a7(7);
	TreeNode a8(8);
	TreeNode a9(9);
	a1.left=&a2;
	a1.right=&a3;
	a2.left=&a4;
	a2.right=&a5;
	a4.right=&a6;
	a6.left=&a7;
	a3.left=&a8;
	a3.right=&a9;
	vector<int> v=preorderTraversal(&a1);
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<"\t";
	}
}