#include<stdio.h>
#include<string.h>
typedef struct Node
{
	char name[20];
	char id[20];
	char gender[2];
	int grade;
};
int main()
{
	Node man;
	Node woman;
	Node temp;
	int N;
	scanf("%d",&N);
	man.grade=101;
	woman.grade=-1;
	while(N--)
	{
		scanf("%s%s%s%d",temp.name,temp.gender,temp.id,&temp.grade);
		if(!strcmp(temp.gender,"M"))
		{
			if(temp.grade<man.grade)
			{
				man=temp;
			}
		}
		else if(!strcmp(temp.gender,"F"))
		{
			if(temp.grade>woman.grade)
			{
				woman=temp;
			}
		}
	}
	if(woman.grade==-1)
	{
		printf("Absent\n");
	}
	else
	{
		printf("%s %s\n",woman.name,woman.id);
	}
	if(man.grade==101)
	{
		printf("Absent\n");
	}
	else
	{
		printf("%s %s\n",man.name,man.id);
	}
	if(man.grade!=101&&woman.grade!=-1)
	{
		printf("%d",woman.grade-man.grade);
	}
	else
	{
		printf("NA");
	}
}