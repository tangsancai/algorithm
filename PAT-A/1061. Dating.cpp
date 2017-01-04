#include<stdio.h>
#include<string.h>
char Day[10];
char Hour[10];
void getDay(char a)
{
	memset(Day,'\0',sizeof(Day));
	switch(a)
	{
		case 'A':
			strcpy(Day,"MON ");
			break;
		case 'B':
			strcpy(Day,"TUE ");
			break;
		case 'C':
			strcpy(Day,"WED ");
			break;
		case 'D':
			strcpy(Day,"THU ");
			break;
		case 'E':
			strcpy(Day,"FRI ");
			break;
		case 'F':
			strcpy(Day,"SAT ");
			break;
		case 'G':
			strcpy(Day,"SUN ");
			break;
	}	
}
void getHour(char a)
{
	memset(Hour,'\0',sizeof(Hour));
	switch(a)
	{
		case '0':
			strcpy(Hour,"00:");
			break;
		case '1':
			strcpy(Hour,"01:");
			break;
		case '2':
			strcpy(Hour,"02:");
			break;
		case '3':
			strcpy(Hour,"03:");
			break;
		case '4':
			strcpy(Hour,"04:");
			break;
		case '5':
			strcpy(Hour,"05:");
			break;
		case '6':
			strcpy(Hour,"06:");
			break;
		case '7':
			strcpy(Hour,"07:");
			break;
		case '8':
			strcpy(Hour,"08:");
			break;
		case '9':
			strcpy(Hour,"09:");
			break;
		case 'A':
			strcpy(Hour,"10:");
			break;
		case 'B':
			strcpy(Hour,"11:");
			break;
		case 'C':
			strcpy(Hour,"12:");
			break;
		case 'D':
			strcpy(Hour,"13:");
			break;
		case 'E':
			strcpy(Hour,"14:");
			break;
		case 'F':
			strcpy(Hour,"15:");
			break;
		case 'G':
			strcpy(Hour,"16:");
			break;
		case 'H':
			strcpy(Hour,"17:");
			break;
		case 'I':
			strcpy(Hour,"18:");
			break;
		case 'J':
			strcpy(Hour,"19:");
			break;
		case 'K':
			strcpy(Hour,"20:");
			break;
		case 'L':
			strcpy(Hour,"21:");
			break;
		case 'M':
			strcpy(Hour,"22:");
			break;
		case 'N':
			strcpy(Hour,"23:");
			break;
	}
}
int main()
{
	int i=0;
	int flag=0;
	char str1[65];
	char str2[65];
	scanf("%s%s",str1,str2);
	while(str1[i]!='\0'&&str2[i]!='\0')
	{
		if(str1[i]==str2[i]&&flag==0&&str1[i]>='A'&&str1[i]<='G')
		{
			getDay(str1[i]);
			flag=1;
		}
		else if(str1[i]==str2[i]&&flag==1&&((str1[i]>='A'&&str1[i]<='N')||(str1[i]>='0'&&str1[i]<='9')))
		{
			getHour(str1[i]);
			break;
		}
		i++;
	}
	i=0;
	scanf("%s%s",str1,str2);
	while(str1[i]!='\0'&&str2[i]!='\0')
	{
		if(str1[i]==str2[i])
		{
			if((str1[i]>='A'&&str1[i]<='Z')||(str1[i]>='a'&&str1[i]<='z'))
			{
				if(i<9)
				{
					printf("%s%s0%d",Day,Hour,i);
				}
				else
				{
					printf("%s%s%d",Day,Hour,i);
				}
				break;	
			}	
		}
		i++;
	}
}