//https://www.acmicpc.net/problem/11070

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define MAX_TEAM 1001
using namespace std;

struct Team {
	int scored;
	int allowed;
} team[MAX_TEAM];

int main(void) {
	ios::sync_with_stdio(false);
	int T, n, m;
	int a, b, p, q;

	cin >> T;
	while(T--) {
		memset(team, 0x00, sizeof(team));
		cin >> n >> m;

		for(int i = 0; i < m; i++) {
			cin >> a >> b >> p >> q;
			team[a].scored += p;
			team[a].allowed += q;
			team[b].scored += q;
			team[b].allowed += p;
		}

		long long W, S, A, max_W = LLONG_MIN, min_W = LLONG_MAX;
		for(int i = 1; i <= n; i++) {
			if(!team[i].scored && !team[i].allowed) 
				W = 0;
			else {
				S = team[i].scored * team[i].scored;
				A = team[i].allowed * team[i].allowed; 
				W = S * 1000 / (S + A);
			}	

			max_W = max(max_W, W);
			min_W = min(min_W, W);

		}
		cout << max_W << endl;
		cout << min_W << endl;
	}
	return 0;
}