#include<stdio.h>
#include<string.h>
char signinname[20];
char signoutname[20];
int signinhh=25;
int signinmm=61;
int signinss=61;
int signouthh=-1;
int signoutmm=-1;
int signoutss=-1;
void compareIn(int hh,int mm,int ss,char name[])
{
	if(hh<signinhh)
	{
		signinhh=hh;
		signinmm=mm;
		signinss=ss;
		strcpy(signinname,name);
	}
	else if(hh==signinhh)
	{
		if(mm<signinmm)
		{
			signinmm=mm;
			signinss=ss;
			strcpy(signinname,name);
		}
		else if(signinmm==mm)
		{
			if(ss<signinss)
			{
				signinss=ss;
				strcpy(signinname,name);
			}	
		}
	}
}
void compareOut(int hh,int mm,int ss,char name[])
{
	if(hh>signouthh)
	{
		signouthh=hh;
		signoutmm=mm;
		signoutss=ss;
		strcpy(signoutname,name);
	}
	else if(hh==signouthh)
	{
		if(mm>signoutmm)
		{
			signoutmm=mm;
			signoutss=ss;
			strcpy(signoutname,name);
		}
		else if(signoutmm==mm)
		{
			if(ss>signoutss)
			{
				signoutss=ss;
				strcpy(signoutname,name);
			}	
		}
	}
}
int main()
{
	int N;
	int hh;
	int mm;
	int ss;
	char name[20];
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",name);
		scanf("%d:%d:%d",&hh,&mm,&ss);
		compareIn(hh,mm,ss,name);
		scanf("%d:%d:%d",&hh,&mm,&ss);
		compareOut(hh,mm,ss,name);
	}
	printf("%s %s",signinname,signoutname);
}