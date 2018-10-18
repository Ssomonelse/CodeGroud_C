#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int Test_Case = 10;

	for (int t = 0; t < Test_Case; t++) {
		int arr[100][100];
		int answer = 0;
		int tt;
		cin >> tt;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}
		int sum1, sum2, sum3, sum4;

		sum1 = sum2 = sum3 = sum4 = 0;

		for (int i = 0; i < 100; i++) {
			sum1 = sum2 = 0;
			for (int j = 0; j < 100; j++) {
				sum1 += arr[i][j];
				sum2 += arr[j][i];
				if (i == j) sum3 += arr[i][j];
				if (i + j == 99) sum4 += arr[i][j];
			}
			answer = max(answer, sum1);
			answer = max(answer, sum2);
		}
		answer = max(answer, sum3);
		answer = max(answer, sum4);

		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}