#include<iostream>
#include<math.h>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head)
{
	if(head==NULL)
		return;
	ListNode *r=head;
	ListNode *head2=NULL;
	int len=0;
	while(r!=NULL)
	{
		++len;
		if(r->next==NULL)
			head2=r;
		r=r->next;
	}
	if(len<=2)
		return;
	int halflen=ceil((len+0.0)/2.0);
	r=head;	
	for(int i=0;i<halflen-1;++i)
		r=r->next;
	ListNode *p=r->next;
	r->next=NULL;
	while(p!=head2)
	{
		ListNode *q=p->next;
		p->next=head2->next;
		head2->next=p;
		p=q;
	}
	while(head2!=NULL)
	{
		p=head->next;
		r=head2->next;
		head->next=head2;
		head2->next=p;
		head=p;
		head2=r;
	}
}

int main()
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	ListNode a6(6);
	ListNode a7(7);
	a1.next=&a2;
	a2.next=&a3;
	a3.next=&a4;
	a4.next=&a5;
	a5.next=&a6;
	a6.next=&a7;
	reorderList(&a1);
	ListNode *a=&a1;
	while(a!=NULL)
	{
		cout<<a->val<<"\t";
		a=a->next;
	}
}