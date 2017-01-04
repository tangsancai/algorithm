#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* swapPairs(ListNode* head)
{
	if(head==NULL||head->next==NULL)
		return head;
	ListNode *pre=head;
	ListNode *post=head->next;
	ListNode *postnext=post->next;
	ListNode *tmp=NULL; 
	pre->next=post->next;
	post->next=pre;
	head=post;

	tmp=pre;
	pre=postnext;
	if(pre==NULL||pre->next==NULL)
		return head;
 	post=pre->next;
 	postnext=post->next;
 	while(1)
 	{
		 pre->next=post->next;
		 post->next=pre;
		 tmp->next=post;
		 tmp=pre;
		 pre=postnext;
		 if(pre==NULL||pre->next==NULL)
			return head;
		 post=pre->next;
		 postnext=post->next;	
 	}
 	return head;
} 
int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	ListNode*p=swapPairs(&n1);
	while(p!=NULL)
	{
		cout<<p->val<<"\t";
		p=p->next;
	}
}