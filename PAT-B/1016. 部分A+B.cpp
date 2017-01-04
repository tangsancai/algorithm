#include<stdio.h>
#include<string.h>

int main()
{
	char A[15];
	int DA;
	char B[15];
	int DB;
	scanf("%s%d%s%d",A,&DA,B,&DB);
	int i=-1;
	int suma=0;
	int sumb=0;
	while(A[++i]!='\0')
	{
		if((A[i]-'0')==DA)
		{
			suma=suma*10+DA;
		}
	}
	i=-1;
	while(B[++i]!='\0')
	{
		if((B[i]-'0')==DB)
		{
			sumb=sumb*10+DB;
		}
	}
	printf("%d",suma+sumb);
} 