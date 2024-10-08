#include <stdio.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

int isFull() {
	if (top >= STACK_SIZE - 1) {
		printf("Error : Stack is Full!\n");
		return 1;
	}

	return 0;
}

int isEmpty() {
	if (top == -1) {
		printf("Error : Stack is Empty!\n");
		return 1;
	}

	return 0;
}

void push(int data) {
	if (!isFull()) {
		top++;
		stack[top] = data;
	}
}

int pop() {
	if (!isEmpty()) {
		return stack[top--];
	}
}

void printStack() {
	for (int i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main()
{
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);

	printStack();

	for (int i = 0; i < 6; i++) {
		pop();
		printStack();
	}

	return 0;
}
