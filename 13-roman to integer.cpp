#include<string>
#include<iostream>
using namespace std;
int romanToInt(string s)
{
	int accNum=0;
 	convertRomanToInt(0,s,accNum);
  	return(accNum);
}
int convertRomanToInt(int pos,string &s,int &accNum)
{
	int num=0;
	int prevNum=0;
	if(pos==s.length()-1)
	{
		num=getNumFromRoman(s[pos]);
		accNum=num;
		return(num);
  	}
   	prevNum=convertRomanToInt(pos+1,s,accNum);
    num=getNumFromRoman(s[pos]);
    if(prevNum>num)
	{
		accNum -= prevNum;
  		accNum += prevNum - num;
    }
	else
	{
 		accNum += num;
   	}
   	return num;
}
    
int getNumFromRoman(char c)
{
	switch(c)
	{
	case 'M':
            return 1000;
 	case 'D':
            return 500;
 	case 'C':
            return 100;
  	case 'L':
            return 50;
   	case 'X':
            return 10;
    case 'V':
            return 5;
    default:
            return 1;
    }
}