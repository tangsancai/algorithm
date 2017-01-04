#include<stdio.h>
#include<string.h>
#include<algorithm>
int data[100005];
int main()
{
	memset(data,0,sizeof(data));
	int n;
	scanf("%d",&n);
	int num;
	int score;
	int maxnum=-1;
	int maxscore=-1;
	while(n--)
	{
		scanf("%d%d",&num,&score);
		data[num]=data[num]+score;
		if(maxscore<data[num])
		{
			maxscore=data[num];
			maxnum=num;
		}
	}
	printf("%d %d",maxnum,maxscore);	
} 