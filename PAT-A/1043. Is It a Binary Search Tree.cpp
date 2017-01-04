#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
};
int N;
int pre[1005];
int pretemp[1005];
int num;
void insertBST(Node* &root,int x)
{
	if(root==NULL)
	{
		root=new Node;
		root->data=x;
		root->leftchild=NULL;
		root->rightchild=NULL;	
		return;
	}
	if(x<root->data)
	{
		insertBST(root->leftchild,x);
	}
	else
	{
		insertBST(root->rightchild,x);
	}
}
Node* creatBST()
{
	Node* root=NULL;
	for(int i=0;i<N;i++)
	{
		insertBST(root,pre[i]);
	}
	return root;
}
void preTra(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	pretemp[num++]=root->data;
	preTra(root->leftchild);
	preTra(root->rightchild);
}
bool IsBST(Node* root)
{
	num=0;
	preTra(root);
	for(int i=0;i<N;i++)
	{
		if(pretemp[i]!=pre[i])
		{
			return false;
		}
	}
	return true;	
}
void postTra(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	postTra(root->leftchild);
	postTra(root->rightchild);
	printf("%d",root->data);
	num++;
	if(num<N)
	{
		printf(" ");
	}	
}
void insertMBST(Node* &root,int x)
{
	if(root==NULL)
	{
		root=new Node;
		root->data=x;
		root->leftchild=NULL;
		root->rightchild=NULL;	
		return;
	}
	if(x<root->data)
	{
		insertMBST(root->rightchild,x);
	}
	else
	{
		insertMBST(root->leftchild,x);
	}
}
Node* creatMBST()
{
	Node* root=NULL;
	for(int i=0;i<N;i++)
	{
		insertMBST(root,pre[i]);
	}
	return root;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&pre[i]);
	}
	Node* root1=creatBST();
	if(IsBST(root1))
	{
		printf("YES\n");
		num=0;
		postTra(root1);
		return 0;
	}
	Node* root2=creatMBST();
	if(IsBST(root2))
	{
		printf("YES\n");
		num=0;
		postTra(root2);
		return 0;
	}
	printf("NO\n");
}