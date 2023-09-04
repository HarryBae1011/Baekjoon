#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int* arr, int L, int R)
{
	int l = L, r = R, tmp;
	int pivot = arr[(L + R) / 2];

	do {
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

	if(L < r)
		quicksort(arr, L, r);
	if(R > l)
		quicksort(arr, l, R);
}

int main()
{
	int n, sum = 0, cnt = 0;
	int* level;
	double cut, avg, num, res;
	scanf("%d", &n);

	cut = n * 0.15;
	num = floor(cut + 0.5);

	level = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &level[i]);
	}

	quicksort(level, 0, n - 1);

	for (int i = num; i < n - num; i++) {
		sum += level[i];
		cnt++;
	}

	avg = (float)sum / (float)cnt;

	res = floor(avg + 0.5);

	if (n == 0)
		res = 0;
	printf("%.f\n", res);
}
