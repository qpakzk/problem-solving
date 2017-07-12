#include <cstdio>
#include <cmath>

typedef struct _team {
	int scored;
	int allowed;
} Team;
int main(void) {
	int T, n, m;
	Team team[1001] = {0};

	int a, b, p, q;

	scanf("%d", &T);
	for(int loop = 0; loop < T; loop++) {
		scanf("%d %d", &n, &m);

		for(int i = 1; i <= n; i++) {
			if(team[i].scored != 0)
				team[i].scored = 0;
			if(team[i].allowed != 0)
				team[i].allowed = 0;
		}

		for(int game = 0; game < m; game++) {
			scanf("%d %d %d %d", &a, &b, &p, &q);
			team[a].scored += p;
			team[a].allowed += q;
			team[b].scored += q;
			team[b].allowed += p;
		}

		int W_1000,pow_S, pow_A, bigW = -1, smallW = -1;
		for(int i = 1; i <= n; i++) {

			if(team[i].scored == 0 && team[i].allowed == 0) 
				W_1000 = 0;	
			else {
				pow_S = pow(team[i].scored, 2);
				pow_A = pow(team[i].allowed, 2);
				W_1000 = (pow_S * 1000) / (pow_S + pow_A);
			}	

			if(bigW == -1 || bigW < W_1000) {
				bigW = W_1000;
			}

			if(smallW == -1 || smallW > W_1000) {
				smallW = W_1000;
			}

		}
		printf("%d\n%d\n", bigW, smallW);
	}	
	return 0;
}
