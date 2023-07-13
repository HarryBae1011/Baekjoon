#include <stdio.h>

int main()
{
	int n;
	int time[1000];
	int temp = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &time[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1 ; j < n; j++)
		{
			if (time[i] > time[j])
			{
				temp = time[i];
				time[i] = time[j];
				time[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum += time[i] * (n-i);
	}

	printf("%d\n", sum);

}
