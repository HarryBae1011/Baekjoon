#include <stdio.h>
#include <stdlib.h>

int map[26][26];
int count[625];

int find(int x, int y, int n, int cnt)
{
	map[x][y] = 0;

	count[cnt]++;

	if (x - 1 >= 0 && map[x - 1][y] == 1)
		find(x - 1, y, n, cnt);
	if (x + 1 < n && map[x + 1][y] == 1)
		find(x + 1, y, n, cnt);
	if (y - 1 >= 0 && map[x][y - 1] == 1)
		find(x, y - 1, n, cnt);
	if (y + 1 < n && map[x][y + 1] == 1)
		find(x, y + 1, n, cnt);

	return 0;
}

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				find(i, j, n, cnt);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (count[i] > count[j]) {
				int temp;
				temp = count[i];
				count[i] = count[j];
				count[j] = temp;
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		printf("%d\n", count[i]);
	}
}
