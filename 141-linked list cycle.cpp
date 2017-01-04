#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

bool hasCycle(ListNode *head)
{
	ListNode *p;
	p=head;
	int i;
	for(i=0;i<10000&&p!=NULL;++i)
		p=p->next;
	if(i<10000)
		return false;
	return true;
}