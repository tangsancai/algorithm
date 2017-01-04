#include<string.h>
#include<stdio.h>
int main()
{
	int N;
	int i;
	int j;
	int num;
	char temp[300];
	char same[300];
	char input[300];
	scanf("%d",&N);
	getchar();
	gets(input);
	strcpy(same,input);
	N--;
	while(N--)
	{
		gets(input);
		memset(temp,'\0',sizeof(temp));
		num=0;
		for(i=strlen(same)-1,j=strlen(input)-1;i>=0&&j>=0;i--,j--)
		{
			if(same[i]==input[j])
			{
				temp[num++]=same[i];	
			}
			else
			{
				break;
			}
		}
		memset(same,'\0',sizeof(same));
		for(i=0;i<num;i++)
		{
			same[i]=temp[num-1-i];
		}
	}
	if(strlen(same))
	{
		printf("%s",same);
	}
	else
	{
		printf("nai");
	}
}