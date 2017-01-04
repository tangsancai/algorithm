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
	int no;//�ýڵ㲻͵ʱ������ 
	int yes;//�ýڵ㴦��������棨͵�벻͵����ȽϺ����������� 
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

money dfs(TreeNode* root)//��ȡ������� 
{
	if(root==NULL)
	{
		return money();
	}
	money leftmoney=dfs(root->left);//���ӽڵ��������� 
	money rightmoney=dfs(root->right);//���ӽڵ��������� 
	money summoney;
	summoney.no=leftmoney.yes+rightmoney.yes;//��ǰ��㲻͵ʱ������Ϊ�����ӽڵ�ġ��������֮�� 
	summoney.yes=max(summoney.no,root->val+leftmoney.no+rightmoney.no);//���������ǡ���ǰ�ڵ㲻͵ʱ�����桿�롾��ǰ�ڵ�͵ʱ�����桿�ȽϵĽ�� 
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