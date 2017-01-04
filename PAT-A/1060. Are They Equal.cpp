#include <stdio.h>
#include <string.h>
#define MAX 110
struct result{
	char d[MAX];
	int k;
};

result getResult(char *a, int n){
	result r;
	int firstPos = -1;
	int pointPos = -1;
	int index = 0;
	int i;
	for (i = 0; a[i]; i++){
		if (a[i] == '.'){
			pointPos = i;
			continue;
		}
		else if (a[i] == '0' && firstPos == -1)
			continue;
		else{
			if (firstPos == -1)
				firstPos = i;
			if (index < n)
			{
				if (index < strlen(a))
					r.d[index++] = a[i];
				else
					r.d[index++] = '0';
			}
		}
	}
	r.d[index] = 0;
	if (pointPos == -1)
		pointPos = i;
	if (pointPos - firstPos < 0)
		r.k = pointPos - firstPos + 1;
	else
		r.k = pointPos - firstPos;
	if (index == 0){
		int i;
		for (i = 0; i != n; i++)
			r.d[i] = '0';
		r.d[i] = 0;
		r.k = 0;
	}
	return r;
}

int main(){
	int n;
	char a[MAX], b[MAX];
	scanf("%d%s%s", &n, a, b);
	result r1 = getResult(a, n);
	result r2 = getResult(b, n);
	if (strcmp(r1.d, r2.d) == 0 && r1.k == r2.k)
		printf("YES 0.%s*10^%d\n", r1.d, r1.k);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1.d, r1.k, r2.d, r2.k);
	return 0;
}