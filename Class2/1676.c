#include <stdio.h>

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int count(int n)
{
	int cnt_2 = 0, cnt_5 = 0;
	int tmp;

	while (n > 0) {
		tmp = n;

		if (tmp % 2 == 0) {
			while (tmp % 2 == 0) {
				cnt_2++;
				tmp /= 2;
			}
		}

		if(tmp % 5 == 0){
			while (tmp % 5 == 0) {
				cnt_5++;
				tmp /= 5;
			}
		}
		n--;
	}

	return min(cnt_2, cnt_5);
}

int main()
{
	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("0\n");
	}
	else {
		printf("%d\n", count(n));
	}
}
