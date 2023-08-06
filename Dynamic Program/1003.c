#include<stdio.h>

int num[1000];

int main()
{
	int t;
    int fib[100];
    int fib_zero[100];
    int fib_one[100];
    fib_zero[0] = 1;
    fib_zero[1] = 0;
    fib_zero[2] = 1;
    fib_one[0] = 0;
    fib_one[1] = 1;
    fib_one[2] = 1;

    for (int i = 3; i <= 40; i++) {
        fib_zero[i] = fib_zero[i - 1] + fib_zero[i - 2];
        fib_one[i] = fib_one[i - 1] + fib_one[i - 2];
    }

	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
        scanf("%d", &num[i]);
	}

    for (int i = 0; i < t; i++) {
        printf("%d %d\n", fib_zero[num[i]], fib_one[num[i]]);
    }
}
