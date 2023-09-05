#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10000

typedef struct Node {
	int index;
	int value;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
}Queue;

void initqueue(Queue* queue)
{
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int isFull(Queue* queue)
{
	if (queue->count > QUEUE_SIZE)
		return 1;
	return 0;
}

int isEmpty(Queue* queue)
{
	if (queue->count == 0)
		return 1;
	return 0;
}

void push(Queue* queue, int index, int value)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->index = index;
	newnode->value = value;

	if (isEmpty(queue)) {
		queue->front = newnode;
	}
	else {
		queue->rear->next = newnode;
	}

	queue->rear = newnode;
	queue->count++;
}

void pop_cycle(Queue* queue)
{
	int index, value;
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (!isEmpty(queue)) {
		tmp = queue->front;
		queue->front = tmp->next;
		index = tmp->index;
		value = tmp->value;
		free(tmp);
		queue->count--;
		push(queue, index, value);
	}
}

void pop(Queue* queue)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (!isEmpty(queue)) {
		tmp = queue->front;
		queue->front = tmp->next;
		free(tmp);
		queue->count--;
	}
}

int main()
{
	int t, n, m, max = 0, max_index, res = 0;
	int doc[101] = { 0, };
	Queue queue;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			scanf("%d", &doc[j]);
			if (doc[j] > max) {
				max = doc[j];
				max_index = j;
			}
		}
			initqueue(&queue);
			for (int k = 0; k < n; k++) {
				push(&queue, k, doc[k]);
			}
			while (1) {
				if (queue.front->value == max) {
					//printf("max : %d\n", max);
					if (queue.front->index == m) {
						res++;
						//printf("index : %d, res : %d\n", queue.front->index, res);
						break;
					}
					else {
						res++;
						//printf("index : %d, res : %d\n", queue.front->index, res);
						pop(&queue);
						max = 0;
						doc[max_index] = 0;
						for (int k = 0; k < n; k++) {
							if (doc[k] > max) {
								max = doc[k];
								max_index = k;
							}
						}
					}
				}
				else {
					pop_cycle(&queue);
				}
			}
		printf("%d\n", res);
		res = 0;
		max = 0;
	}

}
