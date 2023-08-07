#include<stdio.h>

int main()
{
	int n, cnt = 0;
	int share1, share2, left1;
	scanf("%d", &n);

	if (n == 3)
		printf("1\n");
	else if (n == 4)
		printf("-1\n");
	else {
		share1 = n / 5;
		left1 = n % 5;
		cnt = share1;
		while (share1 >= 0) {
			if (share1 == 0) {
				//printf("printf\n");
				share2 = left1 / 3;
				left1 = left1 % 3;
				cnt += share2;
				if (left1 != 0) {
					share1 = -1;
					cnt = -1;
					//printf("printf\n");
					break;
				}
				else {
					break;
				}
			}
			if (left1 == 0)
				break;
			share2 = left1 / 3;
			left1 = left1 % 3;
			if (left1 == 0) {
				cnt += share2;
				break;
			}
			else {
				left1 = left1 + 5 + (share2 * 3);
				share1--;
				cnt--;
			}
		}
		printf("%d\n", cnt);
	}
}
