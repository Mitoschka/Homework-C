#include <stdio.h>
int main()
{
	int x,y;
	scanf("%d", &x);
	int squareOfx = x * x;
	y = (squareOfx + x) * (squareOfx + 1) + 1;
	printf("%d", y);
	return 0;
}

