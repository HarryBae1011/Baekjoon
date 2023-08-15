#include <stdio.h>

int minimum(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int main()
{
	char board[51][51];
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}

	int cnt1 = 0, cnt2 = 0, tmp, min = 10000;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			for (int x = i; x <= i + 7; x++) {
				for (int y = j; y <= j + 7; y++) {
					if ((i - x + j - y) % 2 == 0) {
						if (board[x][y] != 'B')
							cnt1++;
					}
					else {
						if (board[x][y] != 'W')
							cnt1++;
					}
				}
			}

			for (int x = i; x <= i + 7; x++) {
				for (int y = j; y <= j + 7; y++) {
					if ((i - x + j - y) % 2 == 0) {
						if (board[x][y] != 'W')
							cnt2++;
					}
					else {
						if (board[x][y] != 'B')
							cnt2++;
					}
				}
			}

			tmp = minimum(cnt1, cnt2);

			if (tmp < min) {
				min = tmp;
			}
			cnt1 = 0;
			cnt2 = 0;
		}
	}

	printf("%d\n", min);
}
