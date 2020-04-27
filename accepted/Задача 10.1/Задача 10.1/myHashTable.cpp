#include "myHashTable.h"
#include "myList.h"

#include <string.h>
#include <stdio.h>

struct MyHashTable
{
	int capacity = 100;
	MyList** hashTable = createArrayOfList(capacity);
};

MyHashTable* createHashTable()
{
	MyHashTable* result = new MyHashTable;
	for (int i = 0; i != result->capacity; ++i)
	{
		result->hashTable[i] = createList();
	}
	return result;
};

int capacityOfHashTable(MyHashTable* hashTable)
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

int hashFunction(MyHashTable* hashTable, char value[])
{
	int result = 0;
	for (int i = 0; value[i] != '\0'; ++i)
	{
		result = (result + powerOfTwo(i) * value[i]) % hashTable->capacity;
	}
	return result;
}

void addElementToHashTable(MyHashTable* hashTable, char value[])
{
	int index = hashFunction(hashTable, value);
	addUniqueElementToList(hashTable->hashTable[index], value);
}

bool isContainInHashTable(MyHashTable* hashTable, char value[])
{
	int index = hashFunction(hashTable, value);
	return isContain(hashTable->hashTable[index], value);
}

int numberOfEntries(MyHashTable* hashTable, char value[])
{
	int number = hashFunction(hashTable, value);
	if (!isContain(hashTable->hashTable[number], value))
	{
		return 0;
	}
	ListElement* currentElement = getHead(hashTable->hashTable[number]);
	while (currentElement != nullptr)
	{
		char temp[100];
		getValue(currentElement, temp);
		if (strcmp(temp, value) == 0)
		{
			return getCounterElement(currentElement);
		}
		currentElement = getNext(currentElement);
	}

	return 0;
}

void printHashTable(MyHashTable* hashTable)
{
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (getHead(hashTable->hashTable[i]) != nullptr)
		{
			ListElement* currentElement = getHead(hashTable->hashTable[i]);
			while (currentElement != nullptr)
			{
				char word[100];
				getValue(currentElement, word);
				printf("%d раз(-а) встречается слово %s", getCounterElement(currentElement), word);
				printf("\n");
				currentElement = getNext(currentElement);
			}
		}
	}
}

float loadFactor(MyHashTable* hashTable)
{
	int numberOfElements = 0;
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (getHead(hashTable->hashTable[i]) != nullptr)
		{
			numberOfElements += numberOfDifferentElements(hashTable->hashTable[i]);
		}
	}

	return (float)numberOfElements / hashTable->capacity;
}

int maxLengthOfListInSegment(MyHashTable* hashTable)
{
	int max = 0;
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		if (getHead(hashTable->hashTable[i]) != nullptr && numberOfDifferentElements(hashTable->hashTable[i]) > max)
		{
			max = numberOfDifferentElements(hashTable->hashTable[i]);
		}
	}

	return max;
}

float averageLengthOfLists(MyHashTable* hashTable)
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

	return (float)sumOfLengths / count;
}

void deleteHashTable(MyHashTable* hashTable)
{
	for (int i = 0; i != hashTable->capacity; ++i)
	{
		deleteList(hashTable->hashTable[i]);
	}

	delete[] hashTable->hashTable;
	delete hashTable;
}