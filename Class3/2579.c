#include <stdio.h>
#include <stdlib.h>

int max_num(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	int n, sum = 0;
	int stair[301];
	int dp[301];
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max_num(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}

	printf("%d\n", dp[n]);

}
