//http://codeforces.com/problemset/problem/118/A

#include <stdio.h>

int main(void) {
	char string[100];
	int i;
	scanf("%s", string);
	i = 0;
	while(string[i] != '\0') {
		if(string[i] == 'a' || string[i] == 'A'
		|| string[i] == 'e' || string[i] == 'E' 	
		|| string[i] == 'i' || string[i] == 'I' 
		|| string[i] == 'o' || string[i] == 'O' 
		|| string[i] == 'u'	|| string[i] == 'U' 
		|| string[i] == 'y' || string[i] == 'Y') {
			i++;
			continue;	
		}
		else {	
			printf(".%c", string[i] < 97 ? string[i] + 32 : string[i]);
			i++;
		}
	}
	printf("\n");
	return 0;
}

