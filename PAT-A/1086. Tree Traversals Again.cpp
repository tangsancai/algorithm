#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
typedef struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
};
int preorder[50];
int inorder[50];
int N;
int num=0;
Node* createTree(int preL,int preR,int inL,int inR)
{
	if(preL>preR)
	{
		return NULL;
	}
	Node* root=new Node;
	root->data=preorder[preL];
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(preorder[preL]==inorder[k])
		{
			break;
		}
	}
	int numleft=k-inL;
	root->lchild=createTree(preL+1,preL+numleft,inL,k-1);
	root->rchild=createTree(preL+numleft+1,preR,k+1,inR);
	return root;
}
void postOrderTra(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	postOrderTra(root->lchild);
	postOrderTra(root->rchild);
	printf("%d",root->data);
	num++;
	if(num<N)
	{
		printf(" ");
	}	
}
int main()
{
	char op[10];
	int numpre=0;
	int numin=0;
	stack<int> s;
	scanf("%d",&N);
	for(int i=0;i<2*N;i++)
	{
		scanf("%s",op);
		if(!strcmp(op,"Push"))
		{
			int temp;
			scanf("%d",&temp);
			preorder[numpre++]=temp;
			s.push(temp);
		}
		else if(!strcmp(op,"Pop"))
		{
			int temp=s.top();
			inorder[numin++]=temp;
			s.pop();	
		}
	}
	Node* root=createTree(0,numpre-1,0,numin-1);
	postOrderTra(root);
}