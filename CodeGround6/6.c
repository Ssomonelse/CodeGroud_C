/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int Answer;

int main(void)
{
	int T, test_case;
	int N, K, i, j, flag = 1, n, row, col, tN;
	int **arr;
	char move;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	// freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		n = 1;
		row = col = 0;
		flag = 1;
		tN = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		scanf("%d %d", &N, &K);

		arr = (int**)malloc(sizeof(int*)*N);

		for (i = 0; i < N; i++) {
			arr[i] = (int*)malloc(sizeof(int)*N);
			//memset(arr[i], 0, sizeof(short)*N);
		}

		tN = N;
		for (i = 1; i <= (2 * N - 1); i++) {
			if (i <= N) {
				for (j = 1; j <= i; j++) {
					if (flag == 1) {
						arr[row][col] = n;
						if (i != 1 && j != i) {
							row--;
							col++;
						}
						n++;
					}
					else {
						arr[row][col] = n; //-------------------------------------7*7 이런거 직접 그려서 테스트해보기
						if (j != i) {
							row++;
							col--;
						}
						n++;
					}
				}
				if (flag == 1) {
					flag = 0;
					if(i!=N)
						col++;
				}
				else {
					flag = 1;
					if(i!=N)
						row++;
				}
			}
			else {
				tN--;
				if (flag == 0) {
					flag = 1;
					row++;
				}
				else {
					flag = 0;
					col++;
				}
				for (j = 1; j <= tN; j++) {
					if (flag == 1) {
						arr[row][col] = n;
						if (j != tN) {
							row++;
							col--;
						}
						n++;
					}
					else {
						arr[row][col] = n;
						if (j != tN) {
							row--;
							col++;
						}
						n++;
					}
				}
			}
		}

		row = col = 0;
		Answer += arr[row][col];
		getchar();

		for (i = 0; i < K; i++) {
			scanf("%c", &move);
			switch (move)
			{
			case 'U': Answer += arr[--row][col]; break;
			case 'D': Answer += arr[++row][col]; break;
			case 'L': Answer += arr[row][--col]; break;
			case 'R': Answer += arr[row][++col]; break;
			
			}
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

		for (j = 0; j < N; j++)
			free(arr[j]);
		free(arr);
	}

	return 0;//Your program should return 0 on normal termination.
}