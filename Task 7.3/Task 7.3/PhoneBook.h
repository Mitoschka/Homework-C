#pragma once

const int maxSize = 20;

struct Record;

struct PhoneBook;

// Создать телефонную книгу.
PhoneBook* createPhoneBook();

// Создать запись.
Record* createRecord(int number, char newName[]);

// Вернуть количество записей в книге.
int numberOfRecordsInBook(PhoneBook* phoneBook);

// Вернуть запись в начале книги.
Record* headOfPhoneBook(PhoneBook* phoneBook);

// Вернуть номер телефона в записи.
int numberInRecord(Record* record);

// Вернуть имя в записи.
char* nameInRecord(Record* record);

// Удалить книгу.
void deleteBook(PhoneBook* phoneBook);

// Извлечь запись из книги.
Record* removeRecordFromBook(PhoneBook* phoneBook);

// Прочитаны ли данные из файла.
bool isRecordsRead(PhoneBook* phoneBook);

// Добавить запись в книгу.
void addRecordInPhoneBook(PhoneBook* phoneBook, Record* recordInBook);

// Вывести книгу на консоль.
void showBook(PhoneBook* phoneBook);

// Поместить записи в массив.
void putRecordsToArray(PhoneBook* phoneBook, int numbers[]);