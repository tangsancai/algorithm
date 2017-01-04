#include<stdio.h>
#include<string.h>
int main() 
{
	char str[105]; 
	int n;
	int len;
	int number1;
	int number2;
	int number3;
	int numberp;
	int numbert;
	int con1;
	int flag;
	scanf("%d",&n);
	while(n--)
	{
		con1=0;
		number1=0;
		number2=0;
		number3=0;
		numberp=0;
		numbert=0;
		flag=0;
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;i<len;i++)
		{
			if(str[i]!='P'&&str[i]!='A'&&str[i]!='T')
			{
				break;
				con1=1;
			}
			if(str[i]=='A'&&flag==0)
			{
				number1++;
			}
			else if(str[i]=='P')
			{
				if(flag==0)
				{
					flag=1;
				}	
				numberp++;
			}
			else if(str[i]=='A'&&flag==1)
			{
				number2++;
			}
			else if(str[i]=='T')
			{
				if(flag==1)
				{
					flag=2;
				}
				numbert++;
			}
			else if(str[i]=='A'&&flag==2)
			{
				number3++;
			}
		}
		if(!con1&&numberp==1&&numbert==1)
		{
			if(number2>0&&number3==number2*number1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}