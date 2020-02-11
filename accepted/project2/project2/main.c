#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *readFile(char name[])
{
	FILE *file = fopen(name, "r");
	if (!file)
	{
		return 0;
	}

	char line [256];
	char *str;
	const int symb = 256;
	char* result = (char*)malloc(symb* sizeof(char));
	strcpy(result, "");
	int currInx = 0;
	while (!feof(file))
	{
		fgets(line, symb, file);
		str = strchr(line, ' ');
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			if (str[i] != ' ' && str[i] != '\n')
			{
				result[currInx++] = str[i];
				result[currInx++] = ' ';
			}

		}
	}
	result[currInx] = '\0';
	fclose(file);
	return result;
}

void saveFile(char name[], char *str)
{
	FILE *file;
	file = fopen(name, "w");
	fprintf(file, "%s", str);
	fclose(file);
}

int test()
{
	char *fileName = "input.txt";
	char *result = readFile(fileName);
}

int main()
{
	if (!test())
	{
		printf("\nerror!\n");
		return 0;
	}

	char *str = readFile("input.txt");
	saveFile("output.txt", str);
	printf("Result: %s\n", str);
	return 0;
}
