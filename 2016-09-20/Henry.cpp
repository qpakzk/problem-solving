#include <cstdio>

void GCD(int n1, int n2, int& gcd) {
	int big, small;

	if(n1 > n2) {
		big = n1;
		small = n2;
	}
	else {
		big = n2;
		small = n1;
	}	
	
	int remain = big % small;
	
	if(remain == 0) {
		gcd =  small;
		return;
	}
	GCD(small, remain, gcd);
}

int main(void) {
	int T, a, b, c, gcd;
	int up, down, temp;	
	int res;
	scanf("%d", &T);
	for(int loop = 0; loop < T; loop++) {
		scanf("%d%d", &a, &b);
		up = a;
		down = b;
		c = 2;
		while(1) {	
			GCD(up, down, gcd);	

			if(gcd != 1) {
				up = up / gcd;
				down = down / gcd;
			}

			if(up == 1) {
				res = down;
				break;
			}
			while(1) {
				temp = c * up;
				if(temp > down) {
					up = temp - down;
					down = down * c;
					break;
				}	
				else
					c++;
			}
		}
		printf("%d\n", res);
	}	
	return 0;
}
