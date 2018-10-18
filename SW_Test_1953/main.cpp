#include <iostream>

using namespace std;

int answer[50][50];
int map[50][50];
int visited[50][50];
int N, M, R, C, L;
int result;

typedef struct Info {
	int x, y;
	int type;
	int time;
}Info;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool check(int cur, int nxt, int d) {
	switch (d)
	{
	case 0: {
		if (cur == 1 || cur == 3 || cur == 6 || cur == 7) {
			if (nxt == 2 || nxt == 6 || nxt == 7) return false;
			else return true;
		}
		else if (cur == 2 || cur == 4 || cur == 5) return false;
	} break;
	case 1: {
		if (cur == 1 || cur == 3 || cur == 4 || cur == 5) {
			if (nxt == 2 || nxt == 4 || nxt == 5) return false;
			else return true;
		}
		else if (cur == 2 || cur == 6 || cur == 7) return false;
	} break;
	case 2: {
		if (cur == 1 || cur == 2 || cur == 4 || cur == 7) {
			if (nxt == 3 || nxt == 4 || nxt == 7) return false;
			else return true;
		}
		else if (cur == 3 || cur == 5 || cur == 6) return false;
	} break;
	case 3: {
		if (cur == 1 || cur == 2 || cur == 5 || cur == 6) {
			if (nxt == 3 || nxt == 5 || nxt == 6) return false;
			else return true;
		}
		else if (cur == 3 || cur == 4 || cur == 7) return false;
	} break;
	default:
		break;
	}
}

void sol(Info cur) {

	if (cur.time == 1) {
		answer[cur.x][cur.y] = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		Info nxt = cur;
		nxt.x = cur.x + dx[i];
		nxt.y = cur.y + dy[i];
		nxt.type = map[nxt.x][nxt.y];

		if (nxt.x < 0 || nxt.x >= N || nxt.y < 0 || nxt.y >= M) continue;

		if (!check(cur.type, nxt.type, i)) continue;

		if (visited[nxt.x][nxt.y] == 1) continue;

		visited[nxt.x][nxt.y] = 1;
		nxt.time--;
		if (nxt.time > 1) {
			answer[nxt.x][nxt.y] = 1;
		}
		sol(nxt);
		nxt.time++;
		visited[nxt.x][nxt.y] = 0;
	}

}

int main() {

	int Test_Case;

	cin >> Test_Case;

	for (int t = 0; t < Test_Case; t++) {
		result = 0;

		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				answer[i][j] = 0;
				cin >> map[i][j];
				visited[i][j] = 1;
				if (map[i][j] != 0)
					visited[i][j] = 0;
			}
		}

		Info cur = { R, C, map[R][C], L };

		sol(cur);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (answer[i][j] != 0)
					result++;
			}
		}

		cout << "#" << t + 1 << " " << result << endl;
	}

	return 0;
}