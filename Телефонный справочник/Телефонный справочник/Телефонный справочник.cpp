#include <stdio.h>
#include <string.h>
#include "locale.h"
#include <stdlib.h>

int const size = 100;

struct person
{
	char num[100];
	char name[100];
};

person people[100];

void exit(FILE* file_ptr)
{
	fclose(file_ptr);
}

void addNum(char* num)
{
	printf("Введите номер контакта: ");
	scanf("%s", num);
}

void addName(char* name)
{
	printf("Введите имя контакта: ");
	scanf("%s", name);
}

int addPerson(int personNum)
{
	char name[100], num[100];
	addName(name);
	addNum(num);
	person personVal;
	strcpy(personVal.name, name);
	strcpy(personVal.num, num);
	people[personNum] = personVal;
	printf("\nКонтакт успешно добавлен\n");
	return personNum + 1;
}

void saveNote(int peopleSchetchic)
{
	FILE* file_ptr;
	if ((file_ptr = fopen("file_ptr.txt", "w")) == NULL)
	{
		printf("error\n");
	}
	else
	{
		for (int i = 0; i < peopleSchetchic; i++)
		{
			fprintf(file_ptr, "%s\t%s\n", people[i].name, people[i].num);
		}
	}
	fclose(file_ptr);
	printf("\n\nСохранение прошло успешно \n");
}

void Print(FILE* file_ptr)
{
	char s[100];
	int k = 0;
	if ((file_ptr = fopen("file_ptr.txt", "r")) == NULL)
	{
		printf("error\n");
	}
	else
		while (fgets(s, 100, file_ptr))
		{
			printf("%s", s);
			k++;
		}
	printf("Количество строк: %d\n", k);
	fclose(file_ptr);
	printf("Все данные были распечатаны\n");
}

void numSearch(char personName)
{
	char nameFinder[100];
	printf("Введите номер контакта: ");
	scanf("%s", nameFinder);
	int strSizeFinder = strlen(nameFinder);
	for (int i = 0; i < personName; i++)
	{
		bool equal = true;
		person personVal = people[i];
		int sizePersonNum = strlen(personVal.num);
		if (sizePersonNum != strSizeFinder)
		{
			continue;
		}
		for (int j = 0; j < strSizeFinder; j++)
		{
			if (nameFinder[j] != personVal.num[j])
			{
				equal = false;
			}
		}
		if (equal)
		{
			printf("%s\t%s\n", personVal.name, personVal.num);
			return;
		}
	}
	printf("Увы, такого контакта здесь нет\n");
}

int min(int x, int y)
{
	return x > y ? y : x;
}

void nameSearch(int personNum)
{
	char numFinder[100];
	printf("Введите имя контакта: ");
	scanf("%s", numFinder);
	int strSizeFinder = strlen(numFinder);
	for (int i = 0; i < personNum; i++)
	{
		bool equal = true;
		person personVal = people[i];
		int sizePersonName = strlen(personVal.name);
		if (sizePersonName != strSizeFinder)
		{
			continue;
		}
		for (int j = 0; j < strSizeFinder; j++)
		{
			if (numFinder[j] != personVal.name[j])
			{
				equal = false;
			}
		}
		if (equal)
		{
			printf("%s\t%s\n", personVal.name, personVal.num);
			return;
		}
	}
	printf("Увы, такого контакта здесь нет\n");
}

int load()
{
	int personSchetchic = 0;
	FILE* file_ptr;
	int i = 0;
	if ((file_ptr = fopen("file_ptr.txt", "r")) == NULL)
	{
		file_ptr = fopen("file_ptr.txt", "w");
		fclose(file_ptr);
		file_ptr = fopen("file_ptr.txt", "r");
	}
	char name[100];
	char num[100];
	while (fscanf(file_ptr, "%s", name) != EOF)
	{
		person personVal;
		fscanf(file_ptr, "%s", num);
		strcpy(personVal.name, name);
		strcpy(personVal.num, num);
		people[personSchetchic] = personVal;
		personSchetchic++;
	}
	return personSchetchic;
}

int main()
{
	FILE* file_ptr;
	file_ptr = fopen("file_ptr.txt", "r+t");
	setlocale(LC_ALL, "Russian");
	printf("Это телефонный справочник\n");
	int schetchic = load();
	char act = '0';
	while (true)
	{
		if (act != '\n')
		{
			printf("\nВызов инструкции осуществляется по номеру 6\nВведите номер команды: ");
		}
		scanf("%c", &act);
		switch (act)
		{
		case '0': {exit(file_ptr); return 0;}
		case '1': {schetchic = addPerson(schetchic);break;}
		case '2': {Print(file_ptr);break;}
		case '3': {numSearch(schetchic);break;}
		case '4': {nameSearch(schetchic);break;}
		case '5': {saveNote(schetchic);break;}
		case '6': {printf(" 0 - выйти\n 1 - добавить запись (имя и телефон)\n 2 - распечатать все имеющиеся записи\n 3 - найти телефон по имени\n 4 - найти имя по телефону \n 5 - сохранить текущие данные в файл \n");break;}
		case '\n': {break;}
		default: {printf("Я не знаю такой команды, вызовите инструкцию\n");}
		}
	}
	fclose(file_ptr);
	return 0;
}
