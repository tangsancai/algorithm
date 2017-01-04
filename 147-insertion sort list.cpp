#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

ListNode* insertionSortList(ListNode* head)
{
	if(head==NULL||head->next==NULL)
		return head;
 	ListNode *sortedHead = new ListNode(-1);
  	while(head!=NULL)
   	{
	   	ListNode *temp=head->next;
	   	ListNode *cur=sortedHead;
	   	while(cur->next!=NULL&&cur->next->val<head->val)
		   	cur=cur->next;
      	head->next=cur->next;
       	cur->next=head;
        head=temp;
	}
 	return sortedHead->next;
}