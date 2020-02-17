#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BinaryTree.h"

int isDigit(char* s)
{ //является ли данная строка целым числом
	int i = 0;
	int len = strlen(s);
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return 0;
		}
		i++;
	}
	return 1;
}

char* strToLower(char* value)
{//преобразование строки в нижний регистр
	const len = strlen(value);
	for (int i = 0; i < len; i++)
	{
		if (value[i] >= 'A' && value[i] <= 'Z')
		{
			value[i] += 'z' - 'Z';
		}

		if (value[i] >= 'А' && value[i] <= 'Я')
		{
			value[i] += 'я' - 'Я';
		}
	}
	return value;
}

int menu()
{//реализация меню программы
	printf("[MENU]\n");
	printf("1. Ввод значения по ключу\n");
	printf("2. Получение значения по ключу\n");
	printf("3. Проверка наличия заданного ключа\n");
	printf("4. Удаление записи\n");
	printf("5. Выход\n");
	printf("Выбор пункта: ");

	char* choose = (char*)malloc(100 * sizeof(char));//выделение памяти для ключа;
	scanf("%s", choose);
	//возврат выбранного пункта меню
	if (choose < '0' && choose >'9')
	{
		free(choose);//освобождение памяти
		return 0;
	}
	else
	{
		int nChouse = atoi(choose);
		free(choose);//освобождение памяти
		return nChouse;
	}
}

int test()
{
	//тестирование функций
	//проверка на добавление
	Node* tree = NULL;
	int key = 5;
	tree = addNode(tree, key, "value1");
	if (!tree)
	{
		return 0;
	}
	//проверка на удаление
	tree = removeByKey(tree, key);
	if (tree)
	{
		return 0;
	}
	//проверка на перевод символов в нижний регистр
	char* value = (char*)malloc(100 * sizeof(char));//выделение памяти для значения
	strcpy(value, "ЯГА");
	if (strcmp(strToLower(value), "яга") != 0)
	{
		return 0;
	}

	return 1;
}

int main()
{
	setlocale(LC_ALL, "RU");

	if (!test())
	{
		printf("Тест не пройден...\n");
		return 0;
	}

	Node* tree = NULL;//память под узел
	int key = 0;//значение
	char* sKey = (char*)malloc(100 * sizeof(char));//значение ключа
	char* value = (char*)malloc(100 * sizeof(char));//выделение памяти для значения

	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				printf("ДОБАВЛЕНИЕ НОВОЙ ИНФОРМАЦИИ\n");
				printf("Введите значение ключа: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("Неверный ввод значения!\n");
					break;
				}
				//первод значения ключа в число
				key = atoi(sKey);
				printf("Введите запись: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("Запись внесена!\n");
				break;
			}

			case 2:
			{
				printf("ВЫВОД ИНФОРМАЦИИ ПО КЛЮЧУ\n");
				printf("Ввод ключа: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("Неверный ввод значения!\n");
					break;
				}
				//первод значения ключа в число
				key = atoi(sKey);
				Node* found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%d %s\n", found->key, found->item);
				}
				else
				{
					printf("Запись не найдена!\n");
				}
				break;
			}

			case 3:
			{
				printf("ПРОВЕРКА КЛЮЧА\n");
				printf("Введите ключ для его проверки: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("Неверный ввод значения!\n");
					break;
				}
				//первод значения ключа в число
				key = atoi(sKey);
				Node* searchKey = searchByKey(tree, key);
				if (searchKey)
				{
					printf("Данный ключ существует\n");
				}
				else
				{
					printf("Такого ключа нет!\n");
				}
				break;
			}

			case 4:
			{
				printf("УДАЛЕНИЕ ДАННЫХ\n");
				printf("Введите значение ключа для удаления записи: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("Неверный ввод значения!\n");
					break;
				}
				//первод значения ключа в число
				key = atoi(sKey);

				tree = removeByKey(tree, key);
				printf("Для продолждения нажмите любую клавишу..\n");
				break;
			}

			case 5:
			{
				loop = 0;
				break;
			}

			default:
			{
				printf("Неверный выбор...\n");
				break;
			}
		}
	}

	freeTree(tree);
	free(value);
	free(sKey);

	return 0;
}
