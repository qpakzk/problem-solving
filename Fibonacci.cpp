#include <iostream>
using namespace std;

int Fibo(int n, int& count0, int& count1) {
	if(n == 0) {
		count0++;
		return 0;		
	}
	else if(n == 1) {
		count1++;
		return 1;
	}
	else 
		return Fibo(n - 1, count0, count1) + Fibo(n - 2, count0, count1);
}

int main(void) {
	int T, N;
	int count0, count1;
	cin >> T;
	for(int i = 0; i < T; i++) {
		count0 = 0;
		count1 = 0;

		cin >> N;		
		Fibo(N, count0, count1);
		cout << count0 << " " << count1 << endl;
	}

	return 0;
}
