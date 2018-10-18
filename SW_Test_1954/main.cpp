#include <iostream>
#include <string.h>
using namespace std;

int main() {

	int Test_Case;
	cin >> Test_Case;

	for (int t = 0; t < Test_Case; t++) {
		int N;
		cin >> N;

		int** arr = new int*[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new int[N];
			memset(arr[i], 0, sizeof(int) * N);
		}
		int sw = 1;
		int k = N;
		int n = 0;
		int row = 0, col = -1;
		
		for (int i = 0; i < (2 * N - 1); i++) {
			for (int j = 0; j < k; j++) {
				n++;
				col += sw;
				arr[row][col] = n;
			}
			k--;
			for (int j = 0; j < k; j++) {
				n++;
				row += sw;
				arr[row][col] = n;
			}
			sw *= -1;
		}
		cout << "#" << t + 1 << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < N; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	return 0;
}