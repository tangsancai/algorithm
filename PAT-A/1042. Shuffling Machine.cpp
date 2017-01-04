#include<stdio.h>
#include<string.h>
int main()
{
	char card[60][5]={"",
					"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
					"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
					"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
					"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
					"J1","J2"};
	int K;
	int pos[55];
	char mid[60][5];
	scanf("%d",&K);
	for(int i=1;i<=54;i++)
	{
		scanf("%d",&pos[i]);
	}
	while(K--)
	{
		for(int i=1;i<=54;i++)
		{
			strcpy(mid[pos[i]],card[i]);
		}
		for(int i=1;i<=54;i++)
		{
			strcpy(card[i],mid[i]);
		}
	}
	for(int i=1;i<54;i++)
	{
		printf("%s ",card[i]);
	}
	printf("%s",card[54]);
}