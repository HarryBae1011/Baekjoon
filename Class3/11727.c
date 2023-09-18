#include <stdio.h>

int main()
{
	int n;
	long long int dp[1001];
	dp[1] = 1;
	dp[2] = 3;
	scanf("%d", &n);

	for (int i = 3; i < 1001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	printf("%lld\n", dp[n]);
}
