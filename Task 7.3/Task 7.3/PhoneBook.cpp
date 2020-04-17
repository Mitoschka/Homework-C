#include <stdio.h>
#include <string.h>
#include "PhoneBook.h"

struct Record
{
	int number;
	char name[maxSize]{};
	Record* next = nullptr;
};

struct PhoneBook
{
	int numberOfRecords = 0;
	Record* head = nullptr;
};

PhoneBook* createPhoneBook()
{
	return new PhoneBook;
}

Record* createRecord(int number, char newName[])
{
	Record* newRecord = new Record;
	newRecord->number = number;
	strcpy(newRecord->name, newName);
	return newRecord;
}

int numberOfRecordsInBook(PhoneBook* phoneBook)
{
	return phoneBook->numberOfRecords;
}

Record* headOfPhoneBook(PhoneBook* phoneBook)
{
	return phoneBook->head;
}

int numberInRecord(Record* record)
{
	return record->number;
}

char* nameInRecord(Record* record)
{
	return record->name;
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