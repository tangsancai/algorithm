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
	ListNode *newhead=new ListNode(INT_MIN);
	newhead->next=head;
	ListNode *pre=newhead;
	while(head!=NULL)
	{
		ListNode *post=head;
		int val=head->val;
		while(post->next!=NULL&&post->next->val==val)
			post=post->next;
		if(head!=post)
		{
			pre->next=post->next;
			head=pre->next;
		}
		else
		{
			pre=pre->next;
			head=head->next;
		}
	} 
	return newhead->next;
}