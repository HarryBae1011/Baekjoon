#include <stdio.h>

int main()
{
	int num, tmp, rev = 0, i = 1;
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}

		tmp = num;

		while (tmp != 0) {
			tmp /= 10;
			i *= 10;
		}

		i /= 10;
		tmp = num;

		while (tmp != 0) {
			rev += (tmp % 10) * i;
			tmp /= 10;
			i /= 10;
		}

		if (rev == num)
			printf("yes\n");
		else
			printf("no\n");

		rev = 0;
		i = 1;
	}
}
