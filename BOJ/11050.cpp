//https://www.acmicpc.net/problem/11050
#include <iostream>
using namespace std;

int Factorial(int n) {
	if(n == 0)
		return 1;
	else if(n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main(void) {
	int N, K;
	int result;
	cin >> N >> K;
	
	result = Factorial(N) / (Factorial(K) * Factorial(N - K));	

	cout << result << endl;
	return 0;
}
	

