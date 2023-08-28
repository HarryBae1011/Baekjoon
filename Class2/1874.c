#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100001

int stack[STACK_SIZE];
int top = -1;
char p_m[STACK_SIZE * 2];

int isEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}

int isFull()
{
	if (top >= STACK_SIZE)
		return 1;
	return 0;
}

void push(int data)
{
	if (!isFull()) {
		stack[++top] = data;
	}
}

int pop()
{
	if (isEmpty()) {
		printf("Stack is Empty!\n");
		return 0;
	}
	return stack[top--];
}

int main()
{
	int num = 0, p = 0, n, i = 1;

	scanf("%d", &n);

	int* arr = (int *)malloc(sizeof(int) * n);

	for (int j = 0; j < n; j++) {
		scanf("%d", &arr[j]);
	}

	while(1){
		if(top == -1 || arr[num] > stack[top]) {
			//printf("%d\n", arr[num]);
			p_m[p++] = '+';
			push(i);
			//printf("push : %d\n", i);
			i++;
		}
		else if (arr[num] == stack[top]) {
			p_m[p++] = '-';
			//printf("pop : %d\n", pop());
			pop();
			num++;
		}
		else {
			printf("NO\n");
			return 0;
		}

		if (p == n * 2)
			break;
	}

	for (int j = 0; j < p; j++) {
		printf("%c\n", p_m[j]);
	}

}
