#include <iostream>
#include <string>
#include <set>

using namespace std;

int answer;
char arr[4][4];
set<string> ss;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void sol(int i, int j, int len, string s) {
	s += arr[i][j];
	if (len == 7) {
		ss.insert(s);
		return;
	}
	for (int q = 0; q < 4; q++) {
		int nx = i + dx[q];
		int ny = j + dy[q];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		sol(nx, ny, len + 1, s);
	}
}

int main() {

	int Test_Case;
	cin >> Test_Case;

	for (int t = 0; t < Test_Case; t++) {
		ss.clear();
		answer = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string s = "";
				sol(i, j, 1, s);
			}
		}
		answer = ss.size();
		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}