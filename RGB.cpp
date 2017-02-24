#include <iostream>
#include <cstdio>
using namespace std;

void RGBCase(int **RGB, int i, int j, int N, int& sum, int& small) {
	sum += RGB[i][j];

	if(i == N - 1) {
		if (small == 0) {
			small = sum;
			sum -= RGB[i][j];
		}
		else {
			if (small > sum)
				small = sum;
			sum -= RGB[i][j];
		}
		return;
	}


	if(j == 0) {
		RGBCase(RGB, i + 1, 1, N, sum, small);
		RGBCase(RGB, i + 1, 2, N, sum, small);
	}
	else if(j == 1) {
		RGBCase(RGB, i + 1, 0, N, sum, small);
		RGBCase(RGB, i + 1, 2, N, sum, small);
	}
	else {
		RGBCase(RGB, i + 1, 0, N, sum, small);
		RGBCase(RGB, i + 1, 1, N, sum, small);
	}

	sum -= RGB[i][j];
}
int main(void) {
	int N;
	int **RGB;
	int sum, small, smallest;
	cin >> N;
	cin.clear();



	RGB = new int * [N];
	for(int i = 0; i < N; i++) {
		RGB[i] = new int [3];
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}

	smallest = 0;
	sum = 0;
	small = 0;
	for(int j = 0; j < 3; j++) {
		RGBCase(RGB, 0, j, N, sum, small);

		if(smallest == 0)
			smallest = small;
		else {
			if(smallest > small) {
				smallest = small;
			}	
		}
	}   

	cout << smallest << endl;
/*
	for(int i = 0; i < N; i++) {
		delete[] RGB[i]
	}
	delete[] RGB;
	*/
	return 0;
}
