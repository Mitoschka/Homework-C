#include <stdio.h>

const int N = 10000000;

int main(int argc, char* argv[])
{
	printf("Please enter the number: ");
	int num;
	scanf("%d", &num);
	bool sieve[N] = { false };

	for (int i = 2; i * i < N; ++i)
		if (!sieve[i])
			for (int K = i + i; K < N; K += i)
				sieve[K] = true;
	printf("Prime numbers:\n");
	for (int i = 2; i < N; ++i)
		if (!sieve[i] && i > num)
			printf("%3d\n", i);
	printf("\n");
	return 0;
}