#include <stdio.h>
#define QUEUE_SIZE 1000001

int tomato[101][101][101] = { 0, };

struct Node{
	int x;
	int y;
	int z;
};

struct Node Queue[QUEUE_SIZE];

int front = 0, rear = 0;
int cnt = 0;
int m, n, h;

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int isEmpty()
{
	if (front == rear) {
		return 1;
	}
	return 0;
}

void enque(int i, int j, int k)
{
	struct Node tmp;
	tmp.x = i, tmp.y = j, tmp.z = k;
	Queue[rear] = tmp;
	rear = (rear + 1) % QUEUE_SIZE;
}

struct Node deque()
{
	struct Node tmp = Queue[front];
	front = (front + 1) % QUEUE_SIZE;
	return tmp;
}

int bfs()
{
	int nx, ny, nz;
	struct Node tmp;

	while (isEmpty() == 0) {
		tmp = deque();
		for (int i = 0; i < 6; i++) {
			nx = tmp.x + dx[i];
			ny = tmp.y + dy[i];
			nz = tmp.z + dz[i];
			if (nx > 0 && nx <= m && ny > 0 && ny <= n && nz > 0 && nz <= h) {
				if (tomato[nx][ny][nz] == 0) {
					tomato[nx][ny][nz] = tomato[tmp.x][tmp.y][tmp.z] + 1;
					enque(nx, ny, nz);
					cnt--;
				}
			}
		}
	}

	if (cnt == 0) {
		return tomato[tmp.x][tmp.y][tmp.z] - 1;
	}
	return -1;
}

int main()
{
	scanf("%d %d %d", &m, &n, &h);

	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				scanf("%d", &tomato[k][j][i]);
				if (tomato[k][j][i] == 1) {
					enque(k, j, i);
				}
				else if (tomato[k][j][i] == 0) {
					cnt++;
				}
			}
		}
	}

	printf("%d\n", bfs());

}
