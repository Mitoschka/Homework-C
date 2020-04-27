#pragma once

struct MyHashTable;

// Создание хэш-таблицы.
MyHashTable* createHashTable();

// Вернуть количество ячеек в хэш-таблице.
int capacityOfHashTable(MyHashTable* hashTable);

// Добавить элемент в хэш-таблицу.
void addElementToHashTable(MyHashTable* hashTable, char value[]);

// Проверка принадлежности слова хэш-таблице.
bool isContainInHashTable(MyHashTable* hashTable, char value[]);

// Количество вхождений слова.
int numberOfEntries(MyHashTable* hashTable, char value[]);

// Распечатать хэш-таблицу.
void printHashTable(MyHashTable* hashTable);

// Вернуть коэффициент заполнения.
float loadFactor(MyHashTable* hashTable);

// Получить максимальную длину списка в сегменте.
int maxLengthOfListInSegment(MyHashTable* hashTable);

// Получить среднюю длину списка.
float averageLengthOfLists(MyHashTable* hashTable);

// Удаление хэш-таблицы.
void deleteHashTable(MyHashTable* hashTable);