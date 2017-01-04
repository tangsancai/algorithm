#include<stdio.h>
#include<string.h>
int data[75]={0};
char chuan1[100005];
char chuan2[100005];
int main()
{
	int i=0;
	int temp=-1;
	int flag=0;
	memset(chuan1,'\0',sizeof(chuan1));
	memset(chuan2,'\0',sizeof(chuan2));
	gets(chuan1);
	gets(chuan2);
	while(chuan1[i]!='\0')
	{
		if(chuan1[i]>='0'&&chuan1[i]<='9')
		{
			data[chuan1[i]-'0']=1;
		}
		else if(chuan1[i]>='A'&&chuan1[i]<='Z')
		{
			data[(chuan1[i]-'A')+10]=1;
			data[(chuan1[i]-'A')+10+26]=1;
		}
		else
		{
			switch(chuan1[i])
			{
				case '_':
					data[62]=1;
					break;
				case ',':
					data[63]=1;
					break;
				case '-':
					data[64]=1;
					break;
				case '.':
					data[65]=1;
					break;
				case '+':
					for(int j=10+26;j<36+26;j++)
					{
						data[j]=1;
					}
					break;
			}
		}
		i++;
	}	
	i=0;
	while(chuan2[i]!='\0')
	{
		if(chuan2[i]>='0'&&chuan2[i]<='9')
		{
			temp=chuan2[i]-'0';
		}
		else if(chuan2[i]>='a'&&chuan2[i]<='z')
		{
			temp=(chuan2[i]-'a')+10;
		}
		else if(chuan2[i]>='A'&&chuan2[i]<='Z')
		{
			temp=(chuan2[i]-'A')+10+26;
		}
		else
		{
			switch(chuan2[i])
			{
				case '_':
					temp=62;
					break;
				case ',':
					temp=63;
					break;
				case '-':
					temp=64;
					break;
				case '.':
					temp=65;
					break;
			}
		}
		if(data[temp]==1)
		{
			i++;
		}
		else
		{
			printf("%c",chuan2[i]);
			flag=1;
			i++;
		}
	}
	if(flag==0)
	{
		printf("\n");
	}
}