#include <stdio.h>
#include <stdlib.h>

void record(FILE* firstFile, FILE* secondFile)
{
	int readSymbol = 0;
	int i = 0;
	while ((readSymbol = fgetc(firstFile)) != EOF)
	{
		if (readSymbol == '\"')
		{
			if (++i % 2)
			{
				fprintf(secondFile, "\n");
			}
			fprintf(secondFile, "\"");
		}
		else if (i % 2)
		{
			fprintf(secondFile, "%c", readSymbol);
		}
	}
}

void print()
{
	FILE* firstFile = nullptr;
	if ((firstFile = fopen("text.txt", "r")) == nullptr)
	{
		printf("Could not open file...");
		exit(0);
	}
	FILE* secondFile = nullptr;
	if ((secondFile = fopen("quotes.txt", "r")) == nullptr)
	{
		printf("Could not open file...");
		exit(0);
	}
	secondFile = fopen("quotes.txt", "w");
	record(firstFile, secondFile);
	fclose(firstFile);
	fclose(secondFile);
}

int main()
{
	print();
	return 0;
}
