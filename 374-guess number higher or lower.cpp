#include<iostream>
using namespace std;

int guess(int num)
{
	if(num<1702766719)
		return -1;
	if(num>1702766719)
		return 1;
	return 0;
}
int guessNumber(int n)
{
	int s=1;
	int e=n;
	int temp;
	while(1)
	{
		temp=(s/2+e/2);
		if(s%2!=0&&e%2!=0)
		{
			temp++;
		}
		switch(guess(temp))
		{
			case 1:
				e=temp+1;
				break;
			case -1:
				s=temp-1;
				break;
			case 0:
				return temp;
		}	
	}
} 

int main()
{
	guessNumber(2126753390);
	return 0;
} 