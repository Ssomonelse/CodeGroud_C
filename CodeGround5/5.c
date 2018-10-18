/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <stdlib.h>
#define P 2000003
#pragma warning(disable:4996)
unsigned long int Answer;

unsigned long int binomial_coefficient2(int n, int k);
int factorial(int n, int k, int i, int *nanugi, int f);

unsigned long int binomial_coefficient(int n, int k) {
	unsigned long int sum = 0;
	int a1, b1, a2, b2;

	if (n == k || k == 0) return 1;
	if (n - k == 1 || k == 1) return n;

	if (k - 1 < n - k) { a1 = n - 1; b1 = k - 1; }
	else { a1 = n - 1; b1 = n - k; }

	if (k < n - 1 - k) { a2 = n - 1; b2 = k; }
	else { a2 = n - 1; b2 = n - 1 - k; }

	sum += (binomial_coefficient(a1, b1) + binomial_coefficient(a2, b2));

	return sum;
}

unsigned long int binomial_coefficient2(int n, int k) {
	unsigned long int result = 0;
	int *nanugi, i;
	if (n == k || k == 0) {
		//printf("return 1\n");
		return 1;
	}
	else if (n - k == 1 || k == 1) {
		//printf("return2 %d\n", n);
		return n;
	}
	
	nanugi = (int*)malloc(sizeof(int)*(k+1));

	for (i = k; i > 0; i--) {
		nanugi[i] = i;
	}

	result = factorial(n, k, 1, nanugi, n);
	//printf("return3 %d\n", result);

	//free(nanugi);
	return result;
}

int factorial(int n, int k, int i, int *nanugi, int f) {
	unsigned long int result = 1;
	int j, temp = n;
	int a=1;

	if (n == 1) return 1;
	else if (i == k) return n;

	for (j = k; j > 1; j--) {
		if (nanugi[j] != 1 && temp % j == 0) {
			temp = temp / j;
			nanugi[j] = 1;
		}
	}
	result = temp * factorial(n - 1, k, i + 1, nanugi, f);

	if (n == f) {
		for (j = 1; j < k+1; j++) {
			if (nanugi[j] != 1)
				a *= nanugi[j];
		}
		result /= a;
	}
	return result;
}

int binomial_coefficient3(int n, int k, int *f) {
	int nn, kk, i;
	int res = 1;
	for (i = 1; i <= P - 1; i++)
		f[i] = f[i - 1] * i % P;
	while (n && k) {
		nn = n % P;
		kk = k % P;
		if (nn < kk) {
			res = 0;
			break;
		}
		res = (res * f[nn]) % P;
		for (i = 0; i < P - 2; i++)
			res = ((res * f[kk]) % P * f[nn - kk]) % P;
		n /= P, k /= P;
	}
	return res;
}
int main(void)
{
	int T, test_case;
	int N, M, i, j;
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
		int *f = (int*)malloc(sizeof(int) * P);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		scanf("%d %d", &N, &M);

		//printf("%d C %d = %d\n", N, M, binomial_coefficient2(N, M));

		for (i = 0; i <= N; i++) {
			for (j = 0; j <= M; j++) {
				if (i < j) {
					//printf("%d C %d\n", i + j, i);
					Answer += binomial_coefficient3(i + j, i, f);
					//Answer %= 1000000007;
				}
				else {
					//printf("%d C %d\n", i + j, j);
					Answer += binomial_coefficient3(i + j, j, f);
					//Answer %= 1000000007;
				}
			}
		}

		Answer %= 1000000007;
		printf("Case #%d\n", test_case + 1);
		printf("%lu\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}