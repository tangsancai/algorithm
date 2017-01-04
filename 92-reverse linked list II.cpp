#include<iostream>
using namespace std;

struct ListNode 
{	
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if(m==n)
		return head;
  	ListNode **phead=&head;
  	ListNode **pp=&head;
   	n=n-m;
    while(--m) 
		pp=&((*pp)->next);
  	ListNode *pStart=*pp;
   	ListNode *pNext=NULL;
    while(n--)
	{
		pNext=pStart->next;
		pStart->next=pNext->next;
		pNext->next=*pp;
		*pp=pNext;
  	}
  	return *phead;
} 