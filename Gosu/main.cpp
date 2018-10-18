#include <iostream>
#include <string.h>
using namespace std;

int main() {

	int row, col;
	cin >> row >> col;

	int **map = new int*[row];

	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		memset(map[i], 0, sizeof(int)*col);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	


	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;

	return 0;
}