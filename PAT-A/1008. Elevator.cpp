#include<stdio.h>
int main()
{
	int N;
	int a=0;
	int b;
	int timesum=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&b);
		if(b>a)
		{
			timesum=timesum+(b-a)*6+5;
		}	
		else if(b<a)
		{
			timesum=timesum+(a-b)*4+5;
		}
		else
		{
			timesum=timesum+5;
		}
		a=b;
	}
	printf("%d",timesum);
}