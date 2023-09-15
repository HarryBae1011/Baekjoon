#include <stdio.h>
#include <stdlib.h>

typedef struct time {
	int x;
	int y;
}time;

int compare(const void* a, const void* b)
{
	time A = *(time*)a;
	time B = *(time*)b;
	if (A.y > B.y)
		return 1;
	else if (A.y == B.y)
	{
		if (A.x > B.x)
			return 1;
		else
			return -1;
	}
	else
		return -1;
}

int main()
{
	int n, cnt = 1, x = 0, y = 1;
	time meet[100001];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &meet[i].x , &meet[i].y);
	}

	qsort(meet, n, sizeof(time), compare);

	while (y < n) {
		if (meet[x].y <= meet[y].x) {
			x = y;
			cnt++;
		}
		y++;
	}

	printf("%d\n", cnt);
}
