//http://codeforces.com/problemset/problem/4/A

#include <stdio.h>
#include <stdlib.h>

int main() {
	int w;
	scanf("%d", &w);
	if(w == 2 || w % 2 == 1) 
		printf("NO");
	else 
		printf("YES");
	return 0;
}
