#include <iostream>

#include "myHashTable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	HashTable * hashTable = createHashTable();

	FILE * file;
	errno_t err = fopen_s(&file, "text.txt", "r");
	if (err != 0)
	{
		printf("Ошибка открытия файла.");
		return 0;
	}

	char word[100];
	while (fscanf_s(file, "%s", word, _countof(word)) != EOF)
	{
		addHashElement(hashTable, word);
	}

	err = fclose(file);
	if (err != 0)
	{
		printf("Ошибка закрытия файла.");
		return 0;
	}

	printHashTable(hashTable);

	printf("Коэффициент заполнения: %f \n", loadFactor(hashTable));
	printf("Максимальная длина списка: %d \n", maxLengthOfListInSegment(hashTable));
	printf("Средняя длина списка: %f", averageLengthOfLists(hashTable));
	deleteHashTable(hashTable);

	return 0;
}