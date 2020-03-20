#pragma once

const int maxSize = 20;

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

// Создать телефонную книгу.
PhoneBook* createPhoneBook();

// Удалить книгу.
void deleteBook(PhoneBook* phoneBook);

// Прочитаны ли данные из файла.
bool isRecordsRead(PhoneBook* phoneBook);

// Добавить запись в книгу.
void addRecordInPhoneBook(PhoneBook* phoneBook, Record* recordInBook);

// Сортировка слиянием.
PhoneBook* mergeSort(PhoneBook* phoneBook, bool& isNumberSort);

// Вывести книгу на консоль.
void showBook(PhoneBook* phoneBook);

// Поместить записи в массив.
void putRecordsToArray(PhoneBook* phoneBook, int numbers[]);
void putRecordsToArray(PhoneBook* phoneBook, int numbers[]);