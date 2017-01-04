#include<stdio.h>
typedef struct Node
{
	char Id[15];
	char password[15];
	int tag;
};
int main()
{
	Node info[1005];
	int N;
	int j;
	int Num=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s%s",info[i].Id,info[i].password);
		info[i].tag=0;
		j=0;
		while(info[i].password[j]!='\0')
		{
			switch(info[i].password[j])
			{
				case '1':
					info[i].tag=1;
					info[i].password[j]='@';
					break;
				case '0':
					info[i].tag=1;
					info[i].password[j]='%';
					break;
				case 'l':
					info[i].tag=1;
					info[i].password[j]='L';
					break;
				case 'O':
					info[i].tag=1;
					info[i].password[j]='o';
					break;
				default:
					break;
			}
			j++;
		}
		if(info[i].tag==1)
		{
			Num++;
		}
	}
	if(Num)
	{
		printf("%d\n",Num);
		for(int i=0;i<N;i++)
		{
			if(info[i].tag==1)
			{
				printf("%s %s\n",info[i].Id,info[i].password);
			}
		}
	}
	else
	{
		if(N==1)
		{
			printf("There is %d account and no account is modified",N);
		}
		else
		{
			printf("There are %d accounts and no account is modified",N);
		}
	}
}