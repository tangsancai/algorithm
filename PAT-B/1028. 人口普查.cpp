#include<stdio.h>
#include<string.h>
int maxyear=2015;
int minyear=2014-200+1;
int maxmonth=13;
int minmonth=-1;
int maxday=32;
int minday=-1;
char maxname[10];
char minname[10];
void IsMax(int inputyear,int inputmonth,int inputday,char inputname[])
{
	if(inputyear<maxyear)
	{
		maxyear=inputyear;
		maxmonth=inputmonth;
		maxday=inputday;
		strcpy(maxname,inputname);
	}
	else if(inputyear==maxyear)
	{
		if(inputmonth<maxmonth)
		{
			maxmonth=inputmonth;
			maxday=inputday;
			strcpy(maxname,inputname);
		}
		else if(inputmonth==maxmonth)
		{
			if(inputday<maxday)
			{
				maxday=inputday;
				strcpy(maxname,inputname);
			}
		}
	}
}
void IsMin(int inputyear,int inputmonth,int inputday,char inputname[])
{
	if(inputyear>minyear)
	{
		minyear=inputyear;
		minmonth=inputmonth;
		minday=inputday;
		strcpy(minname,inputname);
	}
	else if(inputyear==minyear)
	{
		if(inputmonth>minmonth)
		{
			minmonth=inputmonth;
			minday=inputday;
			strcpy(minname,inputname);
		}
		else if(inputmonth==minmonth)
		{
			if(inputday>minday)
			{
				minday=inputday;
				strcpy(minname,inputname);
			}
		}
	}
}
int main()
{
	char inputname[10];
 	int inputyear;
 	int inputmonth;
 	int inputday;
 	int num=0;
 	int N;
 	scanf("%d",&N);
 	while(N--)
 	{
	 	scanf("%s %d/%d/%d",inputname,&inputyear,&inputmonth,&inputday);
		if(inputyear>(2014-200)&&inputyear<2014)
		{
			num++;
			IsMax(inputyear,inputmonth,inputday,inputname);
			IsMin(inputyear,inputmonth,inputday,inputname);
		}
		else
		{
			if(inputyear==(2014-200))
			{
				if(inputmonth>9||(inputmonth==9&&inputday>=6))
				{
					num++;
					IsMax(inputyear,inputmonth,inputday,inputname);
					IsMin(inputyear,inputmonth,inputday,inputname);
				}
			}
			else if(inputyear==2014)
			{
				if(inputmonth<9||(inputmonth==9&&inputday<=6))
				{
					num++;
					IsMax(inputyear,inputmonth,inputday,inputname);
					IsMin(inputyear,inputmonth,inputday,inputname);
				}
			}	
		}  				 	
 	}
 	if(num!=0)
 	{
	 	printf("%d %s %s",num,maxname,minname);
 	}
 	else
 	{
	 	printf("0");
 	}
 }