#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

ListNode *detectCycle(ListNode *head)
{
	ListNode *p,*q;
	p=head;
	q=head;
	int i,j;
	for(i=0;i<10000&&p!=NULL;++i)
		p=p->next;
	if(i<10000)
		return NULL;
	j=0;
	while(p!=q)
	{
		q=q->next;
		++j;
	}
	int z=i-j;
	for(int k=0;k<=j;++k)
	{
		q=head;
		p=head;
		for(int k1=0;k1<k;++k1)
		{
			q=q->next;
			p=p->next;
		}	
		for(int k1=0;k1<z;++k1)
			q=q->next;
		if(q==p)
			break;
	}
	return p;
}

int main()
{
	ListNode a(-21);ListNode a2(10);ListNode a3(17);ListNode a4(8);ListNode a5(4);
	ListNode a6(26);ListNode a7(5);ListNode a8(35);ListNode a9(33);ListNode a10(-7);
	ListNode a11(-16);ListNode a12(27);ListNode a13(-12);ListNode a14(6);ListNode a15(29);
	ListNode a16(12);ListNode a17(5);ListNode a18(9);ListNode a19(20);ListNode a20(14);
	ListNode a21(14);ListNode a22(2);ListNode a23(13);ListNode a24(-24);ListNode a25(21);
	ListNode a26(23);ListNode a27(-21);ListNode a28(5);
	a.next=&a2;a2.next=&a3;a3.next=&a4;a4.next=&a5;a5.next=&a6;a6.next=&a7;a7.next=&a8;a8.next=&a9;a9.next=&a10;a10.next=&a11;
	a11.next=&a12;a12.next=&a13;a13.next=&a14;a14.next=&a15;a15.next=&a16;a16.next=&a17;a17.next=&a18;a18.next=&a19;a19.next=&a20;a20.next=&a21;
	a21.next=&a22;a22.next=&a23;a23.next=&a24;a24.next=&a25;a25.next=&a26;a26.next=&a27;a27.next=&a28;a28.next=&a28;
	cout<<detectCycle(&a)->val;
}