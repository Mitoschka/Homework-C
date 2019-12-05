#include <stdio.h>
#include <string.h>
const int S = 1000;
int main()
{
	char string[S] = { 0 };
	printf("Enter the first line:  ");
	fgets(string, S, stdin);
	int sizeString = strlen(string) - 1;


	char subString[S] = { 0 };
	printf("Enter the second line:  ");
	fgets(subString, S, stdin);
	int sizeSubString = strlen(subString) - 1;


	int result = 0;
	for (int i = 0; i <= sizeString - sizeSubString; ++i)
	{
		bool matchFlag = true;
		for (int j = 0; j < sizeSubString; ++j)
		{
			if (string[i + j] != subString[j])
			{
				matchFlag = false;
			}
		}
		if (matchFlag)
		{
			result++;
		}

	}
	printf("%d", result);

	return 0;
}