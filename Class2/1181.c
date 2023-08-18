#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void q_sort(char** arr, int L, int R)
{
	int left = L, right = R;
	char temp[51];
	int pivot = strlen((char *)arr[(int)((left + right) / 2)]);
	do {
		while (strlen((char*)arr[left]) < pivot)
			left++;
		while (strlen((char*)arr[right]) > pivot)
			right--;

		if (left <= right) {
			strcpy(temp, (char*)arr[left]);
			strcpy((char*)arr[left], (char*)arr[right]);
			strcpy((char*)arr[right], temp);
			left++;
			right--;
		}
		
	} while (left <= right);

	while (right > L)
		q_sort(arr, L, right);
	while (left < R)
		q_sort(arr, left, R);
}*/

int compare(const void* a, const void* b)
{   
	if (strlen((char*)a) > strlen((char*)b)) 
		return 1;
	else if (strlen((char*)a) < strlen((char*)b)) 
		return -1;
	else 
		return strcmp((char*)a, (char*)b);
}


int main()
{
	int n;
	char word[20000][51];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}

	qsort(word, n, sizeof(word[0]), compare);

	for (int i = 0; i < n; i++) {
		if (strcmp(word[i], word[i + 1]) == 0 && i + 1 < n)
			continue;
		printf("%s\n", word[i]);
	}
}
