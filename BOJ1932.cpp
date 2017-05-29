//https://www.acmicpc.net/problem/1932
#include <iostream>
using namespace std;

int compare(int n1, int n2) {
	if(n1 > n2)
		return n1;
	else
		return n2;
}
void MaxSum(int **triangle, int n) {
	int bigger;

	for(int i = 0; i < n - 1; i++) {
		bigger = compare(triangle[n - 1][i], triangle[n - 1][i + 1]);	
		triangle[n - 2][i] += bigger;	
	}

	if(n == 0)
		return;

	MaxSum(triangle, n - 1);
}

int main(void) {
	int n, num, *arr, **triangle;
	int max;
	cin >> n;
			
	num = 0;
	for(int i = 1; i <= n; i++)
		num += i;
	arr = new int [num];
	for(int i = 0; i < num; i++) {
		cin >> arr[i];
	}	
	
	triangle = new int * [n];
	
	for(int i = 0; i < n; i++) {
		triangle[i] = new int [i + 1];
	}
	
	int k = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i + 1; j++) {
			triangle[i][j] = arr[k];
			k++;
		}	
	}

	MaxSum(triangle, n);

	cout << triangle[0][0] << endl;

	delete[] arr;
	for(int i = 0; i < n; i++) {
		delete[] triangle[i];
	}
	delete[] triangle;

	return 0;
}
