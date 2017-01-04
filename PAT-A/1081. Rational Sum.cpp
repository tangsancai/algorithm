#include <cstdio>
long long gcd(long long x, long long y){
	if (y == 0) return x;
	else return gcd(y, x%y);
}
long long lcm(long long x, long long y){
	return x / gcd(x, y) *y;
}
long long a[100], b[100];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld/%lld", &a[i], &b[i]);
	}
	long long deno = 1, nume = 0;
	for (int i = 0; i < n; i++)
		deno = lcm(deno, b[i]);
	for (int i = 0; i < n; i++)
		nume += deno / b[i] * a[i];
	long long pre = nume / deno;
	nume = nume - pre*deno;
	long long t = gcd(nume, deno);
	nume = nume / t;
	deno = deno / t;
	if (pre == 0 && nume == 0)
		printf("0\n");
	else if (pre != 0 && nume == 0)
		printf("%lld\n", pre);
	else if (pre == 0 && nume != 0)
		printf("%lld/%lld\n", nume, deno);
	else 
		printf("%lld %lld/%lld\n", pre, nume, deno);
	return 0;
}