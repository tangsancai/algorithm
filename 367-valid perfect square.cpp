#include<iostream>
using namespace std;

bool isPerfectSquare(int num)
{
	if(num==1||num==4)
	{
		return true;
	}
	int tmp=num%10;
	if(tmp==2||tmp==3||tmp==7||tmp==8)
	{
		return false;
	}
	for(int i=0;i<num/2;i++)
	{
		if(i*i==num)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	if(isPerfectSquare(16))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
} 