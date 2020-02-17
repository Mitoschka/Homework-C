#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BinaryTree.h"


char *strToLower(char *value)
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
	printf("1. Ввод значения\n");
	printf("2. Номер телефона по фамилии\n");
	printf("3. Проверка наличия заданного ключа\n");
	printf("4. Удаление записи\n");
	printf("5. Выход\n");
	printf("Input number: ");

	char *choose = (char*)malloc(100 *sizeof(char));//выделение памяти для ключа;
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
	Node *tree = NULL;
	char *key = "a";
	tree = addNode(tree, key, "value1");
	if (!tree)
	{
		return 0;
	}
	//проверка на удаление
	tree = removeByKey(tree, key);
	if (tree)
	{
		free(tree);
		return 0;
	}

	//проверка на перевод символов в нижний регистр
	char *value = (char*)malloc(100 *sizeof(char));//выделение памяти для значения
	strcpy(value, "ЯГА");
	if (strcmp(strToLower(value), "яга") != 0)
	{
		free(value);
		return 0;
	}
	free(value);
	if (tree != NULL) free(tree);
	return 1;
}

int main()
{
	setlocale(LC_ALL, "RU");

	if (!test())
	{
		printf("Тест не пройден...\n");
	}
	
	Node *found = NULL;
	Node *searchKey = NULL;
	Node *tree = NULL;//память под узел
	char *key = (char *)malloc(100*sizeof(char));//выделение памяти для ключа
	char *value = (char *)malloc(100*sizeof(char));//выделение памяти для значения


	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				printf("ДОБАВЛЕНИЕ НОВОЙ ИНФОРМАЦИИ\n");
				printf("Введите фамилию: ");
				scanf("%s", key);
				key = strToLower(key);
				printf("Введите номер телефона: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("Запись внесена!\n");
				break;
			}

			case 2:
			{
				printf("ВЫВОД ИНФОРМАЦИИ ПО КЛЮЧУ\n");
				printf("Введите фамилию: ");
				scanf("%s", key);
				key = strToLower(key);
				found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%s %s\n", found->key, found->item);
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
				printf("Введите фамилию для проверки ключа: ");
				scanf("%s", key);
				key = strToLower(key);
				searchKey = searchByKey(tree, key);
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
				printf("Введите фамилию для удаления: ");
				scanf("%s", key);
				key = strToLower(key);
				tree = removeByKey(tree, key);
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
	free(searchKey);
	free(value);
	free(key);
	
	return 0;
}