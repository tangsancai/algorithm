#include<stdio.h> 
void Number(int n, int flag)
{
	switch(n)
	{
		case 0:
			printf("ling");
			break;
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
	}
	if(flag==0)
	{
		printf(" ");
	}
}
int main()
{
	int i=0;
	int sum=0;
	char str[105];
	scanf("%s",str);
	while(str[i]!='\0')
	{
		sum=sum+(str[i]-'0');
		i++;
	}	
	if(sum/100!=0)
	{
		Number(sum/100,0);
		sum=sum-100*(sum/100);
		Number(sum/10,0);
		sum=sum-10*(sum/10);
		Number(sum,1);
	}
	else if(sum/10!=0)
	{
		Number(sum/10,0);
		sum=sum-10*(sum/10);
		Number(sum,1);
	}
	else
	{
		Number(sum,1);
	}
	
}