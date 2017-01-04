#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeElements(ListNode* head, int val)
{
	ListNode *newhead=new ListNode(-1);
	newhead->next=head;
	ListNode *pre=newhead;
	ListNode *post=head;
	while(post!=NULL)
	{
		if(post->val==val)
		{
			post=post->next;
			pre->next=post;
		}
		else
		{
			pre=post;
			post=post->next;
		}	
	} 
	return newhead->next;
}