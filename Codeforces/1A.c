//http://codeforces.com/problemset/problem/1/A

#include <stdio.h>

int main(void) {
	long long n, m, a;
	long long big, small;
	long long num, num1, num2;
	scanf("%lld%lld%lld", &n, &m, &a);

	if(n > m) {
		big = n;
		small = m;
	}
	else {
		big = m;
		small = n;
	}

	if(a >= big)
		num = 1;
	else if(a >= small) {
		if(big % a == 0)
			num = big / a;
		else
			num = big / a + 1;
	}
	else {
		if(big % a == 0)
			num1 = big / a;
		else
			num1 = big / a + 1;

		if(small % a == 0)
			num2 = small / a;
		else
			num2 = small / a + 1;

		num = num1 * num2;
	}
	printf("%lld\n", num);
	return 0;
}
