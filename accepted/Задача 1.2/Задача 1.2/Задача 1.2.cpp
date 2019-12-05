#include <stdio.h>

int abs(int x) {
	return (x > 0) ? x : -x;
}

int sign(int x) {
	return (x < 0) ? -1 : 1;
}

int main()
{
	int dividend, divider;

	printf("Enter the dividend and divider: ");
	scanf("%d %d", &dividend, &divider);

	if (divider == 0) {
		printf("You can't divide by zero");
		return 0;
	}

	int sign_divider = sign(divider);
	int sign_dividend = sign(dividend);
	int result = 0;

	while (abs(dividend) > abs(divider * result)) {
		result++;
	}

	if (sign_dividend > 0 && dividend != sign_divider * result * divider) {
		result--;
	}

	printf("%d", sign_divider * sign_dividend * result);
	return 0;
}
