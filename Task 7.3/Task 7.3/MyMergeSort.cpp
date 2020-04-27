#include "MyMergeSort.h"
#include "PhoneBook.h"

#include <string.h>

PhoneBook* reverseBook(PhoneBook* phoneBook)
{
	PhoneBook* tempBook = createPhoneBook();
	while (headOfPhoneBook(phoneBook) != nullptr)
	{
		addRecordInPhoneBook(tempBook, removeRecordFromBook(phoneBook));
	}
	deleteBook(phoneBook);
	return tempBook;
}

bool compareRecords(PhoneBook* firstBook, PhoneBook* secondBook, bool& isNumberSort)
{
	if (isNumberSort != 0)
	{
		return (numberInRecord(headOfPhoneBook(firstBook)) > numberInRecord(headOfPhoneBook(secondBook)));
	}

	return (strcmp(nameInRecord(headOfPhoneBook(firstBook)), nameInRecord(headOfPhoneBook(secondBook))) > 0);
}

// Слияние двух списков в один.
PhoneBook* merge(PhoneBook* phoneBook, PhoneBook* tempBook, bool& isNumberSort)
{
	PhoneBook* resultBook = createPhoneBook();
	int sizeOfResultBook = numberOfRecordsInBook(phoneBook) + numberOfRecordsInBook(tempBook);

	phoneBook = reverseBook(phoneBook);
	tempBook = reverseBook(tempBook);

	for (int i = 0; i != sizeOfResultBook; ++i)
	{
		if (numberOfRecordsInBook(phoneBook) != 0 && numberOfRecordsInBook(tempBook) != 0)
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
		else if (numberOfRecordsInBook(phoneBook) != 0)
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
	if (numberOfRecordsInBook(phoneBook) != 1)
	{
		PhoneBook* tempBook = createPhoneBook();
		int middle = numberOfRecordsInBook(phoneBook) / 2;
		while (numberOfRecordsInBook(phoneBook) > middle)
		{
			addRecordInPhoneBook(tempBook, removeRecordFromBook(phoneBook));
		}

		phoneBook = merge(mergeSort(phoneBook, isNumberSort), mergeSort(tempBook, isNumberSort), isNumberSort);

	}

	return phoneBook;
}