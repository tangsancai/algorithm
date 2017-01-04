#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct Node
{
	int data;
	Node* rchild;
	Node* lchild;
};
int pre[50];
int in[50];
int post[50];
int n;
Node* create(int postL,int postR,int inL,int inR)
{
	if(postL>postR)
	{
		return NULL;
	}
	Node* root=new Node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(post[postR]==in[k])
		{
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=create(postL,postL+numLeft-1,inL,k-1);
	root->rchild=create(postL+numLeft,postR-1,k+1,inR);
	return root;
}
int num=0;
void BFS(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp=q.front();
		printf("%d",temp->data);
		q.pop();
		num++;
		if(num<n)
		{
			printf(" ");
		}
		if(temp->lchild!=NULL)
		{
			q.push(temp->lchild);
		}
		if(temp->rchild!=NULL)
		{
			q.push(temp->rchild);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	Node* root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}