#include<stdio.h>
 int main()
 {
 	int C1;
 	int C2;
 	int mao;
 	int duoyu;
 	scanf("%d%d",&C1,&C2);
 	C1=C2-C1;
    mao=C1/100;
	duoyu=C1%100;
	if(duoyu>=50)
	{
		mao++;
	}
	int hh=mao/3600;
	int mm=(mao-3600*(mao/3600))/60;
	int ss=mao-3600*(mao/3600)-60*((mao-3600*(mao/3600))/60);
	printf("%02d:%02d:%02d",hh,mm,ss);	
 }