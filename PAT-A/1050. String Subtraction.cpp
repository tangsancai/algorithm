#include<stdio.h>
#include<string.h>
char str1[10005];
char str2[10005];
int ascll[10005]={0};
int main()
{
	gets(str1);
	gets(str2);
	int str1num=0;
	int str2num=0;
/*	for(int i=0;i<strlen(str2);i++)//把strlen拿出来就不超时了 
	{
			ascll[str2[i]]=1;
	}

	for(int i=0;i<strlen(str1);i++)
	{
		if(ascll[str1[i]]==0)
		{
			printf("%c",str1[i]);
		}
	}
*/
	while(str1[str1num]!='\0'&&str2[str2num]!='\0')
	{
		ascll[str2[str2num]]=1;
		if(ascll[str1[str1num]]==1)
		{
			str1num++;
		}
		else
		{
			str2num++;
		}
	}
	while(str1[str1num]!='\0')
	{
		if(ascll[str1[str1num]]==0)
		{
			printf("%c",str1[str1num]);
		}
		str1num++;
	}
}