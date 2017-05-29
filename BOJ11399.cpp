//https://www.acmicpc.net/problem/11399
#include <iostream>
using namespace std;

int Compare(const void *a, const void *b) {
	if ( *(int *)a <  *(int *)b ) 
		return -1;
	else if ( *(int *)a == *(int *)b ) 
		return 0;
	else 
		return 1;
}

int main(void) {
	int N;
	int *P, *delay;
	int sum;
	cin >> N;
	cin.clear();

	P = new int[N];

	for(int i = 0; i < N; i++) {
		cin >> P[i];
	}	
	
	qsort(P, N, sizeof(int), Compare);
	
	delay = new int [N];
		
	for(int i = 0; i < N; i++) {
		delay[i] = 0;
		
		delay[i] = P[i];
		if(i > 0) { 
			for(int j = 0; j < i; j++) 
				delay[i] += P[j];
		}
	}	

	sum = 0;
	for(int i = 0; i < N; i++) {
		sum += delay[i];
	}
	
	cout << sum << endl;

	delete[] P;
	delete[] delay;	
	return 0;

}
