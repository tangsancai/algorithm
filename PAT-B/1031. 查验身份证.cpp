#include<stdio.h>
#include<string.h>
#define X 11
int main()
{
	char number[20];
	int sum;
	int quan[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int M[11]={1,0,X,9,8,7,6,5,4,3,2};
	int Z;
	int n;
	int temp;
	int flag=0;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		scanf("%s",number);
		for(int i=0;i<17;i++)
		{
			sum=sum+quan[i]*(number[i]-'0');
		}
		Z=sum%11;
		if(number[17]=='X')
		{
			temp=X;
		}
		else
		{
			temp=number[17]-'0';
		}
		if(temp!=M[Z])
		{
			printf("%s\n",number);
			flag=1;
		}
	}
	if(!flag)
	{
		printf("All passed");
	}
} 