#include<iostream>
#include<map>
using namespace std;
struct RandomListNode 
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head)
{
	if(head==NULL)
		return NULL;
	map<RandomListNode* ,RandomListNode*> m; 
	RandomListNode *p=head;
	RandomListNode *newlisthead=new RandomListNode(p->label);
	RandomListNode *q2=newlisthead;
	m[p]=newlisthead;
	p=p->next;
	while(p!=NULL)
	{
		RandomListNode *q=new RandomListNode(p->label);
		m[p]=q;
		q2->next=q;
		q2=q;
		p=p->next;	
	}
	p=head;
	q2=newlisthead;
	while(p!=NULL)
	{
		q2->random=m[p->random];
		p=p->next;
		q2=q2->next;	
	}
	return newlisthead;
}