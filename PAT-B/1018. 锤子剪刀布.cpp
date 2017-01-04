#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct Node
{
	char typeCJB;
	int num;
};
int CJB(char a,char b)
{
	switch(a)
	{
		case 'C':
			switch(b)
			{
				case 'C':
					return 0;
					break;
				case 'J':
					return 1;
					break;
				case 'B':
					return -1;
					break;
			}
			break;
		case 'J':
			switch(b)
			{
				case 'C':
					return -1;
					break;
				case 'J':
					return 0;
					break;
				case 'B':
					return 1;
					break;
			}
			break;
		case 'B':
			switch(b)
			{
				case 'C':
					return 1;
					break;
				case 'J':
					return -1;
					break;
				case 'B':
					return 0;
					break;
			}
			break;
	}
}
bool cmp(Node a,Node b)
{
	if(a.num!=b.num)
	{
		return a.num>b.num>0;
	}
	else
	{
		return a.typeCJB<b.typeCJB>0;
	}
}
int main()
{
	Node num[3];
	int CWin1=0;
	int BWin1=0;
	int JWin1=0;
	int CWin2=0;
	int BWin2=0;
	int JWin2=0;
	int Ping=0;
	int N;
	char a;
	char b;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		getchar();
		scanf("%c %c",&a,&b);
		switch(CJB(a,b))
		{
			case 0:
				Ping++;
				break;
			case -1:
				switch(a)
				{
					case 'C':
						BWin2++;
						break;
					case 'J':
						CWin2++;
						break;
					case 'B':
						JWin2++;
						break;
				}
				break;
			case 1:
				switch(a)
				{
					case 'C':
						CWin1++;
						break;
					case 'J':
						JWin1++;
						break;
					case 'B':
						BWin1++;
						break;
				}
				break;
		}
	}
	printf("%d %d %d\n",CWin1+JWin1+BWin1,Ping,N-(CWin1+JWin1+BWin1)-Ping);
	printf("%d %d %d\n",N-(CWin1+JWin1+BWin1)-Ping,Ping,CWin1+JWin1+BWin1);
	num[0].typeCJB='B';
	num[0].num=BWin1;
	num[1].typeCJB='C';
	num[1].num=CWin1;
	num[2].typeCJB='J';
	num[2].num=JWin1;
	sort(num,num+3,cmp);
	printf("%c ",num[0].typeCJB);
	num[0].typeCJB='B';
	num[0].num=BWin2;
	num[1].typeCJB='C';
	num[1].num=CWin2;
	num[2].typeCJB='J';
	num[2].num=JWin2;
	sort(num,num+3,cmp);
	printf("%c",num[0].typeCJB);
}