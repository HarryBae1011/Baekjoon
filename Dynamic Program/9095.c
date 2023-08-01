#include<stdio.h>

int main()
{
	int t;
	int testcase[20];
	int dp[20];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int res;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &testcase[i]);
	}

	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	for (int i = 0; i < t; i++) {
		res = dp[testcase[i]];
		printf("%d\n", res);
	}
}
