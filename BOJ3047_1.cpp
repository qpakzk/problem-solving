//https://www.acmicpc.net/problem/3047
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
	int n[3];
	char c[3];

	for(int i = 0; i < 3; i++) {
		cin >> n[i];
	}	
	cin.clear();

	for(int i = 0; i < 3; i++) {
		cin >> c[i];
	}
	
	sort(n, n + 3);

	for(int i = 0; i < 3; i++) {
		switch(c[i]) {
			case 'A':
				cout << n[0] << " ";
				break;
			case 'B':
				cout << n[1] << " ";
				break;
			case 'C':
				cout << n[2] << " ";
				break;
		}
	}

	cout << endl;
	return 0;
}
