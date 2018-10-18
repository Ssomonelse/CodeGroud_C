#include <iostream>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	int Test_Case = 10;
	int tc;
	int** map = new int*[100];
	bool** visited = new bool*[100];
	for (int i = 0; i < 100; i++) {
		map[i] = new int[100];
		visited[i] = new bool[100];
	}
	int answer[10];
	for (int i = 0; i < 10; i++) {
		answer[i] = 0;
	}
	for (int t = 0; t < Test_Case; t++) {
		cin >> tc;
		pair<int, int> start, end;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%1d", &map[i][j]);
				switch (map[i][j])
				{
				case 0: visited[i][j] = false; break;
				case 1: visited[i][j] = true; break;
				case 2: visited[i][j] = false; start.first = i; start.second = j; break;
				case 3: visited[i][j] = false; end.first = i; end.second = j; break;
				default:
					break;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push(make_pair(start.first, start.second));
		int x = start.first;
		int y = start.second;
		visited[x][y] = true;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (map[nx][ny] == 3) {
					answer[t] = 1;
					break;
				}
				if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && visited[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << "#" << i + 1 << " " << answer[i] << endl;
	}

	return 0;
}