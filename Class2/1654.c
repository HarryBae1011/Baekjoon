#include <stdio.h>

int main()
{
	int k, n;
	long long x, max = 0, min = 1, sum = 0, res = 0;
	int lan[10001];
	scanf("%d %d", &k, &n);

	for (int i = 1; i <= k; i++) {
		scanf("%d", &lan[i]);
		if (lan[i] > max) {
			max = lan[i];
		}
	}

	while (min <= max) {
		x = (min + max) / 2;

		for (int i = 1; i <= k; i++) {
			sum += lan[i] / x;
		}

		if (sum >= n) {
			if (res < x)
				res = x;
			min = x + 1;
		}
		else {
			max = x - 1;
		}
		sum = 0;
	}

	printf("%d\n", res);
}
