#include <stdio.h>

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int main()
{
	int n, res = 0;
	int arr[1001];
	int dp[1001];

	dp[1] = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i] > res)
			res = dp[i];
	}

	printf("%d\n", res);

	//for (int i = 1; i <= n; i++) {
		//printf("%d ", dp[i]);
	//}
	//printf("\n");
}
