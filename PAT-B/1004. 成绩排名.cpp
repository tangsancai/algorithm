#include<stdio.h>
#include<string.h>
int main()
{
	int nn;
	scanf("%d",&nn);
	char name[15];
	char namemax[15];
	char namemin[15];
	char no[15];
	char nomax[15];
	char nomin[15];
	int score;
	int scoremax=-1;
	int scoremin=101;
	for(int i=0;i<nn;i++)
	{
		scanf("%s%s%d",&name,&no,&score);
		if(score>scoremax)
		{
			scoremax=score;
			strcpy(namemax,name);
			strcpy(nomax,no);
		}
		if(score<scoremin)
		{
			scoremin=score;
			strcpy(namemin,name);
			strcpy(nomin,no);
		}
	}
	printf("%s %s\n",namemax,nomax);
	printf("%s %s\n",namemin,nomin);
} 