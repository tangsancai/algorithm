#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{	
	if(head==NULL||head->next==NULL)
		return head;
	ListNode *newhead=head;
	while(newhead->next!=NULL)
		newhead=newhead->next;
	while(head!=newhead)
	{
		ListNode *p=head->next;
		head->next=newhead->next;
		newhead->next=head;
		head=p;	
	}
	return newhead;
}