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
class BSTIterator {
private:
	void vis(TreeNode* root)
	{
		if(root==NULL)
			return;
		if(root->left!=NULL)
			vis(root->left);
		node.push_back(root->val);
		if(root->right!=NULL)
			vis(root->right);
	}
public:
	vector<int> node;
	int pos;
	int val;
    BSTIterator(TreeNode *root) {
        vis(root);
        pos=0;
    }
    bool hasNext() {
    	if(node.size()==0)
    		return false;
	    else if(pos<=node.size()-1)
	    {
    		val=node[pos++];
	    	return true;
    	}
	    return false;
    }
    int next() {
        return val;
    }
};

int main()
{
	TreeNode root(1);
	TreeNode root2(2);
	TreeNode root0(0);
	root.left=&root0;
	root.right=&root2;
	BSTIterator i = BSTIterator(&root);
 	while (i.hasNext()) 
	 	cout << i.next()<<endl;
}