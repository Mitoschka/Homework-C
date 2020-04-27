#include "PhoneBook.h"
#include "MyMergeSort.h"
#include <iostream>

bool isCorrect()
{
	PhoneBook* phoneBook = createPhoneBook();
	char name1[] = "aaa";
	int number1 = 222;
	Record* record1 = createRecord(number1, name1);

	char name2[] = "cccc";
	int number2 = 3333;
	Record* record2 = createRecord(number2, name2);

	char name3[] = "ddd";
	int number3 = 555;
	Record* record3 = createRecord(number3, name3);

	char name4[] = "bbb";
	int number4 = 4444;
	Record* record4 = createRecord(number4, name4);

	char name5[] = "eeee";
	int number5 = 1;
	Record* record5 = createRecord(number5, name5);

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