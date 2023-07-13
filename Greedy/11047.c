#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k;
	int* value;
	int cnt = 0;

	scanf("%d %d", &n, &k);

	value = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value[i]);
	}

	for (int i = n-1; i >= 0; i--)
	{
		if (k - value[i] >= 0)
		{
			while (k >= value[i])
			{
				k -= value[i];
				cnt++;
				if (k == 0)
					break;
			}
		}
	}

	printf("%d\n", cnt);
}
