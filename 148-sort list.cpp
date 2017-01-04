#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) 
{
	if(head==NULL||head->next==NULL)
 		return head;
   	ListNode *mid=head,*tail=head;
    while(tail->next!=NULL)
	{
		tail=tail->next;
		if(tail->next==NULL)
  			break;
  		tail=tail->next;
  		mid=mid->next;
    }
	ListNode *right=mid->next,*left=head;
	mid->next=NULL;
	left=sortList(left);
	right=sortList(right);
	return merge(left,right);
}
ListNode* merge(ListNode* l1,ListNode* l2)
{
	ListNode headPre(-1);
	ListNode *now=&headPre;
	while(l1!=NULL || l2!=NULL)
	{
		if(l2==NULL || (l1!=NULL && l1->val<l2->val))
		{
			now->next=l1;
			l1=l1->next;
		}
		else
		{
			now->next=l2;
			l2=l2->next;
		}
		now=now->next;
	}
	return headPre.next;
}