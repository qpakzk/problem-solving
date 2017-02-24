#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void *a, const void *b) {
	if(*(int *)a < *(int *)b)
		return -1;
	else if(*(int *)a == *(int *)b)
		return 0;
	else
		return 1;
}
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
	
	qsort(n, 3, sizeof(int), compare);

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
