#include<stdio.h>
#include<string.h>

 int main()
 {
 	int i;
 	int j=0;
 	char sen[85];
 	char temp[85];
 	memset(temp,'\0',sizeof(temp));
 	gets(sen);
 	for(int i=strlen(sen)-1;i>=0;i--)
 	{
		if(sen[i]==' ')
		{
			for(int k=j-1;k>=0;k--)
			{
				printf("%c",temp[k]);
			}
			printf(" ");
			j=0;
			memset(temp,'\0',sizeof(temp));
		} 
		else
		{
			temp[j++]=sen[i];
		}	
 	}
 	for(int k=j-1;k>=0;k--)
	{
		printf("%c",temp[k]);
	}
 }