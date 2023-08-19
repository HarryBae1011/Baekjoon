#include <stdio.h>

int main()
{
	int n, num = 665, tmp, count = 0;
	int res[10001];
	scanf("%d", &n);

	while (n > count) {
		tmp = num;
		while (tmp != 0) {
			if (tmp % 10 == 6) {
				tmp /= 10;
				if (tmp % 10 == 6) {
					tmp /= 10;
					if (tmp % 10 == 6) {
						res[++count] = num;
						if (n == count) {
							printf("%d\n", res[n]);
							break;
						}
						break;
					}
				}
			}
			tmp /= 10;
		}
		num++;
	}
}
