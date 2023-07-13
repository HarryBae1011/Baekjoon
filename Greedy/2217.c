#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

int temp[MAX];

void mergeSort(int* arr, int left, int right)
{
	if (left == right) { return; }
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void merge(int* arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) { temp[k++] = arr[i++]; }
	while (j <= right) { temp[k++] = arr[j++]; }
	for (int a = left; a <= right; a++)
	{
		arr[a] = temp[a];
	}

	return;
}

int main()
{
	int n;
	int max = 0;
	scanf("%d", &n);
	int* rope = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &rope[i]);
	}

	mergeSort(rope, 0, n-1);

	for (int i = 0; i < n; i++) {
		if(rope[i] * (n - i) > max)
			max = rope[i] * (n - i);
	}

	printf("%d\n", max);
}
