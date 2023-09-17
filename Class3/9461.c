#include <stdio.h>

int main()
{
	int t, n;
	long long int dp[101];
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}
