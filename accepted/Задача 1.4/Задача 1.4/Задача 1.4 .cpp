#include <iostream>
#include <stdio.h>
int main()
{
	int arr[28] = { 0 };
	for (int i = 0; i < 10; ++i)
		for (int k = 0; k < 10; ++k)
			for (int j = 0; j < 10; ++j)
				arr[i + j + k]++;
	int result = 0;
	for (int i = 0; i < 28; ++i)
		result += arr[i] * arr[i];
	printf("%d", result);
	return 0;
}