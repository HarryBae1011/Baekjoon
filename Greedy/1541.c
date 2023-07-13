#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int plus(char* input)
{
	int res = 0;
	int tmp = 0;
	int len = strlen(input);
	for (int i = 0; i <= len ; i++)
	{
		if (input[i] == '+' || i == len) {
			res += tmp;
			//printf("tmp = %d\n", tmp);
			tmp = 0;
			//printf("res = %d\n", res);
		}
		else {
			tmp = tmp * 10;
			tmp = tmp + input[i] - '0';
			//printf("tmp = %d\n", tmp);
		}
	}
	return res;
}

int main()
{
	char input[51];
	int res = 0;
	int temp;
	int cnt = 0;
	char ptr_t[51];

	scanf("%s", &input);

	char* ptr = strtok(input, "-");

	while (ptr != NULL) {
		//printf("%s\n", ptr);
		if (cnt == 0)
		{
			strcpy(ptr_t, ptr);
			temp = plus(ptr_t);
			res += temp;
			cnt++;
			//printf("%d\n", res);
		}
		else {
			strcpy(ptr_t, ptr);
			temp = plus(ptr_t);
			res -= temp;
			//printf("%d\n", res);
		}
		ptr = strtok(NULL, "-");
	}

	printf("%d\n", res);

}
