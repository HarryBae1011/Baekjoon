#include <stdio.h>
#include <string.h>

int graph[1001][1001];
int visit[1001];
int queue[1001];

void dfs(int n, int v)
{
	visit[v] = 1;

	printf("%d ", v);

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0 && graph[v][i] == 1) {
			dfs(n, i);
		}
	}

	return;
}

void bfs(int n, int v)
{
	int front = -1, rear = -1, pop;
	printf("%d ", v);
	visit[v] = 1;
	queue[++rear] = v;

	while (front < rear) {
		pop = queue[++front];
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && graph[pop][i] == 1) {
				printf("%d ", i);
				visit[i] = 1;
				queue[++rear] = i;
			}
		}
	}
}

int main()
{
	int n, m, v;
	int x, y;
	scanf("%d %d %d", &n, &m, &v);
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	dfs(n, v);
	printf("\n");
	memset(visit, 0, sizeof(int) * (n + 1));
	bfs(n, v);
}
