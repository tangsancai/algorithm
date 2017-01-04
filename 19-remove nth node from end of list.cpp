#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* removeNthFromEnd(ListNode* head,int n)
{
	if(head==NULL) 
		return head;
  	ListNode dummy(0),*t=&dummy,*s=&dummy;//用加一个头节点的方法来处理特殊情况 
   	dummy.next=head;
    while (t&&t->next) 
	{
 		if (n--<=0) 
		 	s=s->next;
    	t=t->next;
    }
    s->next=s->next->next;
    return dummy.next;
}

int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	ListNode* p=removeNthFromEnd(&n1,2);
	for(int i=0;i<4;++i)
		{
			cout<<p->val<<"\t";
			p=p->next;
		}
}