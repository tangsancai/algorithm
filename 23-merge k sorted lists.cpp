#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
//头节点全摘下来，排一排，取最小的，然后在最小的队列中取节点加入，排一排。。。 
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	int n = lists.size();
 	if(n == 0){return nullptr;}
  	else if(n == 1){return lists[0];}
   	else if(n == 2){return merge2Lists(lists[0],lists[1]);}
    else
    {
    	vector<ListNode*> part1(lists.begin(), lists.begin() + (lists.end() - lists.begin())/2);
     	vector<ListNode*> part2(lists.begin() + (lists.end() - lists.begin())/2 ,lists.end());
      	return merge2Lists(mergeKLists(part1),mergeKLists(part2));
    }
}
ListNode* merge2Lists(ListNode* root1, ListNode* root2)
{
	if(root1 == NULL) return root2;
 	if(root2 == NULL) return root1;
  	ListNode dummy(0);
  	ListNode* p = &dummy;
    while(root1 != NULL && root2 != NULL)
    {
     	if(root1->val >= root2->val)
        {
			p->next = root2;
			p = p->next;
			root2 = root2->next;
		}
		else
		{
			p->next = root1;
			p = p->next;
			root1 = root1->next;
		}
	}
	if(root1 != NULL){p->next = root1;}
	else if (root2 != NULL){p->next = root2;}
	return dummy.next;
}