#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Info {
	int x, y;
	int height;
	int usedK;
	int len;
}Info;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N, K;
int map[8][8];
int visited[8][8];

int answer;

void sol(Info cur) {
	answer = max(cur.len, answer);

	for (int i = 0; i < 4; i++) {
		Info nxt = cur;
		nxt.x += dx[i];
		nxt.y += dy[i];
		nxt.height = map[nxt.x][nxt.y];
		
		if (nxt.x < 0 || nxt.x >= N || nxt.y < 0 || nxt.y >= N) continue;

		if (visited[nxt.x][nxt.y]) continue;

		if (cur.height > nxt.height) {
			nxt.len++;
			visited[nxt.x][nxt.y] = 1;
			sol(nxt);
			visited[nxt.x][nxt.y] = 0;
		}
		else {
			if (cur.usedK != 1 && nxt.height - K < cur.height) {
				nxt.usedK = 1;
				nxt.len++;
				visited[nxt.x][nxt.y] = 1;
				nxt.height = cur.height - 1;
				sol(nxt);
				visited[nxt.x][nxt.y] = 0;
			}
		}
	}
}

int main() {

	int Tast_Case;

	cin >> Tast_Case;

	for (int i = 0; i < Tast_Case; i++) {
		answer = 0;
		cin >> N >> K;

		int heightest = 0;
		for (int q = 0; q < N; q++) {
			for (int w = 0; w < N; w++) {
				cin >> map[q][w];
				heightest = max(heightest, map[q][w]);
				visited[q][w] = 0;
			}
		}
		for (int q = 0; q < N; q++) {
			for (int w = 0; w < N; w++) {
				if (map[q][w] == heightest) {
					Info cur = { q, w, map[q][w], 0, 1 };
					visited[q][w] = 1;
					sol(cur);
					visited[q][w] = 0;
				}
			}
		}
		

		cout << "#" << i + 1 << " " << answer << endl;
	}

	return 0;
}