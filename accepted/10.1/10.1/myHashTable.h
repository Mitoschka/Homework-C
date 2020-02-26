#pragma once

struct HashTable;

// Создание хэш-таблицы.
HashTable * createHashTable();

// Вернуть количество ячеек в хэш-таблице.
int capacityOfHashTable(HashTable * hashTable);

// Добавить элемент в хэш-таблицу.
void addHashElement(HashTable * hashTable, char value[]);

// Распечатать хэш-таблицу.
void printHashTable(HashTable * hashTable);

// Вернуть коэффициент заполнения.
float loadFactor(HashTable * hashTable);

// Получить максимальную длину списка в сегменте.
int maxLengthOfListInSegment(HashTable * hashTable);

// Получить среднюю длину списка.
float averageLengthOfLists(HashTable * hashTable);

// Удаление хэш-таблицы.
void deleteHashTable(HashTable * hashTable);