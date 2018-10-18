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
	int** map = new int*[16];
	bool** visited = new bool*[16];
	for (int i = 0; i < 16; i++) {
		map[i] = new int[16];
		visited[i] = new bool[16];
	}
	int answer[10];
	for (int i = 0; i < 10; i++) {
		answer[i] = 0;
	}
	for (int t = 0; t < Test_Case; t++) {
		cin >> tc;
		pair<int, int> start, end;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
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
				if (nx >= 0 && nx < 16 && ny >= 0 && ny < 16 && visited[nx][ny] == false) {
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

/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct Info {
int x;
int y;
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1};

int map[16][16];
bool check[16][16];

int goalX, goalY;
int startX, startY;

bool bSucess;
queue<Info> q;

void input() {

bSucess = false;

while (!q.empty()) {
q.pop();
}

for (int row = 0; row < 16; row++) {
for (int col = 0; col < 16; col++) {

scanf("%1d", &map[row][col]);

if (map[row][col] == 2) {
startX = row, startY = col;
}

if (map[row][col] == 3) {
goalX = row; goalY = col;
}

check[row][col] = false;
}
}
}


int main() {


for (int test_case = 1; test_case <= 10; test_case++) {
int T;
cin >> T;
input();

Info start;
start.x = startX; start.y = startY;
q.push(start);
check[startX][startY] = true;

while (!q.empty()) {

int curX = q.front().x;
int curY = q.front().y;

q.pop();

for (int move = 0; move < 4; move++) {
int nextX = curX + dx[move];
int nextY = curY + dy[move];

if (nextX == goalX && nextY == goalY) {
bSucess = true; break;
}

if (map[nextX][nextY] ==0 && !check[nextX][nextY]) {
Info tmp;
tmp.x = nextX; tmp.y = nextY;
q.push(tmp);
check[nextX][nextY] = true;
}
}

if (bSucess) {
break;
}
}

cout << "#" << test_case << " ";
if (bSucess) {
cout << "1" << endl;
}
else {
cout << "0 " << endl;
}
}

return 0;
}
*/