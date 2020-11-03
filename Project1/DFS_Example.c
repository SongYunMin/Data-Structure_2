#include <stdio.h>
#include <math.h>
int answer = 2100000000;

void dfs(int n, int number, int idx, int sum)
{
	if (idx > 8)
		return 0;
	if (sum == number) {
		answer = min(idx, answer);
	}

	int temp = 0;

	for (int i = 1; i <= 8; i++) {
		temp = temp * 10 + n;
		dfs(n, number, idx + i, sum + temp);
		dfs(n, number, idx + i, sum - temp);
		dfs(n, number, idx + i, sum / temp);
		dfs(n, number, idx + i, sum * temp);
	}
}

int solution(int N, int number)
{
	dfs(N, number, 0, 0);
	if (answer > 8)
		return -1;
	return answer;
}

int min(int idx, int answer)
{
	if (idx > answer) {
		return answer;
	}
	else {
		return idx;
	}
}



int main(void)
{
	int N = 5;
	int number = 12;
	int a = solution(N, number);
	printf("%d", a);

	return 0;
}
