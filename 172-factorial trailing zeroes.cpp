#include<iostream>
using namespace std;

int trailingZeroes(int n)//算的是n!，且2的数量比5多。出现一对2，5增加一个0 
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
