#include <iostream>

using namespace std;

int main() {

	int Test_Case;
	cin >> Test_Case;
	int answer;

	for (int t = 0; t < Test_Case; t++) {
		answer = 0;

		int arr[9][9];

		for (int i = 0; i < 9; i++) {
			int check[10] = { 0, };
			int cnt = 0;
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
				check[arr[i][j]]++;
			}
			for (int j = 1; j < 10; j++) {
				if (check[j] == 1) {
					cnt++;
				}
			}
			if (cnt == 9) answer += 1;
		}
		for (int j = 0; j < 9; j++) {
			int check[10] = { 0, };
			int cnt = 0;
			for (int i = 0; i < 9; i++) {
				check[arr[i][j]]++;
			}
			for (int i = 1; i < 10; i++) {
				if (check[i] == 1) {
					cnt++;
				}
			}
			if (cnt == 9) answer += 1;
		}
		for (int q = 0; q < 7; q+=3) {
			for (int w = 0; w < 7; w+=3) {
				int check[10] = { 0, };
				int cnt = 0;
				for (int i = q; i < q + 3; i++) {
					for (int j = w; j < w + 3; j++) {
						check[arr[i][j]]++;
					}
				}
				for (int j = 1; j < 10; j++) {
					if (check[j] == 1) {
						cnt++;
					}
				}
				if (cnt == 9) answer += 1;
			}
		}
		if (answer == 27) answer = 1;
		else answer = 0;

		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}