/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
//#include <stdlib.h>
#pragma warning(disable:4996)

int Answer = 0;

int main(void)
{
	int T, test_case;
	int n = 0, i; //, max;
	int num;
	/*int *arr, *temp;
	int cnt = 0;*/
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	// freopen("input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	
	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d", &n);
		Answer = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &num);
			Answer = Answer ^ num;
		}
		/*arr = (int*)malloc(sizeof(int)*n);
		max = 0;
		cnt = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] > max) max = arr[i];
		}
		temp = (int*)malloc(sizeof(int) * (max+1));
		for (i = 0; i <= max; i++) {
			temp[i] = 0;
		}
		for (i = 0; i < n; i++) {
			temp[arr[i]]++;
			if (temp[arr[i]] == 2) temp[arr[i]] = 0;
		}

		for (i = 1; i <= max; i++) {
			if (temp[i] == 1) {
				cnt++;
				if (cnt > 1) {
					Answer = Answer ^ i;
				}
				else {
					Answer = i;
				}
			}
		}*/
		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
		//free(arr);
		//free(temp);
	}

	return 0;//Your program should return 0 on normal termination.
}