//http://codeforces.com/problemset/problem/158/A

#include <stdio.h>

int main(void) {
	int n, k, score[101];
	int i, cut, pass;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; i++)
		scanf("%d", &score[i]);
	cut = score[k];	
	
	if(cut <= 0) {
		pass = 0;
		for(i = 1; i <=n; i++) {
			if(score[i] <= 0)
				break;
			pass++;
		}
	}	
	else {
		pass = k;
		for(i = k + 1; i <= n; i++) {
			if(score[i] != cut)
				break;
			pass++;
		}	
	}	

	printf("%d\n", pass);
	return 0;
}
