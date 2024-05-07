#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 10000

int stack[STACK_SIZE];
int top = -1;

int isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if (top >= STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(int value)
{
	if (isFull() != 1) {
		stack[++top] = value;
	}
}

int pop() {
	if (isEmpty() != 1)
		return stack[top--];
	else
		return -1;
}

int size()
{
	return top + 1;
}

int p_top()
{
	if (isEmpty() == 0)
		return stack[top];
	else
		return -1;
}

int main()
{
	int n, tmp;
	char buffer[30];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", buffer);

		if (strncmp(buffer, "push", 4) == 0) {
			scanf("%d", &tmp);
			push(tmp);
		}
		else if (strncmp(buffer, "pop", 3) == 0) {
			printf("%d\n", pop());
		}
		else if (strncmp(buffer, "size", 4) == 0) {
			printf("%d\n", size());
		}
		else if (strncmp(buffer, "empty", 5) == 0) {
			printf("%d\n", isEmpty());
		}
		else if (strncmp(buffer, "top", 3) == 0) {
			printf("%d\n", p_top());
		}
	}
}
