#include <cstdio>
#include <cmath>

int number[20];
int notation(int num, int system) {
	int n, q, r;	
	int idx;

	idx = 0;
	n = num;
	while(1) {
		q = n / system;
		r = n % system;
		number[idx] = r;
		if(q == 0)
		   break;	
		idx++;
		n = q;
	}	
	return idx;
}

bool isPalindromicNumber(int idx) {
	for(int i = 0; i <= idx / 2; i++) {
		if(number[i] != number[idx - i]) 
			return false;
	}	
	return true;
}

int main(void) {
	int T, n;
	int start_idx;
	bool isPalindrome;
	scanf("%d", &T);
	for(int loop = 0; loop < T; loop++) {
		scanf("%d", &n);
		for(int i = 2; i <= 64; i++) {
			start_idx = notation(n, i);
			isPalindrome = isPalindromicNumber(start_idx);
			if(isPalindrome == true)
				break;
		}
		if(isPalindrome == true)	
			printf("%d\n", 1);	
		else
			printf("%d\n", 0);
	}
	
	return 0;
}
