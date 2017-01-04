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
struct Node
{
	TreeNode * gen;
	int tag;
	Node(TreeNode* a):gen(a),tag(0){}
	Node(){}
};
vector<int> postorderTraversal(TreeNode* root)
{
	stack<Node> st;
	Node tmp(root);
	st.push(tmp);
	vector<int> v; 
	if(root==NULL)
		return v;
	while(!st.empty())
	{
		tmp=st.top();
		if(tmp.tag==2)
			v.push_back(tmp.gen->val);
		st.pop();
		if(tmp.tag==0)
		{
			Node ltmp;
			ltmp.gen=tmp.gen;
			ltmp.tag=tmp.tag+1; 
			st.push(ltmp);
			if(tmp.gen->left!=NULL)
			{
				Node tmpl(tmp.gen->left);
				st.push(tmpl); 
			}
		}
		if(tmp.tag==1)
		{
			Node rtmp;
			rtmp.gen=tmp.gen;
			rtmp.tag=tmp.tag+1;
			st.push(rtmp);
			if(tmp.gen->right!=NULL)
			{
				Node tmpr(tmp.gen->right);
				st.push(tmpr);
			}
		}
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
	vector<int> v=postorderTraversal(&a1);
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<"\t";
	}
}