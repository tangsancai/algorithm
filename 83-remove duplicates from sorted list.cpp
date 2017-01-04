#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if(head==NULL||head->next==NULL)
		return head;
	ListNode *pre=head;
	ListNode *post=head->next;
	while(post!=NULL)
	{
		if(pre->val==post->val)
		{
			pre->next=post->next;
			delete post;	
		}
		else
			pre=post;
		post=pre->next;
	}
	return head;
} 