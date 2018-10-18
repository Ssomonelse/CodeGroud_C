#include <iostream>
#include <algorithm>
using namespace std;

int map[20][20];
int disert[101];
int N;
int answer;
int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };

void init_disert(int* disert) {
	for (int i = 1; i < 101; i++) {
		disert[i] = 0;
	}
}

int main() {

	int Test_Case;
	cin >> Test_Case;

	for (int t = 0; t < Test_Case; t++) {
		cin >> N;
		answer = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((i == 0 && j == 0) || (i == 0 && j == N - 1) || (i == N - 1 && j == 0) || (i == N - 1 && j == N - 1)) continue;

				init_disert(disert);
				sum = 0;
				int flag = 0;
				for (int q = 1; q < N - j; q++) {
					//printf("q = %d\n", q);
					init_disert(disert);
					disert[map[i][j]]++;
					if (q != 1) {
						for (int z = 1; z < q; z++) {
							disert[map[i+z][j+z]]++;
							if (disert[map[i + z][j + z]] > 1) {
								flag = 1;
							}
						}
					}
					int ni = i + q;
					int nj = j + q;
					if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
					if (disert[map[ni][nj]] != 0 || flag == 1) {
						continue;
					}
					disert[map[ni][nj]] = 1;
					/*printf("disert => ");
					for (int u = 1; u < 101; u++) {
						if (disert[u] != 0) {
							printf("%d ", u);
						}
					}
					printf("\n");
					printf("map[%d][%d] = %d\n", ni, nj, map[ni][nj]);*/
					
					int flag2 = 0;
					for (int w = 1; w < N - ni; w++) {
						//printf("w = %d\n", w);
						if (w != 1) {
							for (int z = 1; z < w; z++) {
								disert[map[ni + z][nj - z]]++;
								if (disert[map[i + z][j - z]] > 1) {
									flag2 = 1;
								}
							}
						}
						sum = 0;
						int ni2 = ni + w;
						int nj2 = nj - w;
						if (flag2 == 1) continue;
						if (ni2 < 0 || ni2 >= N || nj2 < 0 || nj2 >= N) continue;
						if (disert[map[ni2][nj2]] != 0) {
							flag2 = 1;
							continue;
						}

						disert[map[ni2][nj2]] = 1;
						/*printf("disert => ");
						for (int u = 1; u < 101; u++) {
							if (disert[u] != 0) {
								printf("%d ", u);
							}
						}
						printf("\n");
						printf("map[%d][%d] = %d\n", ni2, nj2, map[ni2][nj2]);*/
						
						int flag3 = 0;
						for (int e = 1; e <= q; e++) {
							if (flag3 == 1) {
								continue;
							}
							//printf("e = %d\n", e);
							int ni3 = ni2 - e;
							int nj3 = nj2 - e;
							if (ni3 < 0 || ni3 >= N || nj3 < 0 || nj3 >= N) continue;
							if (disert[map[ni3][nj3]] != 0) {
								flag3 = 1;
								continue;
							}

							disert[map[ni3][nj3]] = 1;
							if (e != q) continue;
							/*printf("disert => ");
							for (int u = 1; u < 101; u++) {
								if (disert[u] != 0) {
									printf("%d ", u);
								}
							}
							printf("\n");
							printf("map[%d][%d] = %d\n", ni3, nj3, map[ni3][nj3]);*/
							int flag4 = 0;
							for (int r = 1; r <= w; r++) {
								if (flag4 == 1) {
									continue;
								}
								//printf("r = %d\n", r);
								int ni4 = ni3 - r;
								int nj4 = nj3 + r;
								if (ni4 < 0 || ni4 >= N || nj4 < 0 || nj4 >= N) continue;
								if (r != w && disert[map[ni4][nj4]] != 0) {
									flag4 = 1;
									continue;
								}
								disert[map[ni4][nj4]] = 1;
								/*printf("disert => ");
								for (int u = 1; u < 101; u++) {
									if (disert[u] != 0) {
										printf("%d ", u);
									}
								}
								printf("\n");
								printf("map[%d][%d] = %d\n", ni4, nj4, map[ni4][nj4]);*/
								if (r == w) {
									sum = 2 * q + 2 * w;
									answer = max(answer, sum);
									//printf("answer = %d\n", answer);
								}
							}
							init_disert(disert);
							disert[map[i][j]] = 1;
							int ki, kj, ki2, kj2;
							for (int k = 1; k <= q; k++) {
								disert[map[i + k][j + k]] = 1;
								ki = i + k;
								kj = j + k;
							}
							for (int k = 1; k <= w; k++) {
								disert[map[ki + k][kj - k]] = 1;
								ki2 = ki + k;
								kj2 = kj - k;
							}
							for (int k = 1; k <= e; k++) {
								disert[map[ki2 - k][kj2 - k]] = 1;
							}
						}
						init_disert(disert);
						disert[map[i][j]] = 1;
						int ki, kj;
						for (int k = 1; k <= q; k++) {
							disert[map[i + k][j + k]] = 1;
							ki = i + k;
							kj = j + k;
						}
						for (int k = 1; k <= w; k++) {
							disert[map[ki + k][kj - k]] = 1;
						}
					}
				}
			}
		}

		cout << "#" << t + 1 << " " << answer << endl;
	}

	return 0;
}