//http://codeforces.com/problemset/problem/71/A

#include <stdio.h>
#include <string.h>

int main(void) {
	char word[100];
	int n, i, len;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", word);
		len = strlen(word);
		if(len <= 10)
			printf("%s\n", word);	
		else
			printf("%c%d%c\n", word[0], len - 2, word[len - 1]);
	}
	return 0;
}	
