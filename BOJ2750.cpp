//https://www.acmicpc.net/problem/2750
#include <iostream>
using namespace std;

int Compare(const void *a, const void *b) {
	if(*(int *)a < *(int *)b)
		return -1;
	else if(*(int *)a == *(int *)b)
		return 0;
	else
		return 1;
}

int main(void) {
	int N;
	int *num;
	cin >> N;
	num = new int [N];

	for(int i = 0; i < N; i++) {
		cin >> num[i];
	}	
	
	qsort(num, N, sizeof(int), Compare);
	
	for(int i = 0; i < N; i++) {
		cout << num[i] << endl;
	}
	return 0;
}
