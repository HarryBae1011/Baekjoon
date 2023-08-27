#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int count; // Queue안의 노드 개수 카운트
}Queue;

void initQueue(Queue* queue)
{
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int isEmpty(Queue* queue)
{
	return queue->count == 0;
}

void enqueue(Queue* queue, int data)
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;

	if (isEmpty(queue)) {
		queue->front = newnode;
	}
	else {
		queue->rear->next = newnode;
	}

	queue->rear = newnode;
	queue->count++;
}

int dequeue(Queue* queue)
{
	int data;
	Node* ptr;
	if (isEmpty(queue)) {
		printf("Error : Queue is empty!\n");
		return 0;
	}

	ptr = queue->front;
	data = ptr->data;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;

	return data;
}

int main()
{
	int i;
	Queue queue;

	initQueue(&queue);

	for (i = 1; i <= 10; i++) {
		enqueue(&queue, i);
	}

	while (!isEmpty(&queue)) {
		printf("%d ", dequeue(&queue));
	}

	printf("\n");
	return 0;
}

