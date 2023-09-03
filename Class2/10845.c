#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
}Queue;

void initQueue(Queue* queue)
{
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int isEmpty(Queue* queue)
{
	if (queue->count == 0)
		return 1;
	return 0;
}

void push(Queue* queue, int value)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = value;
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

int pop(Queue* queue)
{
	int value;

	if (isEmpty(queue)) {
		return -1;
	}

	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp = queue->front;
	value = tmp->data;
	queue->front = tmp->next;
	free(tmp);
	queue->count--;

	return value;
}

int print_size(Queue* queue)
{
	return queue->count;
}

int front(Queue* queue)
{
	if (isEmpty(queue)) {
		return -1;
	}
	else {
		return queue->front->data;
	}
}

int back(Queue* queue)
{
	if (isEmpty(queue)) {
		return -1;
	}
	else {
		return queue->rear->data;
	}
}

int main()
{
	int n, p;
	char buffer[30];
	Queue queue;
	scanf("%d", &n);

	initQueue(&queue);

	for (int i = 0; i < n; i++) {
		scanf("%s", buffer);

		if (strncmp(buffer, "push", 4) == 0) {
			scanf("%d", &p);
			push(&queue, p);
		}
		else if (strncmp(buffer, "pop", 3) == 0) {
			printf("%d\n", pop(&queue));
		}
		else if (strncmp(buffer, "size", 4) == 0) {
			printf("%d\n", print_size(&queue));
		}
		else if (strncmp(buffer, "empty", 5) == 0) {
			printf("%d\n", isEmpty(&queue));
		}
		else if (strncmp(buffer, "front", 5) == 0) {
			printf("%d\n", front(&queue));
		}
		else if (strncmp(buffer, "back", 4) == 0) {
			printf("%d\n", back(&queue));
		}
	}

	return 0;
}
