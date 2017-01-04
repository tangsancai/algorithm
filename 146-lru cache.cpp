#include<iostream>
using namespace std;

class LRUCache{
public:
	struct Node{
		int key;
		int val;
		Node *next;	
		Node(int v,int k):val(v),key(k),next(NULL){}
	};
	Node *head;
	Node *tail;
	int len;
	int maxlen;
    LRUCache(int capacity) {
        len=0;
        maxlen=capacity;
        head=NULL;
        tail=NULL;
    }
    int get(int key) {   	
    	if(len==0)
	    	return -1;
    	int tmp=-1;//get需要重新排 
    	Node *q=head;
    	if(q->key==key)
	    	tmp=q->val;
	    if(tmp!=-1)
    		if(head==tail)
	    		return tmp;
    		else
    		{
	    		head=head->next;
				q->next=tail->next;
				tail->next=q;
				tail=q;
				return tmp; 
	    	}
    	q=head;
        Node *p=head->next;
        while(p!=NULL)
        {
        	if(p->key==key)
        	{
	        	tmp=p->val;
	        	break;
	        }
	        p=p->next;
	        q=q->next;
        }
        if(tmp!=-1&&p==tail)
        	return tmp;
        else if(tmp!=-1&&p!=tail)
        {
        	q->next=p->next;
        	p->next=tail->next;
        	tail->next=p;
        	tail=p;
        }
        return tmp;
    }
    void set(int key, int value) {
    	if(head==NULL)
		{
			head=new Node(value,key);
			tail=head;
			++len;
			return;
		}
		if(get(key)!=-1)
		{
			tail->val=value;
			return;
		}
        if(len<maxlen)
        {
			Node *p=new Node(value,key);
			tail->next=p;
			tail=p;	
			++len;
			return;	
        }
        else
        {
        	head->key=key;
			head->val=value;
			if(head==tail)
				return;
			Node *p=head;
			head=head->next;
			p->next=tail->next;
			tail->next=p;
			tail=p;
			return;	
        }
    }
};


int main()
{
	LRUCache l(3);
	l.set(1,1);
	l.set(2,2);
	l.set(3,3);
	l.set(4,4);
	cout<<"~~~"<<l.get(4)<<endl;
	cout<<"~~~"<<l.get(3)<<endl;
	cout<<"~~~"<<l.get(2)<<endl;
	cout<<"~~~"<<l.get(1)<<endl;
	l.set(5,5);
	cout<<"~~~"<<l.get(1)<<endl;
	cout<<"~~~"<<l.get(2)<<endl;
	cout<<"~~~"<<l.get(3)<<endl;
	cout<<"~~~"<<l.get(4)<<endl;
	cout<<"~~~"<<l.get(5)<<endl;
}