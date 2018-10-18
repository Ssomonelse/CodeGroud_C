#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int answer;

	for (int t = 0; t < 10; t++) {
		answer = 0;
		int N;
		cin >> N;
		int* building = new int[N];

		for (int i = 0; i < N; i++) {
			cin >> building[i];
		}

		for (int i = 2; i < N - 2; i++) {
			int L1 = building[i] - building[i - 1];
			int L2 = building[i] - building[i - 2];
			int R1 = building[i] - building[i + 1];
			int R2 = building[i] - building[i + 2];
			if (L1 < 0 || L2 < 0 || R1 < 0 || R2 < 0) continue;

			int left = min(L1, L2);
			int right = min(R1, R2);
			answer += min(left, right);
		}

		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}