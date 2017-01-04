#include<stdio.h>
#include<string.h>

int main()
{
	char A[85];
	char B[85];
	int data[40];
	scanf("%s%s",A,B);
	int i;
	int j=0;
	memset(data,0,sizeof(data));
	for(i=0;i<strlen(A);i++)
	{
		if(A[i]==B[j])
		{
			j++;
		}
		else
		{
			if(A[i]>='0'&&A[i]<='9')
			{
				data[A[i]-'0']++;
				if(data[A[i]-'0']==1)
				{
					printf("%d",A[i]-'0');
				}
			}
			else if(A[i]=='_')
			{
				data[39]++;
				if(data[39]==1)
				{
					printf("_");
				}
			}
			else if(A[i]>='A'&&A[i]<='Z')
			{
				data[A[i]-'A'+10]++;
				if(data[A[i]-'A'+10]==1)
				{
					printf("%c",A[i]);
				}
			}
			else if(A[i]>='a'&&A[i]<='z')
			{
				data[A[i]-'a'+10]++;
				if(data[A[i]-'a'+10]==1)
				{
					printf("%c",A[i]-'a'+'A');
				}
			}
		}
	}
	
} 