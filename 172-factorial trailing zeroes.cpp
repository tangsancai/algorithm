#include<iostream>
using namespace std;

int trailingZeroes(int n)//�����n!����2��������5�ࡣ����һ��2��5����һ��0 
{
	if(n<1)
		return 0;   
  	int c=0;    
   	while(n/5!=0)
   	{
	   	n/=5;   
     	c+=n;   
    }   
    return c;
} 
