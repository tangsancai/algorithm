#include <iostream>

int Count(int n)
{
	int ans = 0;
	int base = 1;
	//count "1" in every digit, then sum
	while (n/base != 0)
	{
		int right = n%base;//low digit
		int left = n/(base*10);//high digit
		int now = (n/base)%10;//current digit
		if (now == 0)//current digit 0, then only determined by high digit
			ans += left*base;
		else if(now == 1)//current digit 1, then determined by both high and low digit
			ans += left*base+right+1;
		else//current digit > 1 
			ans += (left+1)*base;
		base *= 10;
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans = Count(n);
		printf("%d\n", ans);
	}
	return 0;
}