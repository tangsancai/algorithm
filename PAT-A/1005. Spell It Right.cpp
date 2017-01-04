#include<stdio.h>
void Printf(int num)
{
	switch(num)
	{
		case 0:
			printf("zero");
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
	}
} 
int main()
{
	int sum=0;
	int i=0;
	char input[1000];
	int data[1000];
	scanf("%s",input);
	while(input[i]!='\0')
	{
		sum=sum+(input[i]-'0');
		i++;
	}
	i=0;
	while(sum/10)
	{
		data[i++]=sum%10;
		sum=sum/10;
	}
	data[i]=sum%10;
	for(int j=i;j>0;j--)
	{
		Printf(data[j]);
		printf(" ");
	}
	Printf(data[0]);
}