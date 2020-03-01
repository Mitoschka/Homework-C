#include <stdio.h>
#include <iostream>

#include "myHashTable.h"

bool test()
{
	bool isCorrect = true;
	MyHashTable* testHashTable = createHashTable();
	char word1[] = { 't', 'e', 's', 't', '\0' };
	char word2[] = { 't', 'e', 's', 't', 'a', 'g', 'a', 'i', 'n', '\0' };

	addElementToHashTable(testHashTable, word1);

	if (!isContainInHashTable(testHashTable, word1))
	{
		printf("Тест 1 не пройден.\n");
		isCorrect = false;
	}

	float loadFactorBefore = loadFactor(testHashTable);

	addElementToHashTable(testHashTable, word1);
	addElementToHashTable(testHashTable, word2);
	addElementToHashTable(testHashTable, word1);

	float loadFactorAfter = loadFactor(testHashTable);

	if (numberOfEntries(testHashTable, word1) != 3)
	{
		printf("Тест 2 не пройден.\n");
		isCorrect = false;
	}

	if (loadFactorAfter == loadFactorBefore)
	{
		printf("Тест 3 не пройден.\n");
		isCorrect = false;
	}

	deleteHashTable(testHashTable);

	return isCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		printf("Тесты не пройдены.");
		return 0;
	}

	MyHashTable* hashTable = createHashTable();

	FILE* file;
	errno_t err = fopen_s(&file, "text.txt", "r");
	if (err != 0)
	{
		printf("Ошибка открытия файла.");
		return 0;
	}

	char word[100];
	while (fscanf_s(file, "%s", word, _countof(word)) != EOF)
	{
		addElementToHashTable(hashTable, word);
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