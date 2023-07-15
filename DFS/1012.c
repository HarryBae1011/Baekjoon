#include <stdio.h>

int map[50][50][50] = { 0, };
int cnt[50] = { 0, };

int check(int j, int x, int y, int m, int n)
{
	map[j][x][y] = 0;

	if (x - 1 >= 0 && map[j][x - 1][y] == 1)
		check(j, x - 1, y, m, n);
	if (x + 1 < m && map[j][x + 1][y] == 1)
		check(j, x + 1, y, m, n);
	if (y - 1 >= 0 && map[j][x][y - 1] == 1)
		check(j, x, y - 1, m, n);
	if (y + 1 < n && map[j][x][y + 1] == 1)
		check(j, x, y + 1, m, n);

	return 0;
}

int main()
{
	int t;
	int m, n, k;
	int x, y;
	scanf("%d", &t);

	for (int j = 0; j < t; j++) {
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			map[j][x][y] = 1;
		}
	}

	for (int j = 0; j < t; j++) {
		for (int x1 = 0; x1 < m; x1++) {
			for (int y1 = 0; y1 < n; y1++) {
				if (map[j][x1][y1] == 1) {
					check(j,x1,y1, m, n);
					cnt[j]++;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		printf("%d\n", cnt[i]);
	}
}
