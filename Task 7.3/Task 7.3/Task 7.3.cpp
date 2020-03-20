#include "PhoneBook.h"
#include <iostream>

bool isCorrect()
{
	PhoneBook* phoneBook = createPhoneBook();
	Record* record1 = new Record;
	char name1[] = "aaa";
	int number1 = 222;
	strcpy(record1->name, name1);
	record1->number = number1;

	Record* record2 = new Record;
	char name2[] = "cccc";
	int number2 = 3333;
	strcpy(record2->name, name2);
	record2->number = number2;

	Record* record3 = new Record;
	char name3[] = "ddd";
	int number3 = 555;
	strcpy(record3->name, name3);
	record3->number = number3;

	Record* record4 = new Record;
	char name4[] = "bbb";
	int number4 = 4444;
	strcpy(record4->name, name4);
	record4->number = number4;

	Record* record5 = new Record;
	char name5[] = "eeee";
	int number5 = 1;
	strcpy(record5->name, name5);
	record5->number = number5;

	addRecordInPhoneBook(phoneBook, record1);
	addRecordInPhoneBook(phoneBook, record2);
	addRecordInPhoneBook(phoneBook, record3);
	addRecordInPhoneBook(phoneBook, record4);
	addRecordInPhoneBook(phoneBook, record5);

	bool isSortByNumber = true;
	phoneBook = mergeSort(phoneBook, isSortByNumber);

	int testArray[5]{};
	int correctArray[] = { number5, number1, number3, number2, number4 };
	putRecordsToArray(phoneBook, testArray);

	for (int i = 0; i != 5; ++i)
	{
		if (testArray[i] != correctArray[i])
		{
			deleteBook(phoneBook);
			return false;
		}
	}

	deleteBook(phoneBook);
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("Тест не пройден.");
		return 0;
	}

	PhoneBook* phoneBook = createPhoneBook();

	if (isRecordsRead(phoneBook))
	{
		printf("Каким образом отсортировать книгу? (0 - по именам, 1 - по номерам)\n");
		int option = 0;
		scanf("%d", &option);
		bool isSortByNumber = option;
		phoneBook = mergeSort(phoneBook, isSortByNumber);
		showBook(phoneBook);
	}

	deleteBook(phoneBook);

	return 0;
}