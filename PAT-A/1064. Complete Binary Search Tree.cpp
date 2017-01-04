#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int num[1005];
int cbt[1005];
int index=0;
void inorder(int root)
{
	if(root>N)
	{
		return;
	}
	inorder(2*root);
	cbt[root]=num[index++];
	inorder(2*root+1);
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+N);
	inorder(1);
	for(int i=1;i<N;i++)
	{
		printf("%d ",cbt[i]);
	}
	printf("%d",cbt[N]);
}