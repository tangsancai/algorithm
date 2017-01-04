#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if(headA==NULL||headB==NULL)
		return NULL;
	int numb=0,numa=0;
	ListNode *a=headA;
	ListNode *b=headB;
	while(a->next!=NULL)
	{
		++numa;
		a=a->next;
	} 
	while(b->next!=NULL)
	{
		++numb;
		b=b->next;
	}
	if(a!=b)
		return NULL;
	int num=numb-numa;
	if(num<0)
		while(num!=0)
		{
			++num;
			headA=headA->next;
		}
	else if(num>0)
		while(num!=0)
		{
			--num;
			headB=headB->next;
		}
	while(headB!=NULL)
	{
		if(headA==headB)
			return headA;
		headA=headA->next;
		headB=headB->next;
	}
	return NULL;
}