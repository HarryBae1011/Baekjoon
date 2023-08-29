#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int L, int R)
{
	int l = L, r = R, tmp;
	int pivot = arr[(L + R) / 2];

	do
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r) {
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			l++;
			r--;
		}
	} while (l <= r);

	if (L < r)
		sort(arr, L, r);
	if (l < R)
		sort(arr, l, R);
}

int search(int* arr, int value, int size)
{
	int down = 0, up = size;
	int mid;

	while (down <= up) {
		mid = (down + up) / 2;
		if (arr[mid] == value) {
			return 1;
		}
		else if (value > arr[mid]) {
			down = mid + 1;
		}
		else {
			up = mid - 1;
		}
	}

	return 0;
}


int main()
{
	int n, m, find = 0;
	scanf("%d", &n);

	int* a = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);

	int* b = (int *)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	sort(a, 0, n - 1);

	for (int i = 0; i < m; i++) {
		printf("%d\n", search(a, b[i], n - 1));
	}

	free(a);
	free(b);

	return 0;
}
