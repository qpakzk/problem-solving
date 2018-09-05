//https://www.acmicpc.net/problem/1978
#include <iostream>
using namespace std;

bool IsPrimeNumber(int n) {
	bool isPrime = true;
	
	if(n == 1)
		return false;

	for(int i = 2; i < n; i++) {
		if(n % i == 0)
			isPrime = false;	
	}

	if(isPrime == true)
		return true;
	else
		return false;
	

}
int main(void) {
	int N;
	int *num;
	bool isPrime;
	int count;
	cin >> N;
	cin.clear();	
	num = new int[N];
	for(int i = 0; i < N; i++) {
		cin >> num[i]; 
	}	
		
	count = 0;
	for(int i = 0; i < N; i++) {
		isPrime = IsPrimeNumber(num[i]);	
		if(isPrime == true)
			count++;	
	}	

	cout << count << endl;
	return 0;
}
