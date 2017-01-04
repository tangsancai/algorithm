#include<stdio.h>
int main()
{
	int Galleon1;
	int Sickle1;
	int Knuts1;
	int Galleon2;
	int Sickle2;
	int Knuts2;
	int Galleon;
	int Sickle;
	int Knuts;
	scanf("%d.%d.%d %d.%d.%d",&Galleon1,&Sickle1,&Knuts1,&Galleon2,&Sickle2,&Knuts2);
	Knuts=(Knuts1+Knuts2)%29;
	Sickle=((Knuts1+Knuts2)/29+Sickle1+Sickle2)%17;
	Galleon=((Knuts1+Knuts2)/29+Sickle1+Sickle2)/17+Galleon1+Galleon2;
	printf("%d.%d.%d\n",Galleon,Sickle,Knuts);
}