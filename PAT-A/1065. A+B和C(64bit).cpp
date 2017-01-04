//转double做只能有一部分用例通过 
#include<stdio.h>
int main()
{
	int M;
	long long A;
	long long B;
	long long C;
	long long res;
	scanf("%d",&M);
	for(int i=1;i<=M;i++)
	{
		scanf("%lld%lld%lld",&A,&B,&C);
		res=A+B;
		if(A>0&&B>0&&res<0)
			printf("Case #%d: true\n",i);
		else if(A<0&&B<0&&res>=0)
			printf("Case #%d: false\n",i);
		else if(res>C)
			printf("Case #%d: true\n",i);
		else
			printf("Case #%d: false\n",i);
	}
}