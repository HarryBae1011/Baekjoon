#include <stdio.h>
#define QUEUE_SIZE 100001

typedef struct Queue {
	int value;
	int depth;
}Queue;

int visit[QUEUE_SIZE];

int main()
{
	Queue q[QUEUE_SIZE];
	int front = 0, rear = 0;
	int n, k;
	scanf("%d %d", &n, &k);

	q[rear].value = n;
	q[rear].depth = 0;
	visit[n] = 1;

	while (q[front].value != k) {
		int new_v;
		if (q[front].value > 0) {
			new_v = q[front].value - 1;
			if (!visit[new_v]) {
				rear++;
				q[rear].value = new_v;
				q[rear].depth = q[front].depth + 1;
				visit[new_v] = 1;
			}
		}
		if (q[front].value < k) {
			new_v = q[front].value + 1;
			if (!visit[new_v]) {
				rear++;
				q[rear].value = new_v;
				q[rear].depth = q[front].depth + 1;
				visit[new_v] = 1;
			}
		}
		if (q[front].value * 2 <= k + 1) {
			new_v = q[front].value * 2;
			if (!visit[new_v]) {
				rear++;
				q[rear].value = new_v;
				q[rear].depth = q[front].depth + 1;
				visit[new_v] = 1;
			}
		}
		front++;
	}

	printf("%d\n", q[front].depth);
}
