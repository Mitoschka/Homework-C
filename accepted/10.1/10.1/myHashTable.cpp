#include "myHashTable.h"
#include "myList.h"

struct HashTable
{
	int capacity = 100;
	List ** hashTable = createArrayOfList(capacity);
};

HashTable * createHashTable()
{
	HashTable * result = new HashTable;
	for (int i = 0; i != result->capacity; ++i)
	{
		result->hashTable[i] = createList();
	}
	return result;
};

int capacityOfHashTable(HashTable * hashTable)
{
	return hashTable->capacity;
}

int powerOfTwo(int degree)
{
	int result = 1;
	for (int i = 0; i != degree; ++i)
	{
		result *= 2;
	}

	return result;
}

int hashFunction(HashTable * hashTable, char value[])
{
	int result = 0;
	for (int i = 0; value[i] != '\0'; ++i)
	{
		result = (result + powerOfTwo(i) * value[i]) % hashTable->capacity;
	}
	return result;
}

void addHashElement(HashTable * hashTable, char value[])
{
	int number = hashFunction(hashTable, value);
	addElementToList(hashTable->hashTable[number], value);
}

void printHashTable(HashTable * hashTable)
{
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (getHead(hashTable->hashTable[i]) != nullptr)
		{
			printf("%d раз(-а) встречается слово ", numberOfElements(hashTable->hashTable[i]));
			printHead(hashTable->hashTable[i]);
			printf("\n");
		}
	}
}

float loadFactor(HashTable * hashTable)
{
	int numberOfElements = 0;
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (getHead(hashTable->hashTable[i]) != nullptr)
		{
			numberOfElements += numberOfDifferentElements(hashTable->hashTable[i]);
		}
	}

	return (float) numberOfElements / hashTable->capacity;
}

int maxLengthOfListInSegment(HashTable * hashTable)
{
	int max = 0;
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (numberOfDifferentElements(hashTable->hashTable[i]) > max)
		{
			max = numberOfDifferentElements(hashTable->hashTable[i]);
		}
	}

	return max;
}

float averageLengthOfLists(HashTable * hashTable)
{
	int count = 0;
	int sumOfLengths = 0;
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (getHead(hashTable->hashTable[i]) != nullptr && numberOfDifferentElements(hashTable->hashTable[i]) != 0)
		{
			++count;
			sumOfLengths += numberOfDifferentElements(hashTable->hashTable[i]);
		}
	}

	return (float)(sumOfLengths / count);
}

void deleteHashTable(HashTable * hashTable)
{
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		deleteList(hashTable->hashTable[i]);
	}

	delete[] hashTable->hashTable;
	delete hashTable;
}