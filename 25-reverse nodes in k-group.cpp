#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* reverseKGroup(ListNode* head,int k)
{
	if(!head||!head->next||k==1)
		return head;    
  	ListNode dummy(-1);
   	dummy.next=head;    
    bool isTail=true;
    ListNode *pre=&dummy,*slow=&dummy,*fast=&dummy,*tail=&dummy;
    slow=pre->next;
    while(tail&&slow)
	{
		for(int i=0;i<k;i++)
  			if(tail->next)
     			tail=tail->next;
        	else
			{
   				isTail=false;
       			break;
          	}
            if(!isTail)
                break;
            while(fast!=tail)
			{
                fast=slow->next;   
                slow->next=fast->next;
                fast->next=pre->next;
                pre->next=fast;
            }
            pre=slow;
            tail=slow;
            slow=pre->next;   
   }
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
	ListNode*p=reverseKGroup(&n1,2);
	while(p!=NULL)
	{
		cout<<p->val<<"\t";
		p=p->next;
	}
}