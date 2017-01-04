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
vector< vector<int> > v;
void Travel(TreeNode* root,int level)
{
    if(root==NULL)
    {
	    return;
    }
    if(v.size()<=level)
    {
        vector<int> tmp;
    	v.push_back(tmp);
    }
	v[level].push_back(root->val);
    if(root->left!=NULL)
    {
	    Travel(root->left,level+1);
 	}
  	if(root->right!=NULL)
   	{
	    Travel(root->right,level+1);
   	}
    return;
}
vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
	Travel(root,0);
	int len=v.size();
	for(int i=0;i<len;i++)
	{
		if(i%2!=0)
		{
			vector<int> tmp;
			for(int j=v[i].size()-1;j>=0;j--)
			{
				tmp.push_back(v[i][j]);
			} 
			v[i]=tmp;
		}
	}
	return v;
}