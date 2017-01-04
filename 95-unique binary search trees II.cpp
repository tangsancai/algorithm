#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode*> dp[100][100];
vector<TreeNode*> gt(int s,int e)
{
	vector<TreeNode*> v;
	if(s>e)
		return v;
	if(s==e)
	{
		TreeNode *roottmp=new TreeNode(s);
		v.push_back(roottmp);
		return v;
	}
	if(!dp[s][e].empty())
		return dp[s][e];
	for(int i=s;i<=e;++i)
	{
		vector<TreeNode*> left=gt(s,i-1);
		vector<TreeNode*> right=gt(i+1,e);	
		if(!left.empty()&&right.empty())
			for(int j=0;j<left.size();++j)
			{
				TreeNode *roottmp=new TreeNode(i);
				roottmp->left=left[j];
				v.push_back(roottmp);
			}
		else if(left.empty()&&!right.empty())
			for(int j=0;j<right.size();++j)
			{
				TreeNode *roottmp=new TreeNode(i);
				roottmp->right=right[j];
				v.push_back(roottmp);
			} 
		else
			for(int j=0;j<left.size();++j)
				for(int k=0;k<right.size();++k)
				{
					TreeNode *roottmp=new TreeNode(i);
					roottmp->left=left[j];
					roottmp->right=right[k];
					v.push_back(roottmp);
				}
	}
	dp[s][e]=v;
	return v;
} 
vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> v=gt(1,n);
	return v;
} 
int main()
{
	vector<TreeNode*> v=generateTrees(4);
	for(int i=0;i<v.size();++i)
	{
		queue<TreeNode*> q;
		q.push(v[i]);
 		while(!q.empty())
 		{
 			TreeNode *tmp=q.front();
 			q.pop();
			cout<<tmp->val<<"\t";
			if(tmp->left!=NULL)
				q.push(tmp->left);
			if(tmp->right!=NULL)
				q.push(tmp->right); 	
	 	}
	 	cout<<endl;
	} 
}