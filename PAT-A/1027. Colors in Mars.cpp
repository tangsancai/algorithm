#include<stdio.h>
void getNum(int color)
{
	if(color/13<10)
	{
		printf("%d",color/13);
	}
	else
	{
		switch(color/13)
		{
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
		} 
	}
	if(color%13<10)
	{
		printf("%d",color%13);
	}
	else
	{
		switch(color%13)
		{
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
		} 
	}
} 
int main()
{
	int red;
	int green;
	int blue;	
	scanf("%d%d%d",&red,&green,&blue);
	printf("#");
	getNum(red);
	getNum(green);
	getNum(blue);
}