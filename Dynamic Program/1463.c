#include<stdio.h>

int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}

int main()
{
	int n;
	scanf("%d", &n);

	int dp[1000001];
	dp[2] = 1, dp[3] = 1;
	int i = 4;

	while (i <= n) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		i++;
	}
	printf("%d\n", dp[n]);
}
