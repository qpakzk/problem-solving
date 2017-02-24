#include <stdio.h>
long long F[90];

long long Fibo(int n) {
	F[0] = 0;	
	F[1] = 1;

	for(int i = 2; i <= n; i++)
		F[i] = F[i - 1] + F[i - 2];

	return F[n];
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%lld\n", Fibo(n));
	
	return 0;
}
