//intΪ10��9�Σ�long longΪ10��18�� 
#include<stdio.h>
int main()
{
	long long A;
	long long B;
	long long C;
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld%lld",&A,&B,&C);
		if(A+B>C)
		{
			printf("Case #%d: true\n",i);
		}
		else
		{
			printf("Case #%d: false\n",i);
		}
	}
} 