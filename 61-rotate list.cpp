#include<iostream>
#include<string>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k)
{
	if(k==0||head==NULL||head->next==NULL)
		return head;
	ListNode *last=head->next;
	ListNode *newhead;
 	int count=0;
    for(count=2;last->next!=NULL;last=last->next) 
    	count++;
   	if((k%=count)==0)
    	return head;
    last->next=head;
    last=head;
    for(int i=0;i <count-k-1;i++) 
	    last=last->next;
    newhead=last->next;
    last->next=NULL;
	return newhead;
}

int main()
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.next=&a2;
	a2.next=&a3;
	a3.next=&a4;
	a4.next=&a5;
	ListNode *p=rotateRight(&a1,2);
	while(p!=NULL)
	{	
		cout<<p->val<<"\t";
		p=p->next;
	}
}