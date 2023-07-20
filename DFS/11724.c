#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int map[1001][1001];
int visit[1001];
int cnt = 0;

void dfs(int x, int v)
{
	for (int i = 1; i <= v; i++) {
		if (visit[i] == 0 && map[x][i] == 1) {
			//printf("%d\n", i);
			visit[i] = 1;
			map[x][i] = 0;
			map[i][x] = 0;
			dfs(i, v);
		}
	}
}

int main()
{
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		map[u][v] = 1;
		map[v][u] = 1;
	}

	visit[1] = 1;
	//printf("1\n");
	dfs(1, n);
	cnt++;

	for (int i = 2; i <= n; i++) {
		if (visit[i] == 0) {
			dfs(i, n);
			cnt++;
		}
	}

	if (m == 0)
		printf("%d\n", n);
	else
		printf("%d\n", cnt);
}
