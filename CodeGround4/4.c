/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897
#pragma warning(disable:4996)
int Answer;

typedef struct Score_info {
	double left_inclination;
	double right_inclination;
	int score;
}Score_info;

double getRadian(int n) {
	return n * (PI / 180);
}

void getScore(int x, int y, int* pointboard, Score_info* s, int idx) {
	if ((sqrt(pow(x, 2) + pow(y, 2)) < pointboard[4]) && (sqrt(pow(x, 2) + pow(y, 2)) > pointboard[3]))
		Answer += s[idx].score * 2;
	else if ((sqrt(pow(x, 2) + pow(y, 2)) < pointboard[2]) && (sqrt(pow(x, 2) + pow(y, 2)) > pointboard[1]))
		Answer += s[idx].score * 3;
	else
		Answer += s[idx].score;
}

int main(void)
{
	int T, test_case;
	int pointboard[5] = {0,}, i, j, n;
	int x, y, ts[20] = {13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10, 6};
	double point;
	int degree;
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
		degree = 9;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		for (i = 0; i < 5; i++) {
			scanf("%d", &pointboard[i]);
		}
		Score_info *s = (Score_info*)malloc(sizeof(Score_info) * 20);
		for (i = 0; i < 20; i++) {
			s[i].score = ts[i];
			s[i].right_inclination = tan(getRadian(degree));
			degree += 18;
			s[i].left_inclination = tan(getRadian(degree));
			//printf("%d의 왼=%f, 오=%f\n", s[i].score, s[i].left_inclination, s[i].right_inclination);
		}

		scanf("%d", &n);
		
		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			if ((sqrt(pow(x, 2) + pow(y, 2))) >= pointboard[4]) continue;
			if ((pow(x, 2) + pow(y, 2)) < pow(pointboard[0], 2))
				Answer += 50;
			else if (x == 0) {
				if (y > 0) {
					if (y < pointboard[4] && y > pointboard[3]) Answer += (20 * 2);
					else if (y < pointboard[2] && y > pointboard[1]) Answer += (20 * 3);
					else Answer += 20;
				}
				else {
					if (y > (-1*pointboard[4]) && y < (-1*pointboard[3])) Answer += (2 * 2);
					else if (y > (-1*pointboard[2]) && y < (-1*pointboard[1])) Answer += (3 * 3);
					else Answer += 3;
				}
			}
			else if (y == 0) {
				if (x > 0) {
					if (x < pointboard[4] && x > pointboard[3]) Answer += (6 * 2);
					else if (x < pointboard[2] && x > pointboard[1]) Answer += (6 * 3);
					else Answer += 6;
				}
				else {
					if (x > (-1 * pointboard[4]) && x < (-1 * pointboard[3])) Answer += (11 * 2);
					else if (x >(-1 * pointboard[2]) && x < (-1 * pointboard[1])) Answer += (11 * 3);
					else Answer += 11;
				}
			}
			else {
				point = (double)y / x;
				//printf("현재 다트의 기울기 = %f\n", point);
				if (x > 0 && y > 0) {
					for (j = 0; j < 5; j++) {
						if (point > s[3].left_inclination) {
							getScore(x, y, pointboard, s, 4);
							break;
						}
						else if (point < s[0].right_inclination) {
							getScore(x, y, pointboard, s, 19);
							break;
						}
						else if (s[j].left_inclination > point && s[j].right_inclination < point) {
							getScore(x, y, pointboard, s, j);
							break;
						}
					}
				}
				else if (x < 0 && y > 0) {
					for (j = 5; j < 10; j++) {
						if (point > s[8].left_inclination) {
							getScore(x, y, pointboard, s, 9);
							break;
						}
						else if (point < s[5].right_inclination) {
							getScore(x, y, pointboard, s, 4);
							break;
						}
						else if (s[j].left_inclination > point && s[j].right_inclination < point) {
							getScore(x, y, pointboard, s, j);
							break;
						}
					}
				}
				else if (x < 0 && y < 0) {
					for (j = 10; j < 15; j++) {
						if (point > s[13].left_inclination) {
							getScore(x, y, pointboard, s, 14);
							break;
						}
						else if (point < s[10].right_inclination) {
							getScore(x, y, pointboard, s, 9);
							break;
						}
						else if (s[j].left_inclination > point && s[j].right_inclination < point) {
							getScore(x, y, pointboard, s, j);
							break;
						}
					}
				}
				else if (x > 0 && y < 0) {
					for (j = 15; j < 20; j++) {
						if (point > s[18].left_inclination) {
							getScore(x, y, pointboard, s, 19);
							break;
						}
						else if (point < s[15].right_inclination) {
							getScore(x, y, pointboard, s, 14);
							break;
						}
						else if (s[j].left_inclination > point && s[j].right_inclination < point) {
							getScore(x, y, pointboard, s, j);
							break;
						}
					}
				}
			}

		}

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

		free(s);
	}

	return 0;//Your program should return 0 on normal termination.
}