#include <stdio.h>
#include <string.h>
#include "PhoneBook.h"

PhoneBook* createPhoneBook()
{
	return new PhoneBook;
}


void deleteBook(PhoneBook* phoneBook)
{
	while (phoneBook->head != nullptr)
	{
		Record* temp = phoneBook->head->next;
		delete phoneBook->head;
		phoneBook->head = temp;
	}

	delete phoneBook;
}

Record* removeRecordFromBook(PhoneBook* phoneBook)
{
	Record* temp = phoneBook->head;
	phoneBook->head = phoneBook->head->next;
	--phoneBook->numberOfRecords;
	temp->next = nullptr;
	return temp;
}

bool isRecordsRead(PhoneBook* phoneBook)
{
	FILE* file = fopen("Text.txt", "r");
	if (file == NULL)
	{
		fclose(file);
		return false;
	}

	char name[maxSize]{};
	int number = 0;
	while (fscanf(file, "%s%d", name, &number) != EOF)
	{
		Record* recordInBook = new Record;
		strcpy(recordInBook->name, name);
		recordInBook->number = number;
		recordInBook->next = phoneBook->head;
		phoneBook->head = recordInBook;
		++phoneBook->numberOfRecords;
	}

	fclose(file);

	return true;
}

void addRecordInPhoneBook(PhoneBook* phoneBook, Record* recordInBook)
{
	recordInBook->next = phoneBook->head;
	phoneBook->head = recordInBook;
	++phoneBook->numberOfRecords;
}

PhoneBook* reverseBook(PhoneBook* phoneBook)
{
	PhoneBook* tempBook = new PhoneBook;
	while (phoneBook->head != nullptr)
	{
		addRecordInPhoneBook(tempBook, removeRecordFromBook(phoneBook));
	}
	deleteBook(phoneBook);
	return tempBook;
}

bool compareRecords(PhoneBook* firstBook, PhoneBook* secondBook, bool& isNumberSort)
{
	if (isNumberSort)
	{
		return (firstBook->head->number > secondBook->head->number);
	}

	return (strcmp(firstBook->head->name, secondBook->head->name) > 0);
}

// Слияние двух списков в один.
PhoneBook* merge(PhoneBook* phoneBook, PhoneBook* tempBook, bool& isNumberSort)
{
	PhoneBook* resultBook = new PhoneBook;
	int sizeOfResultBook = phoneBook->numberOfRecords + tempBook->numberOfRecords;

	phoneBook = reverseBook(phoneBook);
	tempBook = reverseBook(tempBook);

	for (int i = 0; i != sizeOfResultBook; ++i)
	{
		if (phoneBook->numberOfRecords && tempBook->numberOfRecords)
		{
			if (compareRecords(phoneBook, tempBook, isNumberSort))
			{
				addRecordInPhoneBook(resultBook, removeRecordFromBook(phoneBook));
			}
			else
			{
				addRecordInPhoneBook(resultBook, removeRecordFromBook(tempBook));
			}
		}
		else if (phoneBook->numberOfRecords)
		{
			addRecordInPhoneBook(resultBook, removeRecordFromBook(phoneBook));
		}
		else
		{
			addRecordInPhoneBook(resultBook, removeRecordFromBook(tempBook));
		}
	}

	deleteBook(phoneBook);
	deleteBook(tempBook);

	return resultBook;
}

// Сортировка слиянием.
PhoneBook* mergeSort(PhoneBook* phoneBook, bool& isNumberSort)
{
	if (phoneBook->numberOfRecords != 1)
	{
		PhoneBook* tempBook = new PhoneBook;
		int middle = phoneBook->numberOfRecords / 2;
		while (phoneBook->numberOfRecords > middle)
		{
			addRecordInPhoneBook(tempBook, removeRecordFromBook(phoneBook));
		}

		phoneBook = merge(mergeSort(phoneBook, isNumberSort), mergeSort(tempBook, isNumberSort), isNumberSort);

	}

	return phoneBook;
}

void showBook(PhoneBook* phoneBook)
{
	Record* currentRecord = phoneBook->head;
	printf("Отсортированная телефонная книга: \n");
	while (currentRecord != nullptr)
	{
		printf("%s %d \n", currentRecord->name, currentRecord->number);
		currentRecord = currentRecord->next;
	}
}

void putRecordsToArray(PhoneBook* phoneBook, int numbers[])
{
	Record* currentRecord = phoneBook->head;
	int i = 0;
	while (currentRecord != nullptr)
	{
		numbers[i] = currentRecord->number;
		++i;
		currentRecord = currentRecord->next;
	}
}