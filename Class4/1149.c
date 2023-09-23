#include <stdio.h>

int min(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}

int main()
{
	int n, res = 100000;
	int dp[1001][4];
	int map[1001][4];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &map[i][1], &map[i][2], &map[i][3]);
	}

	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
	dp[1][3] = map[1][3];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + map[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + map[i][2];
		dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]) + map[i][3];
	}

	for (int i = 1; i < 4; i++) {
		if (dp[n][i] < res) {
			res = dp[n][i];
		}
	}

	printf("%d\n", res);
}
