#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> v[100];
void Travel(TreeNode *root,int level)
{
	if(root==NULL)
	{
		return;
	} 
	if(root->left!=NULL)
	{
		v[level].push_back(root->left->val);  
		Travel(root->left,level+1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   )	
	}
	else 
	{
		v[level].push_back(-1);
	}
	if(root->right!=NULL)
	{
		v[level].push_back(root->right->val);  
		Travel(root->right,level+1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   )	
	}
	else 
	{
		v[level].push_back(-1);
	}
	return;
} 

bool isSymmetric(TreeNode* root) 
{
	Travel(root,0);
	for(int i=0;i<100;i++)
	{
		int len=v[i].size();
		for(int j=0;j<len;j++)
		{
			if(v[i][j]!=v[i][len-j-1])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	
}