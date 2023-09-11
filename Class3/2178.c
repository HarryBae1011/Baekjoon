#include <stdio.h>
#define QUEUE_SIZE 10000

typedef struct Node {
	int x;
	int y;
}Node;

Node Queue[QUEUE_SIZE];
int front = 0;
int rear = 0;

int miro[101][101] = { 0, };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int isEmpty()
{
	if (front == rear)
		return 1;
	return 0;
}

void enque(int x, int y)
{
	Node tmp;
	tmp.x = x;
	tmp.y = y;

	Queue[rear] = tmp;
	rear = (rear + 1) % QUEUE_SIZE;
}

Node deque()
{
	Node tmp;
	if (!isEmpty()) {
		tmp = Queue[front];
		front = (front + 1) % QUEUE_SIZE;
		return tmp;
	}
}

int bfs(int n, int m)
{
	Node tmp;
	int nx, ny;

	while (isEmpty() == 0) {
		tmp = deque();
		for (int i = 0; i < 4; i++) {
			nx = tmp.x + dx[i], ny = tmp.y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if (miro[nx][ny] == 1) {
					miro[nx][ny] = miro[tmp.x][tmp.y] + 1;
					enque(nx, ny);
				}
			}
			else {
				continue;
			}
		}
	}
	return miro[n][m];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}

	enque(1, 1);
	printf("%d\n", bfs(n, m));

}
