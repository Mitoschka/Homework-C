#include <stdio.h>

struct Date{
	int day;
	int month;
	int year;
};

int readFile(char name[], struct Date *arrayDate)
{//чтение файла построчно
	int day = 0;
	int month = 0;
	int year = 0;
	int inxOfArray = 0;
	
	FILE *file = fopen(name, "r");
	if (!file)
	{
		return 0;
	}
	while (!feof(file))//file = fopen(name, "r")) != NULL
	{
		fscanf(file, "%d.%d.%d", &day, &month, &year);
		arrayDate[inxOfArray].day = day;
		arrayDate[inxOfArray].month = month;
		arrayDate[inxOfArray].year = year;
		printf("%d.%d.%d\n", arrayDate[inxOfArray].day, arrayDate[inxOfArray].month, arrayDate[inxOfArray].year);
		inxOfArray++;
	}
	fclose(file);
	return inxOfArray;
}

int getMaxDate(struct Date *arrayDate, int inxOfArray)
{//поиск максимальной даты
	int inxOfMaxDate = 0;
	int maxDay = arrayDate[0].day;
	int maxMonth = arrayDate[0].month;
	int maxYear = arrayDate[0].year;
	int tempValue = 0;
	
	for (int i = 1; i < inxOfArray; i++)
	{
		//сравниваем даты
		if (maxYear > arrayDate[i].year)
		{
			tempValue = 1;
		}
		else if (maxYear < arrayDate[i].year)
		{
			tempValue = 2;
		}
		else if (maxMonth > arrayDate[i].month)
		{
			tempValue = 1;
		}
		else if (maxMonth < arrayDate[i].month)
		{
			tempValue = 2;
		}
		else if (maxDay > arrayDate[i].day)
		{
			tempValue = 1;
		}
		else if (maxDay < arrayDate[i].day)
		{
			tempValue = 2;
		}
		else
		{// даты совпадают
			tempValue = 0;
		}
		
		if (tempValue == 1)
		{//максимальная дата
			maxDay = arrayDate[i].day;
			maxMonth = arrayDate[i].month;
			maxYear = arrayDate[i].year;
			inxOfMaxDate = i;
		}				
	}
	return inxOfMaxDate;
}


int test()
{
	const int countLines = 2;
	struct Date* arrayDate = (struct Date*)malloc(countLines* sizeof(struct Date));
	arrayDate[0].day = 1;
	arrayDate[0].month = 2;
	arrayDate[0].year =	2000;

	arrayDate[1].day = 1;
	arrayDate[1].month = 2;
	arrayDate[1].year = 1999;

	int inxOfMaxDate = getMaxDate(arrayDate, countLines);
	if (inxOfMaxDate == 1)
	{
		free(arrayDate);
		return 1;
	}
	else
	{
		free(arrayDate);
		return 0;
	}
}

int main()
{
	if (!test())
	{
		printf("\nerror!\n");
		return 0;
	}
	const int countLines = 100;
	struct Date* arrayDate = (struct Date*)malloc(countLines* sizeof(struct Date));
	
	int inxOfArray = readFile("date.txt", arrayDate);
	int inxOfMaxDate = getMaxDate(arrayDate, inxOfArray);
	
	printf("Max date: %d.%d.%d", arrayDate[inxOfMaxDate].day, arrayDate[inxOfMaxDate].month, arrayDate[inxOfMaxDate].year);

	free(arrayDate);
	return 0;
}
