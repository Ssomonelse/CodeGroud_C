#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int answer;
int score[1000];
int cnt[101];
int result;

int main() {

	int Test_Case;
	cin >> Test_Case;

	for (int t = 0; t < Test_Case; t++) {
		answer = 0;
		result = 0;
		int tt;
		cin >> tt;

		for (int i = 0; i < 1000; i++) {
			cin >> score[i];
			if (i < 101)
				cnt[i] = 0;
		}

		for (int i = 0; i < 1000; i++) {
			cnt[score[i]]++;
		}
		int m = 0;
		for (int i = 0; i < 101; i++) {
			m = max(m, cnt[i]);
		}
		vector<int> v;
		for (int i = 0; i < 101; i++) {
			if (cnt[i] == m) {
				v.push_back(i);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			answer = max(answer, v[i]);
		}
		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}