#include <iostream>
#include <vector>
using namespace std;

int answer;
int film[13][20];
int temp[13][20];
int A, B;

vector<int[]> changeTemp(int idx) {
	vector<int []> v;



	return;
}

int main() {

	int Test_Case;
	cin >> Test_Case;
	int D, W, K;

	for (int t = 0; t < Test_Case; t++) {
		int goOut = 0;
		answer = 0;
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}
		int* water = new int[D];
		for (int i = 0; i < D; i++) {
			water[i] = -1;
		}
		int cnt = 0; // 0, 1
		int flag = 1;
		int wA, wB = 0;
		while (goOut != W) {
			for (int i = 0; i < D; i++) {
				for (int j = 0; j < W; j++) {
					temp[i][j] = film[i][j];
				}
			}
			if (cnt != 0)
				flag = 0;
			if (cnt != 0 && flag == 0) {
				
				if (!temp[0][0])
					A = temp[0][0];
				else
					B = temp[0][0];
				for (int i = 0; i < W; i++) {
					cnt = 0;
					for (int j = 0; j < D; j++) {
						if (temp[j][i] == A && j == 0) {
							cnt++;
						}
						else if (temp[j][i] == B && j == 0) {
							cnt++;
						}
						else if (temp[j][i] != temp[j - 1][i]) {
							cnt = 1;
						}
						else {
							cnt++;
						}
						if (cnt >= K) {
							goOut++;
							break;
						}
					}
				}
			}
			if (!temp[0][0])
				A = temp[0][0];
			else
				B = temp[0][0];
			for (int i = 0; i < W; i++) {
				cnt = 0;
				for (int j = 0; j < D; j++) {
					if (temp[j][i] == A && j == 0) {
						cnt++;
					}
					else if (temp[j][i] == B && j == 0) {
						cnt++;
					}
					else if (temp[j][i] != temp[j-1][i]) {
						cnt = 1;
					}
					else{
						cnt++;
					}
					if (cnt >= K) {
						goOut++;
						break;
					}
				}
			}
		}
		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}