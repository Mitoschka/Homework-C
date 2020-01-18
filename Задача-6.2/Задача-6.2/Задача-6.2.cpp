#include <stdio.h>
#include <stdlib.h>

int const N = 1000;

void stringBalance()
{
	printf("Enter the string: ");
	char str[N];
	fgets(str, N, stdin);
	printf("\nThe string: ");
	puts(str);
}

int main()
{
	stringBalance();
	return 0;
}