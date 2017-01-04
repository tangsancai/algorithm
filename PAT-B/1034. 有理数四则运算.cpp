#include<stdio.h>
typedef struct Faction
{
	long long son;
	long long mother;
};
int Gcd(long long mmax,long long mmin)
{
	if(mmin==0)
	{
		return mmax;
	}	
	else
	{
		return Gcd(mmin,mmax%mmin);
	}
}
int PrintfFaction(Faction a)
{
	int gcd;
	if(a.son>a.mother)
	{
		gcd=Gcd(a.son,a.mother);
	}
	else
	{
		gcd=Gcd(a.mother,a.son);
	}
	a.son=a.son/gcd;
	a.mother=a.mother/gcd;
	if(a.mother<0)
	{
		a.mother=-a.mother;
		a.son=-a.son;
	}
	else if(a.mother==0)
	{
		printf("Inf");
		return 0;
	}
	if(a.son<0)	
	{
		printf("(");
		if(a.mother==1)
		{
			printf("%lld",a.son);
		}
		else
		{
			if(-a.son<a.mother)
			{
				printf("%lld/%lld",a.son,a.mother);
			}
			else
			{
				long long sson=-a.son;
				printf("-%lld %lld/%lld",sson/a.mother,sson%a.mother,a.mother);
			}
		}
		printf(")");
	}
	else if(a.son==0)
	{
		printf("0");	
	}
	else
	{
		if(a.mother==1)
		{
			printf("%lld",a.son);
		}
		else
		{
			if(a.son<a.mother)
			{
				printf("%lld/%lld",a.son,a.mother);
			}
			else
			{
				printf("%lld %lld/%lld",a.son/a.mother,a.son%a.mother,a.mother);
			}
		}
	}
	return 0;
}
int main()
{
	Faction a;
	Faction b;
	Faction c;
	scanf("%lld/%lld%lld/%lld",&a.son,&a.mother,&b.son,&b.mother);
	PrintfFaction(a);
	printf(" + ");
	PrintfFaction(b);
	printf(" = ");
	c.son=a.son*b.mother+b.son*a.mother;	
	c.mother=a.mother*b.mother;
	PrintfFaction(c);
	printf("\n");
	
	PrintfFaction(a);
	printf(" - ");
	PrintfFaction(b);
	printf(" = ");
	c.son=a.son*b.mother-b.son*a.mother;	
	c.mother=a.mother*b.mother;
	PrintfFaction(c);
	printf("\n");
	
	PrintfFaction(a);
	printf(" * ");
	PrintfFaction(b);
	printf(" = ");
	c.son=a.son*b.son;
	c.mother=a.mother*b.mother;
	PrintfFaction(c);
	printf("\n");
	
	PrintfFaction(a);
	printf(" / ");
	PrintfFaction(b);
	printf(" = ");
	c.son=a.son*b.mother;
	c.mother=a.mother*b.son;
	PrintfFaction(c);
	printf("\n");
}