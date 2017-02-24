#include <cstdio>

int main(void) {
	int T, P, M, F, C;
	int pay, sum, temp, coupon, res, remain;
	scanf("%d", &T);
		
	for(int i = 0; i < T; i++) {
		scanf("%d%d%d%d", &P, &M, &F, &C);
			
		sum = 0;
		pay = M / P;
		coupon = pay * C;
		coupon = (coupon / F) * C + (coupon % F);	
		while(1) {
			res = coupon / F;
			if(res == 0)
				break;
			sum += res;
			remain = coupon % F; 
			coupon = res * C + remain;
		}

		printf("%d\n", sum);
	}	

	return 0;
}
