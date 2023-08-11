#include<stdio.h>

int main()
{
	int t, n[10001], k[10001], max_k = 0, max_n = 0;
	int dp[10001][16];
	for (int i = 1; i < 15; i++) {
		dp[0][i] = i;
	}

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &k[i], &n[i]);
		if (k[i] > max_k)
			max_k = k[i];
		if (n[i] > max_n)
			max_n = n[i];
	}

	for (int i = 1; i <= max_k; i++) {
		for (int j = 1; j <= max_n; j++) {
			if (j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}


	for (int i = 0; i < t; i++) {
		printf("%d\n", dp[k[i]][n[i]]);
	}
}
