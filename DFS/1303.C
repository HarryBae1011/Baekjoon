#include<stdio.h>
#include<stdlib.h>

int n, m, w = 0, b = 0;
char map[101][101];
int visit[101][101] = { 0, };

int dx[] = { 0, 1, -1, 0 }, dy[] = { 1, 0, 0, -1 };

int dfs(int x, int y, char c)
{
	int res = 1;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		if (visit[nx][ny] == 0 && map[nx][ny] == c) {
			res += dfs(nx, ny, c);
		}
	}
	return res;
}

int main()
{
	int tmp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				tmp = dfs(i, j, map[i][j]);
				if (map[i][j] == 'W') {
					w = w + (tmp * tmp);
				}
				else {
					b = b + (tmp * tmp);
				}
			}
		}
	}
	printf("%d %d\n", w, b);
}
