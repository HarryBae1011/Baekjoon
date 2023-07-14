#include <stdio.h>
#include <stdlib.h>

int visit[100];
int pc[100][100];
int virus = 0;

void check_connect(int n, int k);

int main()
{

	int com;
	int connect;
	int x, y;
	scanf("%d", &com);
	scanf("%d", &connect);

	for (int i = 0; i < connect; i++) {
		scanf("%d %d", &x, &y);
		pc[x - 1][y - 1] = 1;
		pc[y - 1][x - 1] = 1;
	}
	visit[0] = 1;
	check_connect(com, 0);

	printf("%d\n", virus);
}

void check_connect(int n, int k)
{
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && pc[k][i] == 1) {
			visit[i] = 1;
			check_connect(n, i);
			virus++;
		}
	}
}
