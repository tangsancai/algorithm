#include<stdio.h>
int data[10000000];
int main()
{
	long long A;
	long long B;
    long long D;
	int i=-1;
	scanf("%lld%lld%lld",&A,&B,&D);
	A=A+B;
	while(A>=D)
	{
		data[++i]=A%D;
		A=A/D;
	}
	data[++i]=A;
	while(i>=0)
	{
		printf("%d",data[i]);
		i--;
	}		
} 