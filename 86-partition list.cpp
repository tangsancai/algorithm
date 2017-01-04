#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* head, int x)
{
	ListNode *big=NULL;
	ListNode *small=NULL;
	ListNode *newheads=NULL;
	ListNode *newheadb=NULL;
	while(head!=NULL)
	{
    	if(head->val<x)
    	{
    		if(small!=NULL)
    		{
		    	small->next=head;
		    	small=small->next;
		    }		
   			else
   			{
    			small=head;
    			newheads=small;
   			}
   		}
   		else
   		{
    		if(big!=NULL)
    		{
   				big->next=head;
   				big=big->next;
		    }
			else	
    		{
    			big=head;
   				newheadb=big;
   			}	
   		} 
   		ListNode *p=head->next;
   		head->next=NULL;    		
   		head=p;
  	}
  	if(small==NULL)
   		return newheadb;
   	if(big==NULL)
   		return newheads;
   	small->next=newheadb;
   	return newheads;	
} 

int main()
{
	ListNode a1(1);
	ListNode a2(4);
	ListNode a3(3);
	ListNode a4(2);
	ListNode a5(5);
	ListNode a6(2);
	a1.next=&a2;
	a2.next=&a3;
	a3.next=&a4;
	a4.next=&a5;
	a5.next=&a6;
	ListNode *head=partition(&a1,3);
	while(head!=NULL)
	{
		cout<<head->val<<"\t";
		head=head->next;
	}
}