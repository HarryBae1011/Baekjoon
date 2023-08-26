#include <stdio.h>

int main()
{
	int i, j, n, cnt = 0, k = 2;
	int num[101];
	int prime[1000];
	prime[1] = 2;
	prime[2] = 3;

	for (i = 1; i <= 1000; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (i == j) {
			prime[++k] = i;
		}
	}

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (num[i] == prime[j]) {
				cnt++;
				break;
			}
		}
	}

	printf("%d\n", cnt);

}
